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
                           "Contact Principal", "Email", "Date Début", "Date Fin", "Expiring Soon"};
    model->setHorizontalHeaderLabels(headers);

    QDate currentDate = QDate::currentDate();
    QDate dateLimite = currentDate.addDays(7);

    int row = 0;
    while (query.next()) {
        QList<QStandardItem *> rowItems;
        for (int col = 0; col < 9; ++col) {
            rowItems << new QStandardItem(query.value(col).toString());
        }

        // Vérifier si la date de fin est dans les 7 jours
        QDate dateFin = query.value(8).toDate();
        int isExpiring = (dateFin >= currentDate && dateFin <= dateLimite) ? 1 : 0;

        rowItems << new QStandardItem(QString::number(isExpiring));

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

    query.prepare("UPDATE PARTENAIRES SET NOM = :Nom, TYPEPARTENAIRE = :TypePartenaire, ADRESSE = :Adresse, VILLE = :Ville, CONTACTPRINCIPAL = :ContactPrincipal, EMAIL = :Email WHERE ID = :Id");

    query.bindValue(":Id", id);
    query.bindValue(":Nom", Nom);
    query.bindValue(":TypePartenaire", TypePartenaire);
    query.bindValue(":Adresse", Adresse);
    query.bindValue(":Ville", Ville);
    query.bindValue(":ContactPrincipal", ContactPrincipal);
    query.bindValue(":Email", Email);

    if (!query.exec()) {
        qDebug() << "❌ Erreur lors de la modification : " << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Partenaire mis à jour avec succès !";
    return true;
}
bool Partenaire::recupererParId(int id) {
    QSqlQuery query;
    query.prepare("SELECT NOM, TYPEPARTENAIRE, ADRESSE, VILLE, CONTACTPRINCIPAL, EMAIL FROM PARTENAIRES WHERE ID = :Id");
    query.bindValue(":Id", id);

    if (!query.exec() || !query.next()) {
        qDebug() << "❌ Aucun partenaire trouvé avec l'ID : " << id;
        return false;
    }

    Nom = query.value(0).toString();
    TypePartenaire = query.value(1).toString();
    Adresse = query.value(2).toString();
    Ville = query.value(3).toString();
    ContactPrincipal = query.value(4).toString();
    Email = query.value(5).toString();

    qDebug() << "✅ Partenaire trouvé : " << Nom << ", " << TypePartenaire;
    return true;
}

int Partenaire::nombreContratsEnCours()
{
    QSqlQuery query;

    // Utilisation d'une requête SQL pour compter les contrats en cours
    query.prepare("SELECT COUNT(*) FROM PARTENAIRES WHERE :currentDate BETWEEN DATEDEBUT AND DATEFIN");

    // Assurez-vous que vous passez une date correcte au format SQL
    query.bindValue(":currentDate", QDate::currentDate());

    if (query.exec()) {
        if (query.next()) {
            return query.value(0).toInt();  // Retourne le nombre de contrats en cours
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError();
    }

    return 0;  // Retourne 0 en cas d'erreur ou si aucun contrat en cours n'est trouvé
}

