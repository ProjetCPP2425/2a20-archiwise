#include "partenaire.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>

using namespace std;

// Constructeur par défaut
// Constructeur par défaut
Partenaire::Partenaire()
    : Id(0), Nom(""), TypePartenaire(""), Adresse(""), Ville(""), ContactPrincipal(""), Email(""), DateDebut(QDate::currentDate()), DateFin(QDate::currentDate()) {}

// Constructeur paramétré
Partenaire::Partenaire(QString Nom, QString TypePartenaire, QString Adresse, QString Ville, QString ContactPrincipal, QString Email, QDate DateDebut, QDate DateFin)
    : Id(0), Nom(Nom), TypePartenaire(TypePartenaire), Adresse(Adresse), Ville(Ville), ContactPrincipal(ContactPrincipal), Email(Email), DateDebut(DateDebut), DateFin(DateFin) {}

// Méthode pour afficher les partenaires dans un QTableWidget
QSqlQueryModel* Partenaire::statistiquesParType()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT TYPEPARTENAIRE, COUNT(*) AS NOMBRE FROM PARTENAIRES GROUP BY TYPEPARTENAIRE");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Type de Partenaire"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre"));

    return model;
}

QStandardItemModel* Partenaire::afficher() {
    QStandardItemModel *model = new QStandardItemModel();

    QSqlQuery query("SELECT * FROM PARTENAIRES");

    // Définir les en-têtes
    QStringList headers = {"ID", "Nom", "Type Partenaire", "Adresse", "Ville",
                           "Contact Principal", "Email", "Date Début", "Date Fin", "Expiring Soon", "Actions"};
    model->setHorizontalHeaderLabels(headers);

    QDate currentDate = QDate::currentDate();
    QDate dateLimite = currentDate.addDays(7);

    int row = 0;
    while (query.next()) {
        QList<QStandardItem *> rowItems;

        // Ajouter toutes les colonnes standard
        for (int col = 0; col < 9; ++col) {
            QStandardItem *item = new QStandardItem();

            // Traitement spécial pour les dates
            if (col == 7 || col == 8) { // Colonnes Date Début et Date Fin
                QDate date = query.value(col).toDate();
                item->setText(date.toString("yyyy/MM/dd"));
                item->setData(date, Qt::UserRole); // Stocker la date brute pour le tri
            } else {
                item->setText(query.value(col).toString());
            }

            // Rendre les cellules non éditable
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);

            rowItems << item;
        }

        // Calcul Expiring Soon
        QDate dateFin = query.value(8).toDate();
        int isExpiring = (dateFin >= currentDate && dateFin <= dateLimite) ? 1 : 0;
        QStandardItem *expiringItem = new QStandardItem(QString::number(isExpiring));
        expiringItem->setFlags(expiringItem->flags() & ~Qt::ItemIsEditable);
        rowItems << expiringItem;

        // Colonne Actions (vide - sera gérée par le délégué)
        QStandardItem *actionItem = new QStandardItem();
        actionItem->setFlags(actionItem->flags() & ~Qt::ItemIsEditable);
        rowItems << actionItem;

        model->appendRow(rowItems);
        row++;
    }

    return model;
}

