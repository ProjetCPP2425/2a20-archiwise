#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "partenaire.h"

#include <QPushButton>  // Inclusion nécessaire pour QPushButton
#include <QMessageBox>  // Pour afficher des messages d'erreur

// Constructeur
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->TypePartenaire->addItem("Sélectionnez un type"); // Premier choix invalide
    ui->TypePartenaire->addItem("Client");
    ui->TypePartenaire->addItem("Fournisseur");
    ui->typePartenaireInput->addItem("Sélectionnez un type"); // Premier choix invalide
    ui->typePartenaireInput->addItem("Client");
    ui->typePartenaireInput->addItem("Fournisseur");
    ui->tabWidget->setCurrentIndex(1);




    // Créez un objet Partenaire
    Partenaire p;

    // Récupérez le modèle et vérifiez qu'il n'est pas nul


    // Liez le modèle au QTableView
    ui->tableView1->setModel(p.afficher());
    qDebug() << "✅ Affichage des partenaires réussi.";

    QSqlQuery query("SELECT ID FROM PARTENAIRES");


ui->comboBoxPartenaires->clear();
    ui->comboBoxPartenaires_2->clear();
ui->comboBoxPartenaires_2->addItem("Sélectionnez un id");
ui->comboBoxPartenaires->addItem("Sélectionnez un id");
    while (query.next()) {
        int id = query.value(0).toInt();
         ui->comboBoxPartenaires->addItem(QString::number(id), id);
         ui->comboBoxPartenaires_2->addItem(QString::number(id), id);

    }












}
// Destructeur
MainWindow::~MainWindow()
{
    delete ui;
}

// Slot pour ajouter un partenaire
void MainWindow::on_btnAjouter_clicked()
{
    // Récupérer les valeurs des QLineEdit et les "trim" pour enlever les espaces inutiles
    QString nom = ui->Nom->text().trimmed();
    QString typePartenaire = ui->TypePartenaire->currentText().trimmed();
    QString adresse = ui->Adresse->text().trimmed();
    QString ville = ui->Ville->text().trimmed();
    QString contactPrincipal = ui->ContactPrincipal->text().trimmed();
    QString email = ui->Email->text().trimmed();

    // Vérification : Aucun champ ne doit être vide
    if (nom.isEmpty() || typePartenaire.isEmpty() || adresse.isEmpty() ||
        ville.isEmpty() ||  email.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs !");
        return;  // Sortie anticipée si un champ est vide
    }
    // Contrôle : Ne pas laisser le premier choix
    if (ui->TypePartenaire->currentIndex() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un type de partenaire valide !");
        return;
    }
    // 1. Validation du nom : Non vide, caractères alphabétiques, espaces et tirets, longueur max 50
    bool isValidNom = !nom.isEmpty() && nom.length() <= 50;
    for (const QChar &c : nom) {
        if (!(c.isLetter() || c == ' ' || c == '-')) {
            isValidNom = false;
            break;
        }
    }
    if (!isValidNom) {
        QMessageBox::warning(this, "Erreur", "Le nom est invalide (50 caractères max, lettres seulement) !");
        return;
    }



    // 3. Validation de l'adresse : Non vide, longueur max 100
    if (adresse.isEmpty() || adresse.length() > 100) {
        QMessageBox::warning(this, "Erreur", "L'adresse est invalide (100 caractères max) !");
        return;
    }

    // 4. Validation de la ville : Non vide, caractères alphabétiques, espaces et tirets, longueur max 50
    bool isValidVille = !ville.isEmpty() && ville.length() <= 50;
    for (const QChar &c : ville) {
        if (!(c.isLetter() || c == ' ' || c == '-')) {
            isValidVille = false;
            break;
        }
    }
    if (!isValidVille) {
        QMessageBox::warning(this, "Erreur", "La ville est invalide (50 caractères max, lettres seulement) !");
        return;
    }
    // 5. Validation du contact principal : Non vide, longueur max 100 (même règle que l'adresse)
    if (contactPrincipal.isEmpty() || contactPrincipal.length() > 100) {
        QMessageBox::warning(this, "Erreur", "Le contact principal est invalide (100 caractères max) !");
        return;
    }

    // 6. Validation de l'email : Format d'email valide
    bool isValidEmail = !email.isEmpty() && email.contains('@') && email.contains('.');
    int atIndex = email.indexOf('@');
    int dotIndex = email.lastIndexOf('.');

    // Vérification supplémentaire : '@' avant le dernier '.', caractères avant '@' et après '.'
    if (!(isValidEmail && atIndex > 0 && dotIndex > atIndex + 1 && dotIndex < email.length() - 1)) {
        QMessageBox::warning(this, "Erreur", "L'email est invalide (ex: exemple@domaine.com) !");
        return;
    }


    // Créer un objet Partenaire avec les valeurs récupérées
    Partenaire p(nom, typePartenaire, adresse, ville, contactPrincipal, email);

    // Ajouter le partenaire dans la base
    if (p.ajouter()) {
        qDebug() << "✅ Partenaire ajouté avec succès !";
        ui->tableView1->setModel(p.afficher());
        // Affichage d'un message de succès
        QMessageBox::information(this, "Succès", "L'ajout du partenaire a réussi avec succès !");

        // Vider les champs après l'ajout
        ui->Nom->clear();
        ui->TypePartenaire->setCurrentIndex(0);

        ui->Adresse->clear();
        ui->Ville->clear();
        ui->ContactPrincipal->clear();
        ui->Email->clear();

        //mettre a jour la liste des selections de la supprestion et modification
        QSqlQuery query("SELECT ID FROM PARTENAIRES");

        ui->comboBoxPartenaires->clear();
        ui->comboBoxPartenaires_2->clear();
        ui->comboBoxPartenaires_2->addItem("Sélectionnez un id");
        ui->comboBoxPartenaires->addItem("Sélectionnez un id");
        while (query.next()) {
            int id = query.value(0).toInt();
            ui->comboBoxPartenaires->addItem(QString::number(id), id);
            ui->comboBoxPartenaires_2->addItem(QString::number(id), id);

        }

        // Mettre à jour le QTableWidget avec les nouvelles données

    } else {
        qDebug() << "❌ Erreur lors de l'ajout du partenaire.";

        // Affichage d'un message d'erreur si l'ajout échoue
        QMessageBox::critical(this, "Erreur", "L'ajout du partenaire a échoué !");
    }
}

