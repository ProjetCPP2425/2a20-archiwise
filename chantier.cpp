#include "chantier.h"


#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QStandardPaths>
#include <QSqlRecord>
#include <QPrinter>
#include <QTextDocument>
chantier::chantier()
{
    id = 0;
    nomchantier = "";
    adresse = "";
    datedebut = QDate();
    datefinprevu = QDate();
    datefinreelle = QDate();
    statut = "";
    budgetinitial = 0.0;
    coutreel = 0.0;
    progression = 0;
    temperature = 0.0;
}

chantier::chantier(int id, QString nomchantier, QString adresse, QDate datedebut, QDate datefinprevu, QDate datefinreelle, QString statut, double budgetinitial, double coutreel, int progression, double temperature)
{
    this->id = id;
    this->nomchantier = nomchantier;
    this->adresse = adresse;
    this->datedebut = datedebut;
    this->datefinprevu = datefinprevu;
    this->datefinreelle = datefinreelle;
    this->statut = statut;
    this->budgetinitial = budgetinitial;
    this->coutreel = coutreel;
    this->progression = progression;
    this->temperature = temperature;
}

bool chantier::ajouter()
{

    QSqlQuery query;

    // Get the next available ID from a sequence
    query.prepare("SELECT NVL(MAX(ID), 0) + 1 FROM chantiers");
    if (!query.exec() || !query.next()) {
        return false;  // If the query fails, return false
    }

    int newId = query.value(0).toInt();
    query.prepare("INSERT INTO chantiers (id, nomchantier, adresse, datedebut, datefinprevu, datefinreelle, statut, budgetinitial, coutreel, progression, temperature) "
                  "VALUES (:id, :nomchantier, :adresse, :datedebut, :datefinprevu, :datefinreelle, :statut, :budgetinitial, :coutreel, :progression, :temperature)");
    query.bindValue(":id", newId);
    query.bindValue(":nomchantier", nomchantier);
    query.bindValue(":adresse", adresse);
    query.bindValue(":datedebut", datedebut);
    query.bindValue(":datefinprevu", datefinprevu);
    query.bindValue(":datefinreelle", datefinreelle);
    query.bindValue(":statut", statut);
    query.bindValue(":budgetinitial", budgetinitial);
    query.bindValue(":coutreel", coutreel);
    query.bindValue(":progression", progression);
    query.bindValue(":temperature", temperature);
    return query.exec();
}

