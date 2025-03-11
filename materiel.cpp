#include "materiel.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDate>
// 🔹 Constructeur par défaut
Materiel::Materiel() {
    id = 0;
    cout = 0.0;
    nom = "";
    quantite = 0;
    etat = "";
    dateachat = QDate::currentDate(); // Initialise avec la date du jour
    garantie = "";
}

// 🔹 Constructeur paramétré
Materiel::Materiel(int id, double cout, QString nom, int quantite, QString etat, QDate dateachat, QString garantie) {
    this->id = id;
    this->cout = cout;
    this->nom = nom;
    this->quantite = quantite;
    this->etat = etat;
    this->dateachat = dateachat;
    this->garantie = garantie;
}

bool Materiel::ajouter() {
    QSqlQuery query;

    // 📅 Date actuelle au format "DD-MM-YYYY"
    dateachat = QDate::currentDate();
    QString dateachatStr = dateachat.toString("dd-MM-yyyy");

    qDebug() << "📅 Date achat insérée : " << dateachatStr; // 🔍 Debug

    // 🔹 Requête SQL avec TO_DATE() pour Oracle
    query.prepare("INSERT INTO materiel (id, cout, nom, quantite, etat, dateachat, garantie) "
                  "VALUES (:id, :cout, :nom, :quantite, :etat, TO_DATE(:dateachat, 'YYYY-MM-DD'), :garantie)");

    query.bindValue(":id", id);
    query.bindValue(":cout", cout);
    query.bindValue(":nom", nom);
    query.bindValue(":quantite", quantite);
    query.bindValue(":etat", etat);
    query.bindValue(":dateachat", dateachatStr);
    query.bindValue(":garantie", garantie);

    if (query.exec()) {
        qDebug() << "✅ Matériel ajouté avec succès !";
        return true;
    } else {
        qDebug() << "❌ Erreur SQL :" << query.lastError().text();
        return false;
    }
}


// 🔹 Afficher la liste des matériels
QSqlQueryModel* Materiel::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM materiel");
   //  model->setQuery("SELECT id, nom, cout, quantité, etat, dateachat, garantie FROM materiel");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Coût"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("État"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Dateachat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Garantie"));
    model->insertColumn(model->columnCount());
    model->insertColumn(model->columnCount());
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Update"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Delete"));
    return model;
}

// 🔹 Supprimer un matériel
bool Materiel::supprimer(int id) {
    if (id <= 0) {
        qDebug() << "⚠️ ID invalide ! L'ID doit être un entier positif.";
        return false;
    }
    for (tableViewMateriel *item : selectedItems) {
        int row = item->row();
        QString id = ui->tw->item(row, 0)->text();

    QSqlQuery query;
    query.prepare("DELETE FROM materiel WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "✅ Matériel avec ID" << id << "supprimé avec succès !";
        return true;
    } else {
        qDebug() << "❌ Échec de la suppression du matériel avec ID" << id << ":" << query.lastError().text();
        return false;
    }
}

// 🔹 Modifier un matériel
bool Materiel::modifier(int id,
                        double cout,
                        QString nom,
                        int quantite,
                        QString etat,
                        QDate dateachat,
                        QString garantie ) {
    if (id <= 0) {
        qDebug() << "⚠️ ID invalide ! L'ID doit être un entier positif.";
        return false;
    }

    QSqlQuery query;
    QString dateachatStr = dateachat.toString("yyyy-MM-dd"); // Format Oracle

    query.prepare("UPDATE materiel SET cout = :cout, nom = :nom, quantite = :quantite, "
                  "etat = :etat, dateachat = TO_DATE(:dateachat, 'YYYY-MM-DD'), garantie = :garantie "
                  "WHERE id = :id");

    query.bindValue(":cout", cout);
    query.bindValue(":nom", nom);
    query.bindValue(":quantite", quantite);
    query.bindValue(":etat", etat);
    query.bindValue(":dateachat", dateachatStr);
    query.bindValue(":garantie", garantie);
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "✅ Matériel avec ID" << id << "modifié avec succès !";
        return true;
    } else {
        qDebug() << "❌ Erreur SQL :" << query.lastError().text();
        return false;
    }
}
