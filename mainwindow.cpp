#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "partenaire.h"

#include <QPushButton>  // Inclusion nécessaire pour QPushButton
#include <QMessageBox>// Pour afficher des messages d'erreur
#include <QFile>
#include <QStandardPaths>
#include <QTextStream>
#include <QVoice>
#include <QStandardItemModel>
#include <QProcess>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QSqlQuery>
#include <QtCharts>

#include <QSqlError>
#include <QVBoxLayout>

// Constructeur
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tts(new QTextToSpeech(this)),  // Initialisation de QTextToSpeech
    timer(new QTimer(this))
{
    ui->setupUi(this);
    ui->TypePartenaire->addItem("Sélectionnez un type"); // Premier choix invalide
    ui->TypePartenaire->addItem("Architecte");
    ui->TypePartenaire->addItem("Fournisseur");
    ui->typePartenaireInput->addItem("Sélectionnez un type"); // Premier choix invalide
    ui->typePartenaireInput->addItem("Architecte");
    ui->typePartenaireInput->addItem("Fournisseur");
    ui->tabWidget->setCurrentIndex(1);





    // Créez un objet Partenaire
    Partenaire p;

    // Récupérez le modèle et vérifiez qu'il n'est pas nul


    // Liez le modèle au QTableView
    rappelContratsFinissants();
    ui->tableView1->setModel(p.afficher());
    ui->tableView1->setItemDelegate(new ContratFinissantDelegate(this));
    ui->tableView1->setColumnHidden(9, true);

afficherNombreContratsEnCours();
    ui->tableView->setModel(p.statistiquesParType());
    ui->tableView->setColumnWidth(0, 150);
    ui->tableViewContrats->setColumnWidth(0, 150);

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
    delete tts;
    delete timer;
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
    QDate dateDebut = ui->dateEdit->date();
    QDate dateFin = ui->dateEdit_2->date();

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

    // Regex pour valider exemple@domaine.com ou exemple@domaine.tn
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.(com|tn)$)");

    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "L'email est invalide (ex: exemple@domaine.com ou exemple@domaine.tn) !");
        return;
    }
    if (dateDebut > dateFin) {
        QMessageBox::warning(this, "Erreur", "La date de fin doit être postérieure à la date de début !");
        return;
    }
    // 7. Validation de la date de début : La date de début doit être postérieure à la date actuelle
    if (dateDebut < QDate::currentDate()) {
        QMessageBox::warning(this, "Erreur", "La date de début doit être postérieure à la date actuelle !");
        return;
    }


    // Créer un objet Partenaire avec les valeurs récupérées
    Partenaire p(nom, typePartenaire, adresse, ville, contactPrincipal, email,dateDebut, dateFin);

    // Ajouter le partenaire dans la base
    if (p.ajouter()) {
        qDebug() << "✅ Partenaire ajouté avec succès !";
        ui->tableView1->setModel(p.afficher());
        ui->tableView1->setItemDelegate(new ContratFinissantDelegate(this));
        ui->tableView1->setColumnHidden(9, true);
        afficherNombreContratsEnCours();
        ui->tableView->setModel(p.statistiquesParType());
        ui->tableView->setColumnWidth(0, 150);
        ui->tableViewContrats->setColumnWidth(0, 150);
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
            ui->tableView1->setModel(p.afficher());
            afficherNombreContratsEnCours();
            ui->tableView->setModel(p.statistiquesParType());
            ui->tableView->setColumnWidth(0, 150);
            ui->tableViewContrats->setColumnWidth(0, 150);

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



        // Regex pour valider exemple@domaine.com ou exemple@domaine.tn
        QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.(com|tn)$)");

        if (!emailRegex.match(email).hasMatch()) {
            QMessageBox::warning(this, "Erreur", "L'email est invalide (ex: exemple@domaine.com ou exemple@domaine.tn) !");
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
            ui->tableView1->setItemDelegate(new ContratFinissantDelegate(this));
            ui->tableView1->setColumnHidden(9, true);
            afficherNombreContratsEnCours();
            ui->tableView->setModel(p.statistiquesParType());
            ui->tableView->setColumnWidth(0, 150);
            ui->tableViewContrats->setColumnWidth(0, 150);
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

    void MainWindow::afficherNombreContratsEnCours()


        {
            // Créer une instance de Partenaire
            Partenaire partenaire;

            // Obtenir le nombre de contrats en cours
            int nombreContrats = partenaire.nombreContratsEnCours();

            // Créer un modèle pour afficher les résultats dans un QTableView
            QStandardItemModel* model = new QStandardItemModel(1, 1, this);  // 1 ligne et 1 colonne

            // Définir le nom de la colonne
            model->setHorizontalHeaderItem(0, new QStandardItem("Contrat en cours"));

            // Ajouter la valeur du nombre de contrats en cours à la cellule (0, 0)
            model->setItem(0, 0, new QStandardItem(QString::number(nombreContrats)));

            // Afficher les résultats dans un QTableView
            ui->tableViewContrats->setModel(model);  // tableViewContrats est votre QTableView dans le fichier UI
        }




        void MainWindow::on_recherche_clicked()
        {
            QString rechercheNom = ui->lineEditRechercheNom->text();
            QString attributTrier = ui->comboBoxTrierPar->currentText();

            QString queryStr = "SELECT * FROM PARTENAIRES WHERE NOM LIKE :rechercheNom";

            if (!attributTrier.isEmpty()) {
                queryStr += " ORDER BY " + attributTrier;
            }

            QSqlQuery query;
            query.prepare(queryStr);
            query.bindValue(":rechercheNom", "%" + rechercheNom + "%"); // chaîne partielle

            if (!query.exec()) {
                qDebug() << "Erreur de requête : " << query.lastError().text();
                return;
            }

            QSqlQueryModel *model = new QSqlQueryModel();
            model->setQuery(query);
            if (model->rowCount() == 0) {
                QMessageBox::information(this, "Aucun résultat", "Aucun partenaire trouvé avec ce nom.");
                 // Vider la table
                return;
            }
            else{
            model->setHeaderData(0, Qt::Horizontal, "ID");
            model->setHeaderData(1, Qt::Horizontal, "Nom");
            model->setHeaderData(2, Qt::Horizontal, "Type partenaire");
            model->setHeaderData(3, Qt::Horizontal, "Adresse");
            model->setHeaderData(4, Qt::Horizontal, "Ville");
            model->setHeaderData(5, Qt::Horizontal, "Contact");
            model->setHeaderData(6, Qt::Horizontal, "Email");
            model->setHeaderData(7, Qt::Horizontal, "Date Début");
            model->setHeaderData(8, Qt::Horizontal, "Date Fin");

            ui->tableView1->setModel(model);
            }


        }


        void MainWindow::on_annuler_recherche_clicked()
        {
            Partenaire p;

            // Récupérez le modèle et vérifiez qu'il n'est pas nul


            // Liez le modèle au QTableView

            ui->tableView1->setModel(p.afficher());
            ui->lineEditRechercheNom->clear();

        }
        void MainWindow::on_pushButtonExporter_clicked()
        {
            QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
            QString fileName = desktopPath + "/export_partenaire.csv";

            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier pour écriture.");
                return;
            }

            QTextStream stream(&file);
            QAbstractItemModel *model = ui->tableView1->model();



            // Vérifie si le modèle est nul OU s'il n'a pas de lignes
            if (!model || model->rowCount() == 0) {
                QMessageBox::warning(this, "Erreur", "Aucune donnée à exporter.");
                return;
            }


            // En-têtes
            stream << "Nom,TypePartenaire,Email\n";

            for (int row = 0; row < model->rowCount(); ++row) {
                QString nom = model->data(model->index(row, 1)).toString();     // Colonne 1 : NOM
                QString type = model->data(model->index(row, 2)).toString();    // Colonne 2 : TYPEPARTENAIRE
                QString email = model->data(model->index(row, 6)).toString();   // Colonne 6 : EMAIL

                stream << "\"" << nom << "\","
                       << "\"" << type << "\","
                       << "\"" << email << "\"\n";
            }

            file.close();
            QMessageBox::information(this, "Succès", "Export réussi ! Fichier : export_partenaire.csv (sur le bureau)");
        }

        void MainWindow::rappelContratsFinissants()
        {
            QDate currentDate = QDate::currentDate();
            QDate dateLimite = currentDate.addDays(7);

            if (!QSqlDatabase::database().isOpen()) {
                qDebug() << "La base de données n'est pas ouverte.";
                return;
            }

            // Requête pour compter les contrats expirant bientôt
            QSqlQuery query;
            query.prepare(R"(
        SELECT COUNT(*)
        FROM PARTENAIRES
        WHERE DATEFIN BETWEEN :currentDate AND :dateLimite
    )");
            query.bindValue(":currentDate", currentDate);
            query.bindValue(":dateLimite", dateLimite);

            if (!query.exec()) {
                qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
                return;
            }

            int count = 0;
            if (query.next()) {
                count = query.value(0).toInt();
            }

            // Annonce avec QTextToSpeech
            if (count > 0) {
                QString message = QString("There %1 contract%2 that will expire in the next seven days.")
                .arg(count)
                    .arg(count > 1 ? "s" : "");
                tts->say(message);
            } else {
                tts->say("No contracts are expiring in the next seven days.");
            }

        }




