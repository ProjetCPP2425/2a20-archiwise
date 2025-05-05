#include "materiel.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QDate>
<<<<<<< HEAD
=======
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QUrl>
#include <QPieSeries>
#include <QChartView>
#include <QtCharts>
#include <QMap>
#include <QPainter>

>>>>>>> f963b09 (projet qt)
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
<<<<<<< HEAD

bool Materiel::ajouter() {
    QSqlQuery query;

    // 📅 Date actuelle au format "DD-MM-YYYY"
    dateachat = QDate::currentDate();
    QString dateachatStr = dateachat.toString("dd-MM-yyyy");
=======
QString Materiel::getNom() const {
    return this->nom;
}

int Materiel::getQuantite() const {
    return this->quantite;
}

double Materiel::getCout() const {
    return this->cout;
}

QString Materiel::getEtat() const {
    return this->etat;
}

QDate Materiel::getDateAchat() const {
    return this->dateachat;
}

QString Materiel::getGarantie() const {
    return this->garantie;
}
bool Materiel::ajouter() {
    QSqlQuery query;

    // 📅 Date actuelle au format "YYYY-MM-DD" (correct pour Oracle)
    dateachat = QDate::currentDate();
    QString dateachatStr = dateachat.toString("yyyy-MM-dd");
>>>>>>> f963b09 (projet qt)

    qDebug() << "📅 Date achat insérée : " << dateachatStr; // 🔍 Debug

    // 🔹 Requête SQL avec TO_DATE() pour Oracle
<<<<<<< HEAD
    query.prepare("INSERT INTO materiel (id, cout, nom, quantite, etat, dateachat, garantie) "
                  "VALUES (:id, :cout, :nom, :quantite, :etat, TO_DATE(:dateachat, 'YYYY-MM-DD'), :garantie)");

    query.bindValue(":id", id);
=======
    query.prepare("INSERT INTO materiel (cout, nom, quantite, etat, dateachat, garantie) "
                  "VALUES (:cout, :nom, :quantite, :etat, TO_DATE(:dateachat, 'YYYY-MM-DD'), :garantie)");

    //query.bindValue(":id", id);
>>>>>>> f963b09 (projet qt)
    query.bindValue(":cout", cout);
    query.bindValue(":nom", nom);
    query.bindValue(":quantite", quantite);
    query.bindValue(":etat", etat);
<<<<<<< HEAD
    query.bindValue(":dateachat", dateachatStr);
=======
    query.bindValue(":dateachat", dateachatStr); // 🛠 Envoyer le format correct
>>>>>>> f963b09 (projet qt)
    query.bindValue(":garantie", garantie);

    if (query.exec()) {
        qDebug() << "✅ Matériel ajouté avec succès !";
        return true;
    } else {
        qDebug() << "❌ Erreur SQL :" << query.lastError().text();
        return false;
    }
<<<<<<< HEAD
}


// 🔹 Afficher la liste des matériels
QSqlQueryModel* Materiel::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM materiel");
   //  model->setQuery("SELECT id, nom, cout, quantité, etat, dateachat, garantie FROM materiel");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Coût"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
=======
    if (quantite <= 5) { // Vérification immédiate
        QTimer::singleShot(100, [this]() { // Petit délai pour laisser l'opération se compléter
            verifierStockCritique();
        });
    }

    return true;
}


bool Materiel::recupererParId(int id) {
    QSqlQuery query;
    query.prepare("SELECT NOM, QUANTITE, COUT, ETAT, DATEACHAT, GARANTIE,PROJETID FROM MATERIEL WHERE ID = :Id");
    query.bindValue(":Id", id);

    if (!query.exec() || !query.next()) {
        qDebug() << "❌ Aucun partenaire trouvé avec l'ID : " << id;
        return false;
    }

    nom = query.value(0).toString();
    quantite = query.value(1).toInt();
    cout = query.value(2).toInt();
    etat = query.value(3).toString();
    dateachat = query.value(4).toDate();
    garantie = query.value(5).toString();
  //  projetid = query.value(6).toInt();


    return true;
}



// 🔹 Afficher la liste des matériels
QSqlQueryModel* Materiel::afficher(const QString &sortBy) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString requete = "SELECT id, nom, cout, quantite, etat, dateachat, garantie FROM materiel";

    if (!sortBy.isEmpty()) {
        requete += " ORDER BY " + sortBy;
    }

    model->setQuery(requete);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Cout"));
>>>>>>> f963b09 (projet qt)
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("État"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Dateachat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Garantie"));
<<<<<<< HEAD
    model->insertColumn(model->columnCount());
    model->insertColumn(model->columnCount());
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Update"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Delete"));
=======



>>>>>>> f963b09 (projet qt)
    return model;
}

