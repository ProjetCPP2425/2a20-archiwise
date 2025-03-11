#include "projet.h"
#include <QSqlError>
Projet::Projet()
{
    id = 0;
    nom = "";
    description = "";
    chefDeProjet = "";
    dateDebut = QDate::currentDate();
    dateFinPrevu = QDate::currentDate();
    budget = 0.0;
    statut = "";
}

Projet::Projet(int id, QString nom, QString description, QString chefDeProjet, QDate dateDebut, QDate dateFinPrevu, float budget, QString statut)
{
    this->id = id;
    this->nom = nom;
    this->description = description;
    this->chefDeProjet = chefDeProjet;
    this->dateDebut = dateDebut;
    this->dateFinPrevu = dateFinPrevu;
    this->budget = budget;
    this->statut = statut;
}

bool Projet::ajouter()
{
    QSqlQuery query;

    // Get the next available ID from a sequence
    query.prepare("SELECT NVL(MAX(ID), 0) + 1 FROM projets");
    if (!query.exec() || !query.next()) {
        return false;  // If the query fails, return false
    }

    int newId = query.value(0).toInt();  // Retrieve the new ID

    // Insert the new project with the generated ID
    query.prepare("INSERT INTO projets (ID, Nom, Description, ChefDeProjet, DateDebut, DateFinPrevu, Budget, Statut) "
                  "VALUES (:id, :nom, :description, :chefDeProjet, :dateDebut, :dateFinPrevu, :budget, :statut)");
    query.bindValue(":id", newId);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":chefDeProjet", chefDeProjet);
    query.bindValue(":dateDebut", dateDebut);
    query.bindValue(":dateFinPrevu", dateFinPrevu);
    query.bindValue(":budget", budget);
    query.bindValue(":statut", statut);

    return query.exec();
}


QSqlQueryModel* Projet::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("select * from projets");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ChefDeProjet"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DateDebut"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DateFinPrevu"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Budget"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Statut"));

    // Remove these if causing issues
    model->insertColumn(model->columnCount());
    model->insertColumn(model->columnCount());
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Update"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Delete"));

    return model;
}


bool Projet::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM projets WHERE Id = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Projet::modifier(int id, QString nom, QString description, QString chefDeProjet, QDate dateDebut, QDate dateFinPrevu, float budget, QString statut)
{
    QSqlQuery query;
    query.prepare("UPDATE projets SET Nom = :nom, Description = :description, ChefDeProjet = :chefDeProjet, "
                  "DateDebut = :dateDebut, DateFinPrevu = :dateFinPrevu, Budget = :budget, Statut = :statut WHERE Id = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":chefDeProjet", chefDeProjet);
    query.bindValue(":dateDebut", dateDebut);
    query.bindValue(":dateFinPrevu", dateFinPrevu);
    query.bindValue(":budget", budget);
    query.bindValue(":statut", statut);

    return query.exec();
}
Projet Projet::getprojetById(int id)
{
    QSqlQuery query;
    Projet pro;

    query.prepare("SELECT * FROM projets WHERE id = :id");
    query.bindValue(":id", id);

    // Exécution de la requête
    if(query.exec() && query.next())
    {
        pro.set_id(query.value(0).toInt());
        pro.set_nom(query.value(1).toString());
        pro.set_description(query.value(2).toString());
        pro.set_chefDeProjet(query.value(3).toString());
        pro.set_dateDebut(query.value(4).toDate());
        pro.set_dateFinPrevu(query.value(5).toDate());
        pro.set_budget(query.value(6).toDouble());
        pro.set_statut(query.value(7).toString());

    }

    return pro;
}
