#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QRegularExpression>  // Ajout de l'en-tête pour QRegularExpression
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableView->setModel(client.afficher());
    button_maram();
    // Connexion pour la recherche instantanée
    connect(ui->lineEdit_recherche, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_recherche_textChanged);
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

    // Contrôle de l'adresse email
    QRegularExpression emailRegex("^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$");
    if (!emailRegex.match(adresse).hasMatch()) {
        QMessageBox::warning(this, "Adresse email invalide", "Veuillez entrer une adresse email valide.");
        return;
    }

    // Contrôle du numéro de téléphone
    if (!tel.contains(QRegularExpression("^[0-9]{8}$"))) {
        QMessageBox::warning(this, "Numéro de téléphone invalide", "Le numéro de téléphone doit contenir 8 chiffres.");
        return;
    }

    // Contrôle du prix
    if (prix <= 0) {
        QMessageBox::warning(this, "Prix invalide", "Le prix doit être un nombre positif.");
        return;
    }

    // Contrôle de la date d'inscription
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
    QSqlQueryModel *currentModel = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
    if (!currentModel) return;

    // Vérifier que nous avons assez de colonnes (au moins 10)
    while (currentModel->columnCount() < 10) {
        currentModel->insertColumn(currentModel->columnCount());
    }

    // Colonnes fixes pour les boutons
    const int updateCol = 8;
    const int deleteCol = 9;

    for (int row = 0; row < currentModel->rowCount(); ++row) {
        // Création des boutons
        QPushButton *update_button = new QPushButton("Update", this);
        update_button->setStyleSheet("QPushButton {"
                                     "background-color:#437FF7;border-radius:5px;"
                                     "color:#fff;"
                                     "padding:5px;"
                                     "min-width:70px;"
                                     "}");

        QPushButton *delete_button = new QPushButton("Delete", this);
        delete_button->setStyleSheet("QPushButton {"
                                     "background-color:#ef1f22;border-radius:5px;"
                                     "color:#fff;"
                                     "padding:5px;"
                                     "min-width:70px;"
                                     "}");

        // Connexion du bouton Update
        connect(update_button, &QPushButton::clicked, [this, row, currentModel]() {
            int id = currentModel->index(row, 0).data().toInt();
            this->currentClientId = id;

            Client client = this->client.getclientById(id);
            ui->n->setText(client.get_nom());
            ui->p->setText(client.get_prenom());
            ui->a->setText(client.get_adresse());
            ui->t->setText(client.get_tel());
            ui->pr->setText(QString::number(client.get_prix()));
            ui->ty->setText(client.get_type());
            ui->di->setDate(client.get_dateInscription());
            ui->stackedWidget->setCurrentIndex(2);
        });

        // Connexion du bouton Delete
        connect(delete_button, &QPushButton::clicked, [this, row, currentModel]() {
            int id = currentModel->index(row, 0).data().toInt();
            if (this->client.supprimer(id)) {
                ui->tableView->setModel(this->client.afficher());
                button_maram();
                QMessageBox::information(this, "Succès", "Client supprimé avec succès");
            }
        });

        // Placement des boutons
        ui->tableView->setIndexWidget(currentModel->index(row, updateCol), update_button);
        ui->tableView->setIndexWidget(currentModel->index(row, deleteCol), delete_button);
    }
}

void MainWindow::on_lineEdit_recherche_textChanged(const QString &text) {
    static QTimer timer;
    timer.setSingleShot(true);
    timer.setInterval(300);

    connect(&timer, &QTimer::timeout, this, [this, text]() {
        if (text == ui->lineEdit_recherche->text()) {
            ui->tableView->setModel(client.rechercher(text.trimmed()));
            button_maram();
        }
    });

    timer.start();
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
    // Récupération des données du formulaire
    QString nom = ui->n->text().trimmed();
    QString prenom = ui->p->text().trimmed();
    QString adresse = ui->a->text().trimmed();
    QString tel = ui->t->text().trimmed();
    double prix = ui->pr->text().toDouble();
    QString type = ui->ty->text().trimmed();
    QDate dateInscription = ui->di->date();

    // Validation des données
    if (nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() || tel.isEmpty() || type.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Tous les champs doivent être remplis");
        return;
    }

    if (!tel.contains(QRegularExpression("^[0-9]{8}$"))) {
        QMessageBox::warning(this, "Téléphone invalide", "Le téléphone doit contenir 8 chiffres");
        return;
    }

    if (prix <= 0) {
        QMessageBox::warning(this, "Prix invalide", "Le prix doit être positif");
        return;
    }

    // Création de l'objet Client avec les nouvelles données
    Client clientModifie;
    clientModifie.set_nom(nom);
    clientModifie.set_prenom(prenom);
    clientModifie.set_adresse(adresse);
    clientModifie.set_tel(tel);
    clientModifie.set_prix(prix);
    clientModifie.set_type(type);
    clientModifie.set_dateInscription(dateInscription);

    // Appel de la fonction de modification
    if (clientModifie.modifier(currentClientId)) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès");
        ui->tableView->setModel(client.afficher()); // Rafraîchir l'affichage
        button_maram(); // Mettre à jour les boutons
        ui->stackedWidget->setCurrentIndex(0); // Retour à la liste
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du client");
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

/*void MainWindow::on_rechercherClient_clicked()
{
    QString critere = ui->lineEdit_recherche->text().trimmed();

    if (critere.isEmpty()) {
        ui->tableView->setModel(client.afficher());
    } else {
        ui->tableView->setModel(client.rechercher(critere));
    }

    button_maram();
}*/

// Remplacer l'ancien slot par une version optimisée
/*void MainWindow::on_lineEdit_recherche_textChanged(const QString &text) {
    // Délai de 300ms pour éviter des requêtes trop fréquentes
    QTimer::singleShot(300, this, [this, text]() {
        if (text == ui->lineEdit_recherche->text()) {  // Vérifie que le texte n'a pas changé pendant le délai
            ui->tableView->setModel(client.rechercher(text.trimmed()));
            button_maram();  // Met à jour les boutons
        }
    });
}
*/
