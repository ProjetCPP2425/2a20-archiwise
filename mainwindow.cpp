#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QRegularExpression>  // Ajout de l'en-tête pour QRegularExpression

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(client.afficher());
    button_maram();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouterClient_clicked() {
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString prenom = ui->lineEdit_prenom->text().trimmed();
    QString adresse = ui->lineEdit_adresse->text().trimmed();
    QString tel = ui->lineEdit_tel->text().trimmed();
    double prix = ui->lineEdit_prix->text().toDouble();
    QString type = ui->lineEdit_type->text().trimmed();
    QDate dateInscription = ui->dateEdit_inscription->date();

    // Contrôles de saisie
    if (nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() || tel.isEmpty() || type.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    // Remplacement de QRegExp par QRegularExpression
    if (!tel.contains(QRegularExpression("^[0-9]{8}$"))) {
        QMessageBox::warning(this, "Numéro de téléphone invalide", "Le numéro de téléphone doit contenir 8 chiffres.");
        return;
    }

    if (prix <= 0) {
        QMessageBox::warning(this, "Prix invalide", "Le prix doit être un nombre positif.");
        return;
    }

    if (dateInscription > QDate::currentDate()) {
        QMessageBox::warning(this, "Date invalide", "La date d'inscription ne peut pas être dans le futur.");
        return;
    }

    // Création du client après vérification
    Client client(nom, prenom, adresse, tel, prix, type, dateInscription);

    if (client.ajouter()) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès !");
        ui->tableView->setModel(client.afficher());
        ui->stackedWidget->setCurrentIndex(0);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client.");
    }
}

void MainWindow::button_maram() {
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
            int id = ui->tableView->model()->index(row, 0).data().toInt();
            this->currentClientId = id; // Stockez l'ID du client sélectionné

            // Récupérer les autres données du client et appeler on_modifierClient_clicked
            Client client;
            client.set_id(id);
            client.set_nom(ui->tableView->model()->index(row, 1).data().toString());
            client.set_prenom(ui->tableView->model()->index(row, 2).data().toString());
            client.set_adresse(ui->tableView->model()->index(row, 3).data().toString());
            client.set_tel(ui->tableView->model()->index(row, 4).data().toString());
            client.set_prix(ui->tableView->model()->index(row, 5).data().toFloat());
            client.set_type(ui->tableView->model()->index(row, 6).data().toString());

            QString dateInscriptionString = ui->tableView->model()->index(row, 7).data().toString();
            QDate dateInscription = QDate::fromString(dateInscriptionString, "yyyy-MM-dd");

            if (dateInscription.isValid()) {
                client.set_dateInscription(dateInscription);
            } else {
                qDebug() << "Erreur : Format de date invalide !";
            }

            // Remplir les champs du formulaire de modification
            ui->n->setText(client.get_nom());
            ui->p->setText(client.get_prenom());
            ui->a->setText(client.get_adresse());
            ui->t->setText(client.get_tel());
            ui->pr->setText(QString::number(client.get_prix()));
            ui->ty->setText(client.get_type());
            ui->di->setDate(client.get_dateInscription());

            // Basculer vers la page du formulaire de modification
            ui->stackedWidget->setCurrentIndex(2); // Assurez-vous que l'index 2 correspond à la page de modification
        });

        connect(delete_button, &QPushButton::clicked, [this, row]() {
            int id = ui->tableView->model()->index(row, 0).data().toInt();
            on_supprimerClient_clicked(id);
        });

        ui->tableView->setIndexWidget(ui->tableView->model()->index(row, 8), update_button);
        ui->tableView->setIndexWidget(ui->tableView->model()->index(row, 9), delete_button);
    }
}

void MainWindow:: on_supprimerClient_clicked(int id) {
    Client client=client.getclientById(id);
    if (client.get_id()==-1){
        QMessageBox::critical(this, "Error", "This ID doesn't exist!");
    }else{
        bool test=client.supprimer(id);

        if (test){
            ui->tableView->setModel(client.afficher());
            button_maram();

            QMessageBox::information(nullptr, QObject::tr("DONE"),
                                     QObject::tr("An event's been deleted.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

        }else
            QMessageBox::critical(nullptr, QObject::tr("FAIL"),
                                  QObject::tr("Error.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_lineEdit_id_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_modifierClient_clicked() {
    QString nom = ui->n->text().trimmed();
    QString prenom = ui->p->text().trimmed();
    QString adresse = ui->a->text().trimmed();
    QString tel = ui->t->text().trimmed();
    QString prixStr = ui->pr->text().trimmed();
    double prix = prixStr.toDouble();
    QString type = ui->ty->text().trimmed();
    QDate dateInscription = ui->di->date();

    // Récupérer l'ID du client à modifier
    int id = this->currentClientId;

    // Contrôles de saisie
    if (nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() || tel.isEmpty() || type.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    if (!tel.contains(QRegularExpression("^[0-9]{8}$"))) {
        QMessageBox::warning(this, "Numéro de téléphone invalide", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
        return;
    }

    QRegularExpression prixRegex("^[+]?[0-9]*\\.?[0-9]+$"); // Nombre positif avec ou sans décimales
    if (!prixRegex.match(prixStr).hasMatch() || prix <= 0) {
        QMessageBox::warning(this, "Prix invalide", "Le prix doit être un nombre positif.");
        return;
    }

    if (dateInscription > QDate::currentDate()) {
        QMessageBox::warning(this, "Date invalide", "La date d'inscription ne peut pas être dans le futur.");
        return;
    }

    // Création de l'objet Client avec les nouvelles données
    Client clientModifie(nom, prenom, adresse, tel, prix, type, dateInscription);
    clientModifie.set_id(id);

    // Appel de la méthode modifier() pour mettre à jour les données dans la base de données
    if (clientModifie.modifier(id, nom, prenom, adresse, tel, prix, type, dateInscription)) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès !");
        ui->tableView->setModel(clientModifie.afficher()); // Mise à jour de l'affichage
        ui->stackedWidget->setCurrentIndex(0); // Retour à la page principale
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du client.");
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
