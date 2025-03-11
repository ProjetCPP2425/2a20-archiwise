#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError> // Pour QSqlError
#include <QSqlDatabase> // Pour QSqlDatabase (si vous l'utilisez)
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QSqlQueryModel(this);
    // Connect the "Ajouter" button to the slot
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_ajmateriel_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_clicked()
{
    // Récupérer les valeurs saisies
    QString nom = ui->nom->text().trimmed();
    double cout = ui->lineEditCout->text().toDouble();
    int quantite = ui->lineEditQuantite->text().toInt();
    QString etat = ui->lineEditEtat->text().trimmed();
    QString dateachat = ui->dateEditAchat->date().toString("yyyy-MM-dd"); // Conversion correcte pour SQL
    QString garantie = ui->lineEditGarantie->text().trimmed();

    // Validation des entrées
    if (nom.isEmpty() || etat.isEmpty() || garantie.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    // Vérification que le coût et la quantité sont valides
    if (cout <= 0 || quantite <= 0) {
        QMessageBox::warning(this, "Erreur", "Le coût et la quantité doivent être supérieurs à zéro !");
        return;
    }

    // Requête préparée pour ajouter un matériel
    QSqlQuery query;
    query.prepare("INSERT INTO materiel (nom, cout, quantite, etat, dateachat, garantie) "
                  "VALUES (:nom, :cout, :quantite, :etat, TO_DATE(:dateachat, 'YYYY-MM-DD'), :garantie)");
    query.bindValue(":nom", nom);
    query.bindValue(":cout", cout);
    query.bindValue(":quantite", quantite);
    query.bindValue(":etat", etat);
    query.bindValue(":dateachat", dateachat); // Utilisation correcte du nom de la colonne
    query.bindValue(":garantie", garantie);

    // Exécution de la requête
    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Matériel ajouté avec succès !");

        // Effacer les champs après ajout
        ui->nom->clear();
        ui->lineEditCout->clear();
        ui->lineEditQuantite->clear();
        ui->lineEditEtat->clear();
        ui->dateEditAchat->setDate(QDate::currentDate());
        ui->lineEditGarantie->clear();

        // Retour à la page principale
        ui->stackedWidget->setCurrentIndex(0);

        // Rafraîchir la table view pour afficher les éléments mis à jour
        ui->tableViewMateriel->setModel(materiel.afficher());
    } else {
        QMessageBox::critical(this, "Erreur SQL", "Échec de l'ajout du matériel : " + query.lastError().text());
    }
}