void MainWindow::on_supprimerr_clicked()
{

        // Récupérer l'ID du partenaire à supprimer à partir du QLineEdit

        int id = ui->comboBoxPartenaires_2->currentData().toInt();
        if (ui->comboBoxPartenaires_2->currentIndex() == 0) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un id!");
            return;
        }        // Assurez-vous que le QLineEdit s'appelle "lineEdit_IDS"

        // Vérifier que l'ID est valide (si l'ID est <= 0, la suppression n'est pas possible)
        if (id <= 0) {
            QMessageBox::warning(this, "ID invalide", "Veuillez entrer un ID valide !");
            return;
        }

        // Créer un objet Partenaire pour appeler la méthode supprimer()
        Partenaire p;

        // Appel de la méthode supprimer() et stocker le résultat dans test
        bool test = p.supprimer(id);

        // Afficher un message selon le résultat de la suppression
        if (test) {
            ui->tableView1->setModel(p.afficher());

            // Si la suppression a réussi
            QSqlQuery query("SELECT ID FROM PARTENAIRES");

            ui->comboBoxPartenaires->clear();
            ui->comboBoxPartenaires_2->clear();
            ui->comboBoxPartenaires_2->addItem("Sélectionnez un id");
            ui->comboBoxPartenaires->addItem("Sélectionnez un id");
            while (query.next()) {
                int id = query.value(0).toInt();
                ui->comboBoxPartenaires->addItem(QString::number(id), id);
                ui->comboBoxPartenaires_2->addItem(QString::number(id), id);

            }
            QMessageBox::information(this, QObject::tr("Succès"),
                                     QObject::tr("Suppression effectuée\nClick Cancel to exit."),
                                     QMessageBox::Cancel);
        } else {
            // Si la suppression a échoué
            QMessageBox::critical(this, QObject::tr("Erreur"),
                                  QObject::tr("Suppression non effectuée.\nClick Cancel to exit."),
                                  QMessageBox::Cancel);
        }
    }