QSqlQueryModel * chantier::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT id, nomchantier, adresse, datedebut, datefinprevu, datefinreelle, statut, budgetinitial, coutreel, progression, temperature FROM chantiers");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomchantier"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datedebut"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("datefinprevu"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datefinreelle"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("statut"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("budgetinitial"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("coutreel"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("progression"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("temperature"));

    // Remove these if causing issues
    model->insertColumn(model->columnCount());
    model->insertColumn(model->columnCount());
    model->setHeaderData(11, Qt::Horizontal, QObject::tr("Update"));
    model->setHeaderData(12, Qt::Horizontal, QObject::tr("Delete"));


    return model;
}

bool chantier::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("DELETE FROM chantiers WHERE id = :id");
    query.bindValue(":id", res);
    return query.exec();
}



bool chantier::modifier(int id, const QString &nomchantier, const QString &adresse, const QDate &datedebut,
                        const QDate &datefinprevu, const QDate &datefinreelle, const QString &statut,
                        double budgetinitial, double coutreel, int progression, double temperature)
{
    QSqlQuery query;
    QString res = QString::number(id);

    // ✅ Logs de debug
    qDebug() << "[chantier::modifier] ID =" << id;
    qDebug() << "[chantier::modifier] Nom =" << nomchantier;
    qDebug() << "[chantier::modifier] Adresse =" << adresse;
    qDebug() << "[chantier::modifier] Date début =" << datedebut.toString("yyyy-MM-dd");
    qDebug() << "[chantier::modifier] Date fin prévue =" << datefinprevu.toString("yyyy-MM-dd");
    qDebug() << "[chantier::modifier] Date fin réelle =" << datefinreelle.toString("yyyy-MM-dd");
    qDebug() << "[chantier::modifier] Statut =" << statut;
    qDebug() << "[chantier::modifier] Budget initial =" << budgetinitial;
    qDebug() << "[chantier::modifier] Coût réel =" << coutreel;
    qDebug() << "[chantier::modifier] Progression =" << progression;
    qDebug() << "[chantier::modifier] temperature =" << temperature;

    query.prepare("UPDATE chantiers SET "
                  "nomchantier = :nomchantier, adresse = :adresse, "
                  "datedebut = :datedebut, datefinprevu = :datefinprevu, datefinreelle = :datefinreelle, "
                  "statut = :statut, budgetinitial = :budgetinitial, coutreel = :coutreel, "
                  "progression = :progression, temperature = :temperature "
                  "WHERE id = :id");

    // 🧩 Bind des paramètres
    query.bindValue(":id", res);
    query.bindValue(":nomchantier", nomchantier);
    query.bindValue(":adresse", adresse);
    query.bindValue(":datedebut", datedebut);
    query.bindValue(":datefinprevu", datefinprevu);
    query.bindValue(":datefinreelle", datefinreelle);
    query.bindValue(":statut", statut);
    query.bindValue(":budgetinitial", budgetinitial);
    query.bindValue(":coutreel", coutreel);
    query.bindValue(":progression", progression);
    query.bindValue(":temperature", temperature);

    if (!query.exec()) {
        qDebug() << "❌ ERREUR SQL MODIFICATION :" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ MODIFICATION réussie pour ID =" << id;
    return true;
}


chantier chantier::getchantierById(int id)
{
    QSqlQuery query;
    chantier ch;

    query.prepare("SELECT * FROM chantiers WHERE id = :id");
    query.bindValue(":id", id);

    // Exécution de la requête
    if(query.exec() && query.next())
    {
        ch.set_id(query.value(0).toInt());
        ch.set_nomchantier(query.value(1).toString());
        ch.set_adresse(query.value(2).toString());
        ch.set_datedebut(query.value(3).toDate());
        ch.set_datefinprevu(query.value(4).toDate());
        ch.set_datefinreelle(query.value(5).toDate());
        ch.set_statut(query.value(6).toString());
        ch.set_budgetinitial(query.value(7).toDouble());
        ch.set_coutreel(query.value(8).toDouble());
        ch.set_progression(query.value(9).toInt());
        ch.set_temperature(query.value(10).toDouble());
    }

    return ch;
}

QSqlQueryModel *chantier::search(const QString &criteria)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;


    QString checkQuery = "SELECT COUNT(*) FROM chantiers WHERE nomchantier LIKE :criteria";
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


    query.prepare("SELECT * FROM chantiers WHERE nomchantier LIKE :criteria");
    query.bindValue(":criteria", criteria + "%");

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomchantier"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("datedebut"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("datefinprevu"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("datefinreelle"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("statut"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("budgetinitial"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("coutreel"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("progression"));


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

QSqlQueryModel *chantier::sort(const QString &criteria)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    QString select = "SELECT * FROM chantiers ORDER BY " + criteria + " ASC";
    query.prepare(select);

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nomchantier"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("datedebut"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("datefinprevu"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("datefinreelle"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("statut"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("budgetinitial"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("coutreel"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("progression"));

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
QSqlQueryModel* chantier::getEventStatistics()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT statut, COUNT(ID) as chantier_count FROM chantiers GROUP BY statut");

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("statut"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("chantier_count"));
        return model;
    } else {
        qDebug() << "Error retrieving event statistics:" << query.lastError().text();
        return nullptr;
    }
}

bool chantier::exportToPdf()
{

    QString htmlContent = "<div style='text-align: center;'><h1 style='color: blue;'>Gestion de bureau d'architecte</h1>";
    htmlContent += "<p>Notre solution offre une gestion complète pour bureaux d'architectes, intégrant la gestion centralisée des utilisateurs, des projets, des chantiers, des fournisseurs, des employés et des clients, permettant ainsi une optimisation des processus métiers et une collaboration fluide entre tous les acteurs du projet architectural</p></div><br><br><br><br>";


    htmlContent += "<div style='text-align: center;'><h1 style='color: bleu;'>Liste des Chantiers</h1></div>";
    htmlContent += "<table style='border-collapse: collapse; width: 100%; margin: auto;'>";
    htmlContent += "<thead><tr>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>id</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>Nom du chantier</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>Adresse</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>Date debut</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>Date fin prevu</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>Date fin reelle</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>Statut</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>Budget initial</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>Cout reel</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>Progression</th>"
                   "<th style='border: 1px solid #000; padding: 8px; text-align: left;font-weight: bold;'>temperature</th>"


                   "</tr></thead>";
    QSqlQuery query("SELECT * FROM chantiers");

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

    QString filePath = documentsPath + "/chantier.pdf";

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


QVector<QString> chantier::verifierAlertes() const {
    QVector<QString> alertes;
    QDate aujourdhui = QDate::currentDate();

    if (progression < 100 && datefinprevu.isValid() && datefinprevu < aujourdhui) {
        alertes.append("⏳ Chantier en retard (fin prévue : " + datefinprevu.toString("dd/MM/yyyy") + ")");
    }

    if (budgetinitial > 0 && coutreel > budgetinitial) {
        double depassement = coutreel - budgetinitial;
        alertes.append("💸 Dépassement de budget : " + QString::number(depassement, 'f', 2) + " TND");
    }

    return alertes;
}







