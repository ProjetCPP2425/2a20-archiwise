#include "projet.h"
#include <QSqlError>
#include <QPrinter>
#include <QTextDocument>
#include <QStandardPaths>
#include <QSqlRecord>
#include <QProcess>


Projet::Projet()
{
    id = -1;
    nom = "";
    description = "";
    chefDeProjet = "";
    dateDebut = QDate();
    dateFinPrevu = QDate();
    budget = 0.0;
    statut = "";
    adresse = "";
    upload="";

}

Projet::Projet(int id, QString nom, QString description, QString chefDeProjet, QDate dateDebut, QDate dateFinPrevu, float budget, QString statut,QString adresse,QString upload)
{
    this->id = id;
    this->nom = nom;
    this->description = description;
    this->chefDeProjet = chefDeProjet;
    this->dateDebut = dateDebut;
    this->dateFinPrevu = dateFinPrevu;
    this->budget = budget;
    this->statut = statut;
    this->adresse = adresse;
    this->upload = upload;
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
    query.prepare("INSERT INTO projets (ID, Nom, Description, ChefDeProjet, DateDebut, DateFinPrevu, Budget, Statut,adresse,upload) "
                  "VALUES (:id, :nom, :description, :chefDeProjet, :dateDebut, :dateFinPrevu, :budget, :statut, :adresse, :upload)");
    query.bindValue(":id", newId);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":chefDeProjet", chefDeProjet);
    query.bindValue(":dateDebut", dateDebut);
    query.bindValue(":dateFinPrevu", dateFinPrevu);
    query.bindValue(":budget", budget);
    query.bindValue(":statut", statut);
    query.bindValue(":adresse", adresse);
    query.bindValue(":upload", upload);


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
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("upload"));

    // Remove these if causing issues
    model->insertColumn(model->columnCount());
    model->insertColumn(model->columnCount());
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Update"));
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Delete"));

    return model;
}


bool Projet::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM projets WHERE Id = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool Projet::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE PROJETS SET NOM = :nom, DESCRIPTION = :description, CHEFDEPROJET = :chefDeProjet, "
                  "DATEDEBUT = :dateDebut, DATEFINPREVU = :dateFinPrevu, BUDGET = :budget, STATUT = :statut , adresse = :adresse,upload= :upload WHERE ID = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);
    query.bindValue(":chefDeProjet", chefDeProjet);
    query.bindValue(":dateDebut", dateDebut);
    query.bindValue(":dateFinPrevu", dateFinPrevu);
    query.bindValue(":budget", budget);
    query.bindValue(":statut", statut);
    query.bindValue(":adresse", adresse);
    query.bindValue(":upload", upload);


    return query.exec();
}
Projet Projet::getprojetById(int id)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM projets WHERE id = :id");
    query.bindValue(":id", id);

    // Exécution de la requête
    if(query.exec() && query.next())
    {
        return Projet(query.value("id").toInt(),
                      query.value("nom").toString(),
                      query.value("description").toString(),
                      query.value("chefDeProjet").toString(),
                      query.value("dateDebut").toDate(),
                      query.value("dateFinPrevu").toDate(),
                      query.value("budget").toFloat(),
                      query.value("statut").toString(),
                      query.value("adresse").toString(),
                      query.value("upload").toString());

    }

    return Projet();
}

QSqlQueryModel *Projet::search(const QString &criteria)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;


    QString checkQuery = "SELECT COUNT(*) FROM projets WHERE nom LIKE :criteria";
    query.prepare(checkQuery);
    query.bindValue(":criteria", criteria + "%"); // Append % to match names starting with 'criteria'

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        if (count == 0) {
            return nullptr;
        }
    } else {
        return nullptr;
    }


    query.prepare("SELECT * FROM projets WHERE nom LIKE :criteria");
    query.bindValue(":criteria", criteria + "%");

    if (query.exec()) {
        model->setQuery(std::move(query));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ChefDeProjet"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DateDebut"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("DateFinPrevu"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Budget"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Statut"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("adresse"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("upload"));

        // Remove these if causing issues
        model->insertColumn(model->columnCount());
        model->insertColumn(model->columnCount());
        model->setHeaderData(10, Qt::Horizontal, QObject::tr(""));
        model->setHeaderData(11, Qt::Horizontal, QObject::tr(""));

        return model;
    } else {
        return nullptr;
    }
}

QSqlQueryModel *Projet::sort(const QString &criteria)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    QString select = "SELECT * FROM projets ORDER BY " + criteria + " ASC";
    query.prepare(select);

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("ChefDeProjet"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("DateDebut"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("DateFinPrevu"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Budget"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Statut"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("adresse"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("upload"));

        // Remove these if causing issues
        model->insertColumn(model->columnCount());
        model->insertColumn(model->columnCount());
        model->setHeaderData(10, Qt::Horizontal, QObject::tr(""));
        model->setHeaderData(11, Qt::Horizontal, QObject::tr(""));



        return model;
    } else {
        return nullptr;
    }
}

//stats
QSqlQueryModel* Projet::getEventStatistics()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT CHEFDEPROJET, COUNT(ID) as projet_count FROM projets GROUP BY CHEFDEPROJET");

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CHEFDEPROJET"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("projet_count"));
        return model;
    } else {
        qDebug() << "Error retrieving event statistics:" << query.lastError().text();
        return nullptr;
    }
}

bool Projet::exportToPdf()
{

    QString htmlContent = "<div style='text-align: center;'><h1 style='color: orange;'>Gestion des projets</h1>";



    htmlContent += "<table style='border-collapse: collapse; width: 100%; margin: auto;'>";
    htmlContent += "<thead><tr>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>id</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>nom</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>description</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>chef de projet</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>date de debut</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>date fin prevu</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>Budget</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>statut</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>adresse</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>upload</th>"


                   "</tr></thead>";
    QSqlQuery query("SELECT * FROM projets");

    htmlContent += "<tbody>";

    while (query.next()) {
        htmlContent += "<tr>";
        for (int i = 0; i < query.record().count(); ++i) {
            htmlContent += "<td style='border: 1px solid #000; padding: 8px;'>" + query.value(i).toString() + "</td>";
        }
        htmlContent += "</tr>";
    }
    htmlContent += "</tbody>";

    htmlContent += "</table></div><br><br><br><br>";
    QString logoHtml = "<div style='margin: auto;'><img src=':/img/logo.png' alt='Logo' style='max-width: 40px;'>";
    htmlContent += logoHtml;


    QString documentsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

    QString filePath = documentsPath + "/projet.pdf";

    // Create a QTextDocument and set its HTML content
    QTextDocument doc;
    doc.setHtml(htmlContent);

    // Create a QPrinter
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);

    // Print the document to the printer
    doc.print(&printer);

    if (doc.isEmpty()) {
        qDebug() << "Error printing to PDF:" ;
        return false;
    }

    qDebug() << "PDF exported successfully to:" << filePath;
    return true;
}