void MainWindow::on_recuperer_clicked() {
    // Récupérer l'ID du partenaire depuis un QLineEdit (par exemple)
    int partnerId = ui->comboBoxPartenaires->currentData().toInt();
    if (ui->comboBoxPartenaires->currentIndex() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un id!");
        return;
    }        // Assurez-vous que le QLineEdit s'appelle "lineEdit_IDS"
    // ID récupéré depuis un QLineEdit

    Partenaire partenaire;

    // Vérifier si le partenaire existe dans la base
    if (partenaire.recupererParId(partnerId)) {
        // Si l'ID est trouvé, remplir les champs du formulaire avec les anciennes informations
        ui->nomInput->setText(partenaire.getNom());
        QString typePartenaire =partenaire.getTypePartenaire();
        if((typePartenaire)=="Client"){ui->typePartenaireInput->setCurrentIndex(1);}
        else{ui->typePartenaireInput->setCurrentIndex(2);}
        ui->adresseInput->setText(partenaire.getAdresse());
        ui->villeInput->setText(partenaire.getVille());
        ui->contactPrincipalInput->setText(partenaire.getContactPrincipal());
        ui->emailInput->setText(partenaire.getEmail());

        // Afficher un message de succès
        qDebug() << "✅ Partenaire trouvé, formulaire prêt pour modification.";
        ui->comboBoxPartenaires->setEnabled(false);
    } else {
        // Si l'ID n'est pas trouvé, afficher un message d'erreur
        qDebug() << "❌ Aucun partenaire trouvé avec l'ID : " << partnerId;
    }
}












    void MainWindow::on_modifier_clicked()
    {
        // Récupérer les nouvelles valeurs des champs du formulaire
        QString nom = ui->nomInput->text();
        QString typePartenaire = ui->typePartenaireInput->currentText().trimmed();
        QString adresse = ui->adresseInput->text();
        QString ville = ui->villeInput->text();
        QString contactPrincipal = ui->contactPrincipalInput->text();
        QString email = ui->emailInput->text();


        if (ui->comboBoxPartenaires->currentIndex() == 0) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un id!");
            return;
        }
        // Vérification : Aucun champ ne doit être vide
        if (nom.isEmpty() || typePartenaire.isEmpty() || adresse.isEmpty() ||
            ville.isEmpty() ||  email.isEmpty()) {
            QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs !");
            return;  // Sortie anticipée si un champ est vide
        }
        // Contrôle : Ne pas laisser le premier choix
        if (ui->typePartenaireInput->currentIndex() == 0) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un type de partenaire valide !");
            return;
        }
        // 1. Validation du nom : Non vide, caractères alphabétiques, espaces et tirets, longueur max 50
        bool isValidNom = !nom.isEmpty() && nom.length() <= 50;
        for (const QChar &c : nom) {
            if (!(c.isLetter() || c == ' ' || c == '-')) {
                isValidNom = false;
                break;
            }
        }
        if (!isValidNom) {
            QMessageBox::warning(this, "Erreur", "Le nom est invalide (50 caractères max, lettres seulement) !");
            return;
        }



        // 3. Validation de l'adresse : Non vide, longueur max 100
        if (adresse.isEmpty() || adresse.length() > 100) {
            QMessageBox::warning(this, "Erreur", "L'adresse est invalide (100 caractères max) !");
            return;
        }

        // 4. Validation de la ville : Non vide, caractères alphabétiques, espaces et tirets, longueur max 50
        bool isValidVille = !ville.isEmpty() && ville.length() <= 50;
        for (const QChar &c : ville) {
            if (!(c.isLetter() || c == ' ' || c == '-')) {
                isValidVille = false;
                break;
            }
        }
        if (!isValidVille) {
            QMessageBox::warning(this, "Erreur", "La ville est invalide (50 caractères max, lettres seulement) !");
            return;
        }
        // 5. Validation du contact principal : Non vide, longueur max 100 (même règle que l'adresse)
        if (contactPrincipal.isEmpty() || contactPrincipal.length() > 100) {
            QMessageBox::warning(this, "Erreur", "Le contact principal est invalide (100 caractères max) !");
            return;
        }

        // 6. Validation de l'email : Format d'email valide
        bool isValidEmail = !email.isEmpty() && email.contains('@') && email.contains('.');
        int atIndex = email.indexOf('@');
        int dotIndex = email.lastIndexOf('.');

        // Vérification supplémentaire : '@' avant le dernier '.', caractères avant '@' et après '.'
        if (!(isValidEmail && atIndex > 0 && dotIndex > atIndex + 1 && dotIndex < email.length() - 1)) {
            QMessageBox::warning(this, "Erreur", "L'email est invalide (ex: exemple@domaine.com) !");
            return;
        }


        // L'ID du partenaire à modifier, récupéré depuis le QLineEdit
        int partnerId = ui->comboBoxPartenaires->currentData().toInt();;

        Partenaire partenaire;
        partenaire.setNom(nom);
        partenaire.setTypePartenaire(typePartenaire);
        partenaire.setAdresse(adresse);
        partenaire.setVille(ville);
        partenaire.setContactPrincipal(contactPrincipal);
        partenaire.setEmail(email);

        // Modifier les informations dans la base de données
        if (partenaire.modifier(partnerId)) {
            Partenaire p;
            ui->tableView1->setModel(p.afficher());
            ui->nomInput->clear();
            ui->typePartenaireInput->setCurrentIndex(0);
            ui->adresseInput->clear();
            ui->villeInput->clear();
            ui->contactPrincipalInput->clear();
            ui->emailInput->clear();
            QMessageBox::information(this, QObject::tr("Succès"),
                                     QObject::tr("modification effectuée\nClick Cancel to exit."),
                                     QMessageBox::Cancel);
            qDebug() << "✅ Modifications enregistrées avec succès.";
            ui->comboBoxPartenaires->setEnabled(true);
            ui->comboBoxPartenaires->setCurrentIndex(0);
        } else {
            qDebug() << "❌ Erreur lors de l'enregistrement des modifications.";
        }
    }


    void MainWindow::on_annuler_modification_clicked()
    {
        ui->comboBoxPartenaires->setEnabled(true);
        ui->comboBoxPartenaires->setCurrentIndex(0);
        ui->nomInput->clear();
        ui->typePartenaireInput->setCurrentIndex(0);
        ui->adresseInput->clear();
        ui->villeInput->clear();
        ui->contactPrincipalInput->clear();
        ui->emailInput->clear();
    }


    void MainWindow::on_annuler_ajout_clicked()
    {
        ui->Nom->clear();
        ui->TypePartenaire->setCurrentIndex(0);

        ui->Adresse->clear();
        ui->Ville->clear();
        ui->ContactPrincipal->clear();
        ui->Email->clear();
    }

