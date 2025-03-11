#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projet.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(ptmp.afficher());
    button_doudi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajmateriel_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_ajouterClient_clicked()
{
    QString nom = ui->nom->text().trimmed();
    QString description = ui->description->text().trimmed();
    QString chefDeProject = ui->chefDeProject->text().trimmed();
    QDate dateDebut = ui->dateDebut->date();
    QDate dateFinPrevu = ui->dateFinPrevu->date();
    double budget = ui->budget->text().toDouble();
    QString statut = ui->statut->text().trimmed();

    // Vérification des champs obligatoires
    if (nom.isEmpty() || description.isEmpty() || chefDeProject.isEmpty() || statut.isEmpty()) {
        QMessageBox::warning(this, "Champ(s) manquant(s)", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    // Vérification du budget (doit être un nombre positif)
    if (budget <= 0) {
        QMessageBox::warning(this, "Budget invalide", "Le budget doit être un nombre positif.");
        return;
    }

    // Vérification de la cohérence des dates
    if (dateFinPrevu < dateDebut) {
        QMessageBox::warning(this, "Dates invalides", "La date de fin prévue doit être après la date de début.");
        return;
    }

    // Création de l'objet Projet et ajout
    Projet A(0, nom, description, chefDeProject, dateDebut, dateFinPrevu, budget, statut);

    if (A.ajouter()) {
        ui->tableView->setModel(A.afficher());
        button_doudi();
        QMessageBox::information(this, "Succès", "Le projet a été ajouté avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout du projet a échoué.");
    }

    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::button_doudi()
{
    for (int row = 0; row < ui->tableView->model()->rowCount(); ++row) {
        QPushButton *update_button = new QPushButton("Update", this);
        update_button->setStyleSheet("QPushButton {"
                                     "background-color:#437FF7;border-radius :5px; "
                                     "color : #fff;"
                                     "}");
        QPushButton *delete_button = new QPushButton("Delete", this);
        delete_button->setStyleSheet("QPushButton {"
                                     "background-color:#ef1f22;border-radius :5px; "
                                     "color : #fff;"
                                     "}");

        connect(update_button, &QPushButton::clicked, [this, row]() {
            Projet p;

            p.set_id(ui->tableView->model()->index(row, 0).data().toInt());
            p.set_nom(ui->tableView->model()->index(row, 1).data().toString());
            p.set_description(ui->tableView->model()->index(row, 2).data().toString());
            p.set_chefDeProjet(ui->tableView->model()->index(row, 3).data().toString());

            // Parse DateDebut
            QString dateDebutString = ui->tableView->model()->index(row, 4).data().toString();
            QDate dateDebut = QDate::fromString(dateDebutString, "yyyy-MM-dd");
            if (dateDebut.isValid()) {
                p.set_dateDebut(dateDebut);
            } else {
                qDebug() << "Error: Invalid DateDebut format!";
            }

            // Parse DateFinPrevu
            QString dateFinPrevuString = ui->tableView->model()->index(row, 5).data().toString();
            QDate dateFinPrevu = QDate::fromString(dateFinPrevuString, "yyyy-MM-dd");
            if (dateFinPrevu.isValid()) {
                p.set_dateFinPrevu(dateFinPrevu);
            } else {
                qDebug() << "Error: Invalid DateFinPrevu format!";
            }

            p.set_budget(ui->tableView->model()->index(row, 6).data().toFloat());
            p.set_statut(ui->tableView->model()->index(row, 7).data().toString());

            on_modifier_projet_clicked(p);
        });

        connect(delete_button, &QPushButton::clicked, [this, row]() {
            on_delete_projet_clicked(ui->tableView->model()->index(row, 0).data().toInt());
        });

        ui->tableView->setIndexWidget(ui->tableView->model()->index(row, 8), update_button);
        ui->tableView->setIndexWidget(ui->tableView->model()->index(row, 9), delete_button);
    }
}
void MainWindow::on_modifier_projet_clicked(Projet p) {
    if (p.get_id() == -1) {
        QMessageBox::critical(this, "Erreur", "Cet ID n'existe pas !");
        return;
    }

    // Récupération des données du projet
    QString nom = p.get_nom().trimmed();
    QString description = p.get_description().trimmed();
    QString chefDeProjet = p.get_chefDeProjet().trimmed();
    double budget = p.get_budget();
    QString statut = p.get_statut().trimmed();
    QDate dateDebut = p.get_dateDebut();
    QDate dateFinPrevu = p.get_dateFinPrevu();

    // Vérification des champs obligatoires
    if (nom.isEmpty() || description.isEmpty() || chefDeProjet.isEmpty() || statut.isEmpty()) {
        QMessageBox::warning(this, "Champ(s) manquant(s)", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    // Vérification du budget (doit être un nombre positif)
    if (budget <= 0) {
        QMessageBox::warning(this, "Budget invalide", "Le budget doit être un nombre positif.");
        return;
    }

    // Vérification de la cohérence des dates
    if (dateFinPrevu < dateDebut) {
        QMessageBox::warning(this, "Dates invalides", "La date de fin prévue doit être après la date de début.");
        return;
    }


    // Passage à la page de modification
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_delete_projet_clicked(int id){
    Projet p=ptmp.getprojetById(id);
    if (p.get_id()==-1){
        QMessageBox::critical(this, "Error", "This ID doesn't exist!");
    }else{
        bool test=ptmp.supprimer(id);

        if (test){
            ui->tableView->setModel(ptmp.afficher());
            button_doudi();

            QMessageBox::information(nullptr, QObject::tr("DONE"),
                                     QObject::tr("An event's been deleted.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }else
            QMessageBox::critical(nullptr, QObject::tr("FAIL"),
                                  QObject::tr("Error.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        ui->stackedWidget->setCurrentIndex(0);}

}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}






void MainWindow::on_ajouterClient_2_clicked()
{

}

