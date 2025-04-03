#include "client.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>

// Constructeur par défaut
Client::Client() {
    id = 0;
    prix = 0.0;
}

// Constructeur paramétré
Client::Client(QString nom, QString prenom, QString adresse, QString tel, double prix, QString type, QDate dateInscription) {
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->tel = tel;
    this->prix = prix;
    this->type = type;
    this->dateInscription = dateInscription;
}

// Ajouter un client
bool Client::ajouter() {

    QSqlQuery query;

    // Get the next available ID from a sequence
    query.prepare("SELECT NVL(MAX(ID), 0) + 1 FROM CLIENTS");
    if (!query.exec() || !query.next()) {
        return false;  // If the query fails, return false
    }

    int newId = query.value(0).toInt();  // Retrieve the new ID

    // Insert the new project with the generated ID

    query.prepare("INSERT INTO CLIENTS (id,NOM, PRENOM, ADRESSE, TEL, PRIX, TYPE, DATEINSCRIPTION) "
                  "VALUES (:id,:nom, :prenom, :adresse, :tel, :prix, :type, :dateInscription)");

    query.bindValue(":id", newId);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tel", tel);
    query.bindValue(":prix", prix);
    query.bindValue(":type", type);
    query.bindValue(":dateInscription", dateInscription);

    if (query.exec()) {
        // Récupérer l'ID auto-généré
        int newId = query.lastInsertId().toInt();
        qDebug() << "Client ajouté avec succès ! ID : " << newId;
        return true;
    } else {
        qDebug() << "Échec de l'ajout du client: " << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* Client::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID, nom, prenom, adresse, tel, prix, type, DateInscription FROM CLIENTS");

    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("DateInscription"));

    // Remove these if causing issues
    model->insertColumn(model->columnCount());
    model->insertColumn(model->columnCount());
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Update"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Delete"));

    return model;
}

// Supprimer un client
bool Client::supprimer(int id) {
    QSqlQuery query;
    QString res = QString::number(id); // Convertir l'ID en QString

    query.prepare("DELETE FROM CLIENTS WHERE ID = :id");
    query.bindValue(":id", res); // Lier la valeur de l'ID

    if (query.exec()) {
        qDebug() << "Client supprimé avec succès !";
        return true;
    } else {
        qDebug() << "Échec de la suppression du client: " << query.lastError().text();
        return false;
    }
}

bool Client::modifier(int id) {
    QSqlQuery query;

    query.prepare("UPDATE CLIENTS SET "
                  "NOM = :nom, "
                  "PRENOM = :prenom, "
                  "ADRESSE = :adresse, "
                  "TEL = :tel, "
                  "PRIX = :prix, "
                  "TYPE = :type, "
                  "DATEINSCRIPTION = :dateInscription "
                  "WHERE ID = :id");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":tel", tel);
    query.bindValue(":prix", prix);
    query.bindValue(":type", type);
    query.bindValue(":dateInscription", dateInscription);
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Client modifié avec succès !";
        return true;
    } else {
        qDebug() << "Échec de la modification du client: " << query.lastError().text();
        return false;
    }
}
Client Client::getclientById(int id) {
    QSqlQuery query;
    Client client;

    query.prepare("SELECT * FROM CLIENTS WHERE id = :id");
    query.bindValue(":id", id);

    // Exécution de la requête
    if (query.exec() && query.next()) {
        client.set_id(query.value(0).toInt());
        client.set_nom(query.value(1).toString());
        client.set_prenom(query.value(2).toString());
        client.set_adresse(query.value(3).toString());
        client.set_tel(query.value(4).toString());
        client.set_prix(query.value(5).toFloat());
        client.set_type(query.value(6).toString());
        client.set_dateInscription(query.value(7).toDate());
    } else {
        qDebug() << "Erreur lors de la récupération du client: " << query.lastError().text();
    }

    return client;
}
QSqlQueryModel* Client::rechercher(const QString &critere) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID, nom, prenom, adresse, tel, prix, type, DateInscription FROM CLIENTS "
                  "WHERE (nom LIKE :critere OR prenom LIKE :critere OR tel LIKE :critere) "
                  "ORDER BY nom");
    query.bindValue(":critere", "%" + critere + "%");

    if (!query.exec()) {
        qDebug() << "Erreur recherche:" << query.lastError();
        return model;
    }

    model->setQuery(query);

    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, "Nom");
    model->setHeaderData(2, Qt::Horizontal, "Prenom");
    model->setHeaderData(3, Qt::Horizontal, "Adresse");
    model->setHeaderData(4, Qt::Horizontal, "Tel");
    model->setHeaderData(5, Qt::Horizontal, "Prix");
    model->setHeaderData(6, Qt::Horizontal, "Type");
    model->setHeaderData(7, Qt::Horizontal, "DateInscription");

    // Ajouter les colonnes pour les boutons
    model->insertColumn(model->columnCount());
    model->insertColumn(model->columnCount());
    model->setHeaderData(8, Qt::Horizontal, "Update");
    model->setHeaderData(9, Qt::Horizontal, "Delete");

    return model;
}
