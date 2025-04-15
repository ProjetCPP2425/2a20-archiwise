#include "client.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>
#include <QJsonObject>


Client::Client() {
    id = 0;
    type = ClientType::Particulier;

}



Client::Client(QString nom, QString prenom, QString adresse, QString tel, ClientType type, QDate dateInscription) {
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->tel = tel;
    this->type = type;
    this->dateInscription = dateInscription;
}

QString Client::get_typeString() const {
    switch(type) {
    case ClientType::Particulier: return "Particulier";
    case ClientType::Entreprise: return "Entreprise";
    case ClientType::Premium: return "Premium";
    default: return "Inconnu";
    }
}

void Client::set_type(const QString &typeStr) {
    if (typeStr.compare("Particulier", Qt::CaseInsensitive) == 0) {
        type = ClientType::Particulier;
    } else if (typeStr.compare("Entreprise", Qt::CaseInsensitive) == 0) {
        type = ClientType::Entreprise;
    } else if (typeStr.compare("Premium", Qt::CaseInsensitive) == 0) {
        type = ClientType::Premium;
    } else {
        type = ClientType::Particulier;
    }
}

bool Client::ajouter() {
    QSqlQuery query;
    query.prepare("SELECT NVL(MAX(ID), 0) + 1 FROM CLIENTS");
    if (!query.exec() || !query.next()) {
        return false;
    }

    int newId = query.value(0).toInt();

    query.prepare("INSERT INTO CLIENTS (id, NOM, PRENOM, ADRESSE, TEL, TYPE, DATEINSCRIPTION) "
                  "VALUES (:id, :nom, :prenom, :adresse, :tel, :type, :dateInscription)");

    query.bindValue(":id", newId);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tel", tel);
    query.bindValue(":type", get_typeString());
    query.bindValue(":dateInscription", dateInscription);

    if (!query.exec()) {
        return false;
    }

    // Enregistrer l'action dans l'historique si la modification a réussi
    QString details = QString("ajout du client: %1 %2 (ID: %3)").arg(nom, prenom).arg(id);
    return logAction("ajout", newId, details);}

QSqlQueryModel* Client::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID, nom, prenom, adresse, tel, type, DateInscription FROM CLIENTS");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("DateInscription"));

    return model;
}
bool Client::supprimer(int id) {
    QSqlQuery query;
    QString nomClient, prenomClient;

    // 1. Récupérer les infos du client AVANT suppression
    query.prepare("SELECT NOM, PRENOM FROM CLIENTS WHERE ID = :id");
    query.bindValue(":id", id);
    if (!query.exec() || !query.next()) {
        qDebug() << "Client introuvable :" << query.lastError().text();
        return false;
    }
    nomClient = query.value("NOM").toString();
    prenomClient = query.value("PRENOM").toString();

    // 2. Journaliser AVANT suppression
    QString details = QString("Suppression de %1 %2 (ID: %3)").arg(nomClient, prenomClient).arg(id);
    if (!logAction("Suppression", id, details)) {
        qDebug() << "Échec de la journalisation";
        return false; // Annuler la suppression si le log échoue
    }

    // 3. Supprimer le client
    query.prepare("DELETE FROM CLIENTS WHERE ID = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Erreur SQL :" << query.lastError().text();
        return false;
    }

    // 4. Vérifier si la suppression a eu lieu
    if (query.numRowsAffected() <= 0) {
        qDebug() << "Aucun client supprimé (ID invalide?)";
        return false;

    }
    if (query.exec() && query.numRowsAffected() > 0) {

        return logAction("SUPPRESSION", id, "Client supprimé");
    }


    return true;
}
bool Client::modifier(int id) {
    QSqlQuery query;
    int newId = query.value(0).toInt();
    query.prepare("UPDATE CLIENTS SET "
                  "NOM = :nom, "
                  "PRENOM = :prenom, "
                  "ADRESSE = :adresse, "
                  "TEL = :tel, "
                  "TYPE = :type, "
                  "DATEINSCRIPTION = :dateInscription "
                  "WHERE ID = :id");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tel", tel);
    query.bindValue(":type", get_typeString());
    query.bindValue(":dateInscription", dateInscription);
    query.bindValue(":id", id);
    if (!query.exec()) {
        return false;
    }

    // Enregistrer l'action dans l'historique si la modification a réussi
    QString details = QString("Modification du client: %1 %2 (ID: %3)").arg(nom, prenom).arg(id);
    return logAction("Modification", id, details);
}

Client Client::getclientById(int id) {
    QSqlQuery query;
    Client client;
    client.set_id(-1);

    query.prepare("SELECT ID, NOM, PRENOM, ADRESSE, TEL, TYPE, DATEINSCRIPTION FROM CLIENTS WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        client.set_id(query.value("ID").toInt());
        client.set_nom(query.value("NOM").toString());
        client.set_prenom(query.value("PRENOM").toString());
        client.set_adresse(query.value("ADRESSE").toString());
        client.set_tel(query.value("TEL").toString());
        client.set_type(query.value("TYPE").toString());
        client.set_dateInscription(query.value("DATEINSCRIPTION").toDate());
    }

    return client;
}

QSqlQueryModel* Client::rechercher(const QString &critere) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID, nom, prenom, adresse, tel, type, DateInscription FROM CLIENTS "
                  "WHERE (nom LIKE :critere OR prenom LIKE :critere OR tel LIKE :critere) "
                  "ORDER BY nom");
    query.bindValue(":critere", "%" + critere + "%");

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, "ID");
        model->setHeaderData(1, Qt::Horizontal, "Nom");
        model->setHeaderData(2, Qt::Horizontal, "Prenom");
        model->setHeaderData(3, Qt::Horizontal, "Adresse");
        model->setHeaderData(4, Qt::Horizontal, "Tel");
        model->setHeaderData(5, Qt::Horizontal, "Type");
        model->setHeaderData(6, Qt::Horizontal, "DateInscription");
    }

    return model;
}

QSqlQueryModel* Client::afficherHistorique() {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT "
                  "ID, "
                  "id_c, "
                  "date_action, "
                  "ACTION, "
                  "DETAILS "
                  "FROM HISTORIQUE_clients "
                  "ORDER BY DATE_ACTION DESC");

    if (!query.exec()) {
        qDebug() << "Erreur requête historique:" << query.lastError().text();
        return model;
    }

    // Utilisation de la méthode non dépréciée
    model->setQuery(std::move(query));

    // Définir les en-têtes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Action"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Details"));

    return model;
}
bool Client::logAction(const QString &action, int clientId, const QString &details) {
    QSqlQuery query;
    // Corriger la table ici : remplacer CLIENTS par HISTORIQUE_clients
    query.prepare("SELECT NVL(MAX(ID), 0) + 1 FROM HISTORIQUE_clients");
    if (!query.exec() || !query.next()) {
        return false;
    }
    int newId = query.value(0).toInt();

    query.prepare("INSERT INTO HISTORIQUE_clients (id, ID_C, ACTION, DATE_ACTION, DETAILS) "
                  "VALUES (:id, :clientId, :action, :dateAction, :details)");

    // Liaison des valeurs
    query.bindValue(":id", newId);

    query.bindValue(":clientId", clientId);
    query.bindValue(":action", action);
    query.bindValue(":dateAction", QDateTime::currentDateTime());
    query.bindValue(":details", details);

    if (!query.exec()) {
        qDebug() << "Erreur lors du log:" << query.lastError().text();
        qDebug() << "Requête:" << query.lastQuery();
        return false;
    }
    return true;
}





