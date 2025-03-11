#include "partenaire.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>

using namespace std;

// Constructeur par défaut
Partenaire::Partenaire()
    : Id(0), Nom(""), TypePartenaire(""), Adresse(""), Ville(""), ContactPrincipal(""), Email("") {}

// Constructeur paramétré
Partenaire::Partenaire(QString Nom, QString TypePartenaire, QString Adresse, QString Ville, QString ContactPrincipal, QString Email)
    : Id(0), Nom(Nom), TypePartenaire(TypePartenaire), Adresse(Adresse), Ville(Ville), ContactPrincipal(ContactPrincipal), Email(Email) {}

// Méthode pour afficher les partenaires dans un QTableWidget
QSqlQueryModel* Partenaire::afficher() {



    // Create a new query model to hold the results
    QSqlQueryModel *model = new QSqlQueryModel();  // Dynamically allocated model



model->setQuery("select * from partenaires");
    // Set the header data for the columns (optional)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type Partenaire"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Ville"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Contact Principal"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Email"));

    return model;  // Return the model populated with the data
}

// Méthode pour ajouter un partenaire à la base de données
bool Partenaire::ajouter() {
    QSqlQuery query;

    // Préparer la requête d'insertion
    query.prepare("INSERT INTO PARTENAIRES ( NOM, TYPEPARTENAIRE, ADRESSE, VILLE, CONTACTPRINCIPAL, EMAIL) "
                  "VALUES ( :Nom, :TypePartenaire, :Adresse, :Ville, :ContactPrincipal, :Email)");

    // Liaison des valeurs aux paramètres
    query.bindValue(":Nom", Nom);
    query.bindValue(":TypePartenaire", TypePartenaire);
    query.bindValue(":Adresse", Adresse);
    query.bindValue(":Ville", Ville);
    query.bindValue(":ContactPrincipal", ContactPrincipal);
    query.bindValue(":Email", Email);

    // Log the query and parameters for debugging
    qDebug() << "Exécution de la requête : " << query.lastQuery();
    qDebug() << "Paramètres de la requête : "
             << "\nNom: " << Nom
             << "\nTypePartenaire: " << TypePartenaire
             << "\nAdresse: " << Adresse
             << "\nVille: " << Ville
             << "\nContactPrincipal: " << ContactPrincipal
             << "\nEmail: " << Email;

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