// Méthode pour ajouter un partenaire à la base de données
bool Partenaire::ajouter() {
    QSqlQuery query;

    // Préparer la requête d'insertion en tenant compte de DATEDEBUT et DATEFIN
    query.prepare("INSERT INTO PARTENAIRES (NOM, TYPEPARTENAIRE, ADRESSE, VILLE, CONTACTPRINCIPAL, EMAIL, DATEDEBUT, DATEFIN) "
                  "VALUES (:Nom, :TypePartenaire, :Adresse, :Ville, :ContactPrincipal, :Email, :DateDebut, :DateFin)");

    // Liaison des valeurs aux paramètres
    query.bindValue(":Nom", Nom);
    query.bindValue(":TypePartenaire", TypePartenaire);
    query.bindValue(":Adresse", Adresse);
    query.bindValue(":Ville", Ville);
    query.bindValue(":ContactPrincipal", ContactPrincipal);
    query.bindValue(":Email", Email);
    query.bindValue(":DateDebut", DateDebut);  // Liaison de la date de début
    query.bindValue(":DateFin", DateFin);      // Liaison de la date de fin

    // Log the query and parameters for debugging
    qDebug() << "Exécution de la requête : " << query.lastQuery();
    qDebug() << "Paramètres de la requête : "
             << "\nNom: " << Nom
             << "\nTypePartenaire: " << TypePartenaire
             << "\nAdresse: " << Adresse
             << "\nVille: " << Ville
             << "\nContactPrincipal: " << ContactPrincipal
             << "\nEmail: " << Email
             << "\nDateDebut: " << DateDebut
             << "\nDateFin: " << DateFin;

    if (!query.exec()) {
        qDebug() << "❌ Erreur lors de l'insertion : " << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Partenaire ajouté avec succès !";
    return true;
}

bool Partenaire::supprimer(int id) {
    QSqlQuery query;

    // Préparer la requête de suppression
    query.prepare("DELETE FROM PARTENAIRES WHERE ID = :id");

    // Lier l'ID du partenaire à la requête
    query.bindValue(":id", id);

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "❌ Erreur lors de la suppression : " << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Partenaire supprimé avec succès !";
    return true;
}
bool Partenaire::modifier(int id) {
    QSqlQuery query;

    query.prepare("UPDATE PARTENAIRES SET "
                  "NOM = :Nom, "
                  "TYPEPARTENAIRE = :TypePartenaire, "
                  "ADRESSE = :Adresse, "
                  "VILLE = :Ville, "
                  "CONTACTPRINCIPAL = :ContactPrincipal, "
                  "EMAIL = :Email, "
                  "DATEDEBUT = :DateDebut, "
                  "DATEFIN = :DateFin "
                  "WHERE ID = :Id");

    query.bindValue(":Id", id);
    query.bindValue(":Nom", Nom);
    query.bindValue(":TypePartenaire", TypePartenaire);
    query.bindValue(":Adresse", Adresse);
    query.bindValue(":Ville", Ville);
    query.bindValue(":ContactPrincipal", ContactPrincipal);
    query.bindValue(":Email", Email);

    // Supposons que tes deux dates soient des QDate
    query.bindValue(":DateDebut", DateDebut);
    query.bindValue(":DateFin", DateFin);

    if (!query.exec()) {
        qDebug() << "❌ Erreur lors de la modification : " << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Partenaire mis à jour avec succès !";
    return true;
}
bool Partenaire::recupererParId(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM PARTENAIRES WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        // Remplir les propriétés de l'objet
        this->Id = query.value(0).toInt();
        Nom = query.value(1).toString();
        TypePartenaire = query.value(2).toString();
        Adresse = query.value(3).toString();
        Ville = query.value(4).toString();
        ContactPrincipal = query.value(5).toString();
        Email = query.value(6).toString();
        DateDebut = query.value(7).toDate();
        DateFin = query.value(8).toDate();
        return true;
    }
    return false;
}


int Partenaire::nombreContratsEnCours() const
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM PARTENAIRES WHERE DATEDEBUT <= CURRENT_DATE AND DATEFIN >= CURRENT_DATE");
    if (query.exec() && query.next()) return query.value(0).toInt();
    return 0;
}

int Partenaire::nombreContratsExpires() const
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM PARTENAIRES WHERE DATEFIN < CURRENT_DATE");
    if (query.exec() && query.next()) return query.value(0).toInt();
    return 0;
}

int Partenaire::nombreContratsFuturs() const
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM PARTENAIRES WHERE DATEDEBUT > CURRENT_DATE");
    if (query.exec() && query.next()) return query.value(0).toInt();
    return 0;
}