// 🔹 Supprimer un matériel
bool Materiel::supprimer(int id) {
    if (id <= 0) {
        qDebug() << "⚠️ ID invalide ! L'ID doit être un entier positif.";
        return false;
    }
<<<<<<< HEAD
    for (tableViewMateriel *item : selectedItems) {
        int row = item->row();
        QString id = ui->tw->item(row, 0)->text();
=======
>>>>>>> f963b09 (projet qt)

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
<<<<<<< HEAD
bool Materiel::modifier(int id,
                        double cout,
                        QString nom,
                        int quantite,
                        QString etat,
                        QDate dateachat,
                        QString garantie ) {
    if (id <= 0) {
        qDebug() << "⚠️ ID invalide ! L'ID doit être un entier positif.";
=======

// Dans materiel.cpp
bool Materiel::modifier(int id, double cout, QString nom, int quantite, QString etat, QDate dateachat, QString garantie)
{
    if(id <= 0) {
        qDebug() << "ID invalide pour modification";
        return false;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if(!db.isOpen()) {
        qDebug() << "Base de données non connectée";
>>>>>>> f963b09 (projet qt)
        return false;
    }

    QSqlQuery query;
<<<<<<< HEAD
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
=======
    QString dateStr = dateachat.toString("yyyy-MM-dd");

    query.prepare("UPDATE MATERIEL SET "
                  "NOM = :nom, "
                  "COUT = :cout, "
                  "QUANTITE = :quantite, "
                  "ETAT = :etat, "
                  "DATEACHAT = TO_DATE(:dateachat, 'YYYY-MM-DD'), "
                  "GARANTIE = :garantie "
                  "WHERE ID = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":cout", cout);
    query.bindValue(":quantite", quantite);
    query.bindValue(":etat", etat);
    query.bindValue(":dateachat", dateStr);
    query.bindValue(":garantie", garantie);

    if(!query.exec()) {
        qDebug() << "Échec de la modification - Erreur:" << query.lastError().text();
        return false;
    }

    if(query.numRowsAffected() <= 0) {
        qDebug() << "Aucune ligne affectée - ID probablement inexistant";
        return false;
    }

    // Vérification du stock critique après modification
    if (quantite <= 5) {
        QTimer::singleShot(0, []() {
            Materiel::verifierStockCritique();
        });
    }

    return true;
}
QSqlQueryModel* Materiel::afficherTrié(QString critere, QString ordre) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Vérification pour éviter l'injection SQL
    if (critere != "nom" && critere != "cout") {
        critere = "nom";  // Par défaut, on trie par nom
    }
    if (ordre != "ASC" && ordre != "DESC") {
        ordre = "ASC";  // Par défaut, tri croissant
    }

    // Requête SQL avec ORDER BY
    query.prepare("SELECT id, nom, cout, quantite, etat, dateachat, garantie FROM materiel ORDER BY " + critere + " " + ordre);
    query.exec();
    model->setQuery(std::move(query));

    return model;
}
QSqlQueryModel* Materiel::rechercher(const QString &critere, const QString &valeur) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString requete = "SELECT id, nom, cout, quantite, etat, dateachat, garantie FROM materiel WHERE ";

    if (critere == "nom") {
        requete += "LOWER(nom) LIKE LOWER(:valeur)";
    }
    else if (critere == "cout") {
        requete += "cout = :valeur";
    }
    else {
        requete += "id = :valeur";
    }

    QSqlQuery query;
    query.prepare(requete);

    if (critere == "nom") {
        query.bindValue(":valeur", "%" + valeur + "%");
    } else {
        bool ok;
        double val = valeur.toDouble(&ok);
        if (ok) query.bindValue(":valeur", val);
        else query.bindValue(":valeur", valeur);
    }

    if (!query.exec()) {
        qDebug() << "Erreur recherche:" << query.lastError().text();
        delete model;
        return nullptr;
    }

    model->setQuery(std::move(query)); // Correction ici pour éviter la copie

    // Définition des en-têtes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Cout"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("État"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Dateachat"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Garantie"));


    return model;
}
void Materiel::exporterPDF() {
    QString filePath = QFileDialog::getSaveFileName(nullptr, "Exporter en PDF", "", "PDF Files (*.pdf)");
    if (filePath.isEmpty()) return;

    QPdfWriter pdf(filePath);

    QPainter painter(&pdf);
    int i = 4000;

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 20));
    painter.drawText(3000, 1500, "Liste des Materiels");

    painter.setFont(QFont("Arial", 11));
    painter.drawText(1000, 2500, "Nom");
    painter.drawText(3000, 2500, "État");
    painter.drawText(5000, 2500, "Coût");

    QSqlQuery query;
    query.prepare("SELECT nom, etat, cout FROM materiel");
    if (query.exec()) {
        while (query.next()) {
            QString nom = query.value(0).toString();
            QString etat = query.value(1).toString();
            QString cout = QString::number(query.value(2).toDouble(), 'f', 2);

            painter.drawText(1000, i, nom);
            painter.drawText(3000, i, etat);
            painter.drawText(5000, i, cout + " DT");

            i += 500;
        }
    }

    painter.end();
}

void Materiel::verifierStockCritique(QWidget *parent) {
    QSqlQuery query("SELECT nom, quantite FROM materiel WHERE quantite <= 3");
    QString message;

    while (query.next()) {
        QString nom = query.value(0).toString();
        int quantite = query.value(1).toInt();
        message += "⚠️ " + nom + " : " + QString::number(quantite) + " en stock\n";
    }

    if (!message.isEmpty()) {
        QMessageBox msgBox(parent);
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Alerte Stock Critique");
        msgBox.setText("Les matériels suivants sont en stock critique :");
        msgBox.setInformativeText(message);
        msgBox.setStyleSheet("QLabel{ color: red; }");
        msgBox.exec();
    }
>>>>>>> f963b09 (projet qt)
}
