#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "partenaire.h"
#include "ButtonDelegate.h"
#include <QRegularExpression>

#include <QDebug>
#include <QPushButton>  // Inclusion nécessaire pour QPushButton
#include <QMessageBox>// Pour afficher des messages d'erreur
#include <QFile>
#include <QStandardPaths>
#include <QTextStream>
#include <QVoice>
#include <QStandardItemModel>
#include <QProcess>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QSqlQuery>
#include <QtCharts>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QSqlError>
#include <QVBoxLayout>
#include <random>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
////////////////////////////////////hajjouni
#include "chantier.h"
#include "chantierdelegate.h"
#include <qmessagebox.h>
#include <QPieSeries>
#include <QChart>
#include <QChartView>
#include <QIcon>
#include<QTimer>
#include<QCalendarWidget>

// Constructeur
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tts(new QTextToSpeech(this)),// Initialisation de QTextToSpeech

    temperatureManager(new SerialTemperatureManager(this)),/////////////////////////hajjouni
    timer(new QTimer(this))

{
    ui->setupUi(this);
    /////////////////////////////hajjouni
    ui->tableView->setItemDelegate(new ChantierDelegate(this));
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    setWindowIcon(QIcon(":/icon/logo.jpg"));
    ui->tableView->setModel(c.afficher());
    button_hajjouni();


    detecterChantiersEnRetard();
    ui->datedebut->setDate(QDate::currentDate());





    //partie mtaa houdhaifa----------------------------------------------------------------------------------

    ui->TypePartenaire->addItem("Sélectionnez un type"); // Premier choix invalide
    ui->TypePartenaire->addItem("Architecte");
    ui->TypePartenaire->addItem("Fournisseur");
    ui->typePartenaireInput->addItem("Sélectionnez un type"); // Premier choix invalide
    ui->typePartenaireInput->addItem("Architecte");
    ui->typePartenaireInput->addItem("Fournisseur");
    ui->tabWidget->setCurrentIndex(1);


    botResponses << "Bonjour! Comment puis-je vous aider avec les partenaires ?"
                 << "D'accord, je vais vérifier les partenaires."
                 << "Je peux vous aider à gérer les informations des partenaires."
                 << "Quel type de partenaire voulez-vous consulter ?"
                 << "Avez-vous des questions sur les contrats ?";


    ajouterMessageBot("👋 Bonjour ! Je suis votre assistant intelligent. Posez-moi n'importe quelle question concernant les partenaires !");
    ajouterMessageBot(" Voici quelques questions que vous pouvez me poser :<br>"
                      "- quels sont les partenaires de type architecte ?<br>"
                      "- quels sont les partenaires de type fournisseur?<br>"
                      "- quels sont les partenaires dans la ville NomDeLaVille ?<br>"
                      "- quels sont les partenaires qui ont un contrat expiré ?<br>"
                      "- quels sont les partenaires qui ont un contrat en cours ?<br>"
                      );
    // Revenir au début du texte
    QTextCursor cursor = ui->conversationTextEdit->textCursor();
    cursor.movePosition(QTextCursor::Start);
    ui->conversationTextEdit->setTextCursor(cursor);
    QStringList suggestions = {
        "quels sont les partenaires de type architecte",
        "quels sont les partenaires de type fournisseur",
        "quels sont les partenaires dans la ville NomDeLaVille",
        "quels sont les partenaires qui ont un contrat expiré",
        "quels sont les partenaires qui ont un contrat en cours"
    };
    QCompleter *completer = new QCompleter(suggestions, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->inputLineEdit->setCompleter(completer);



    connect(&serialPort, &QSerialPort::readyRead, this, &MainWindow::readSerialData);



    // Créez un objet Partenaire


    // Récupérez le modèle et vérifiez qu'il n'est pas nul
setupSerialPort();

    // Liez le modèle au QTableView
    rappelContratsFinissants();

    setupTableView();
    initialiserCompleter();
    // Colonne "Actions"



afficherStatistiquesContrats();

    afficherStatistiquesPartenaires();

    qDebug() << "✅ Affichage des partenaires réussi.";

    QSqlQuery query("SELECT ID FROM PARTENAIRES");

//partie mtaa slim -----------------------------------------------------------------------------------------------------------


    connect(ui->btn_add, &QPushButton::clicked, this, &MainWindow::on_btn_add_clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_pdf_clicked);
    emp.afficher(ui->tableWidget);




}
// Destructeur
MainWindow::~MainWindow()
{
    delete ui;
    delete tts;
    delete timer;
}
//partie mtaa houdhaifa ---------------------------------------------------------------------------------------------------------
void MainWindow::ajouterMessageUtilisateur(const QString &message) {
    QString html = "<table width='100%' ><tr><td></td><td align='left' width='70%'>"
                   "<div style='background-color:#ffc7c7; color:#fff; padding:10px 12px; "
                   "border-radius:18px 18px 0 18px; margin:4px 0; display:inline-block; "
                   "font-family:Segoe UI, Arial, sans-serif;'>"
                   "<b>👤 Vous :</b> " + message + "</div></td></tr></table>";
    ui->conversationTextEdit->append(html);
}

void MainWindow::ajouterMessageBot(const QString &message) {
    QString html = "<table width='100%'><tr><td align='left' width='70%'>"
                   "<div style='background-color:#e4e6eb; color:#000; padding:10px 12px; "
                   "border-radius:18px 18px 18px 0; margin:4px 0; display:inline-block; "
                   "font-family:Segoe UI, Arial, sans-serif;'>"
                   "<b>🤖 Bot :</b> " + message + "</div></td></tr></table>";
    ui->conversationTextEdit->append(html);
    ui->conversationTextEdit->moveCursor(QTextCursor::End);

}
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


void MainWindow::initialiserCompleter() {
    QStringList listeNoms;
    QSqlQuery query("SELECT NOM FROM PARTENAIRES");

    while (query.next()) {
        listeNoms << query.value(0).toString();
    }

    QCompleter *completer = new QCompleter(listeNoms, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains); // Pour suggérer même si le nom est au milieu de la saisie

    ui->lineEditRechercheNom->setCompleter(completer);
}



void MainWindow::processUserInput(const QString &input)
{
    QString response;

    if (input.contains("quels sont les partenaires de type architecte", Qt::CaseInsensitive)) {
        QSqlQuery query;
        query.prepare("SELECT NOM FROM PARTENAIRES WHERE TYPEPARTENAIRE = :type");
        query.bindValue(":type", "Architecte");

        if (query.exec()) {
            QStringList noms;
            while (query.next()) {
                noms << query.value(0).toString();
            }
            if (!noms.isEmpty()) {
                response = QString("Il y a %1 partenaires de type architecte :<br>- %2")
                .arg(noms.size())
                    .arg(noms.join("<br>- "));
            } else {
                response = "Aucun partenaire de type architecte trouvé.";
            }
        } else {
            response = "Erreur lors de la récupération des architectes.";
        }
    }

    else if (input.contains("quels sont les partenaires de type fournisseur", Qt::CaseInsensitive)) {
        QSqlQuery query;
        query.prepare("SELECT NOM FROM PARTENAIRES WHERE TYPEPARTENAIRE = :type");
        query.bindValue(":type", "Fournisseur");

        if (query.exec()) {
            QStringList noms;
            while (query.next()) {
                noms << query.value(0).toString();
            }
            if (!noms.isEmpty()) {
                response = QString("Il y a %1 partenaires de type fournisseur :<br>- %2")
                .arg(noms.size())
                    .arg(noms.join("<br>- "));
            } else {
                response = "Aucun partenaire de type fournisseur trouvé.";
            }
        } else {
            response = "Erreur lors de la récupération des fournisseurs.";
        }
    }

    else if (input.contains("quels sont les partenaires dans la ville", Qt::CaseInsensitive)) {
        QRegularExpression regExp("ville ([\\w\\s]+)", QRegularExpression::CaseInsensitiveOption);
        QRegularExpressionMatch match = regExp.match(input);
        QString ville;
        if (match.hasMatch()) {
            ville = match.captured(1).trimmed();
        }

        QSqlQuery query;
        query.prepare("SELECT NOM FROM PARTENAIRES WHERE VILLE = :ville");
        query.bindValue(":ville", ville);

        if (query.exec()) {
            QStringList noms;
            while (query.next()) {
                noms << query.value(0).toString();
            }

            if (!noms.isEmpty()) {
                response = QString("Il y a %1 partenaires dans la ville %2 :<br>- %3")
                .arg(noms.size())
                    .arg(ville)
                    .arg(noms.join("<br>- "));
            } else {
                response = QString("Aucun partenaire trouvé dans la ville %1.").arg(ville);
            }
        } else {
            qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError();
            response = "Je n'ai pas pu obtenir la liste des partenaires dans cette ville pour l'instant.";
        }
    }


    else if (input.contains("quels sont les partenaires qui ont un contrat expiré", Qt::CaseInsensitive)) {
        QSqlQuery query;
        query.prepare("SELECT NOM FROM PARTENAIRES WHERE DATEFIN < CURRENT_DATE");

        if (query.exec()) {
            QStringList partenaires;
            while (query.next()) {
                partenaires << query.value(0).toString();
            }

            if (!partenaires.isEmpty()) {
                response = "Les partenaires dont le contrat est expiré sont :<br>- " + partenaires.join("<br>- ");
            } else {
                response = "Aucun partenaire n'a de contrat expiré.";
            }
        } else {
            qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError();
            response = "Je n'ai pas pu obtenir la liste des partenaires avec contrat expiré.";
        }
    }

    else if (input.contains("quels sont les partenaires qui ont un contrat en cours", Qt::CaseInsensitive)) {
        QSqlQuery query;
        query.prepare("SELECT NOM FROM PARTENAIRES WHERE DATEFIN >= CURRENT_DATE and DATEDEBUT <= CURRENT_DATE");

        if (query.exec()) {
            QStringList partenaires;
            while (query.next()) {
                partenaires << query.value(0).toString();
            }

            if (!partenaires.isEmpty()) {
                response = QString("Il y a %1 partenaires avec un contrat en cours :<br>- %2")
                .arg(partenaires.size())
                    .arg(partenaires.join("<br>- "));
            } else {
                response = "Aucun partenaire n'a de contrat en cours.";
            }
        } else {
            qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError();
            response = "Je n'ai pas pu obtenir la liste des partenaires avec contrat en cours.";
        }
    }


    else {
        // Réponse aléatoire si aucune correspondance

        response = " veuillez choisir l'un de ces questions :<br>"
                   "- quels sont les partenaires de type architecte ?<br>"
                   "- quels sont les partenaires de type fournisseur?<br>"
                   "- quels sont les partenaires dans la ville NomDeLaVille ?<br>"
                   "- quels sont les partenaires qui ont un contrat expiré ?<br>"
                   "- quels sont les partenaires qui ont un contrat en cours ?<br>";
    }

    ajouterMessageBot(response);
}



void MainWindow::addBotMessage(const QString &message)
{
    ui->conversationTextEdit->append("Bot: " + message);
}
void MainWindow::setupTableView()
{
    Partenaire p;
    // Créer un modèle pour afficher les données
    QStandardItemModel *model = p.afficher();

    // Créer un QSortFilterProxyModel
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);  // Lier le proxy au modèle

    // Activer le tri par colonne
    proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive); // Insensible à la casse
    ui->tableView1->setModel(proxyModel);

    // Activer la possibilité de trier les colonnes par clic
    ui->tableView1->setSortingEnabled(true);

    // Facultatif : spécifier le tri par défaut sur la première colonne (Nom par exemple)
    ui->tableView1->horizontalHeader()->setSortIndicator(0, Qt::AscendingOrder);
    ui->tableView1->horizontalHeader()->setSortIndicatorShown(true);
    ui->tableView1->setColumnWidth(10, 200);
    ui->tableView1->setItemDelegate(new ContratFinissantDelegate(this));
    ui->tableView1->setColumnHidden(9, true);
    ButtonDelegate *buttonDelegate = new ButtonDelegate(ui->tableView1);
    ui->tableView1->setItemDelegateForColumn(10, buttonDelegate);
    connect(buttonDelegate, &ButtonDelegate::editClicked, this, &MainWindow::onEditClicked);
    connect(buttonDelegate, &ButtonDelegate::deleteClicked, this, &MainWindow::onDeleteClicked);
}
void MainWindow::resizeEvent(QResizeEvent *event) {
    // Implémentez votre code ici pour gérer l'événement de redimensionnement
    QMainWindow::resizeEvent(event);  // Facultatif, si vous voulez appeler la méthode de la classe de base
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
        setupTableView();
        initialiserCompleter();
        afficherStatistiquesContrats();
        afficherStatistiquesPartenaires();

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



        // Mettre à jour le QTableWidget avec les nouvelles données

    } else {
        qDebug() << "❌ Erreur lors de l'ajout du partenaire.";

        // Affichage d'un message d'erreur si l'ajout échoue
        QMessageBox::critical(this, "Erreur", "L'ajout du partenaire a échoué !");
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
        QDate dateDebut = ui->DD->date();
        QDate dateFin = ui->FF->date();


        if (currentPartnerId <= 0) {
            QMessageBox::warning(this, "Erreur", "Aucun partenaire sélectionné !");
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
        if (dateDebut > dateFin) {
            QMessageBox::warning(this, "Erreur", "La date de fin doit être postérieure à la date de début !");
            return;
        }


        // Regex pour valider exemple@domaine.com ou exemple@domaine.tn
        QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.(com|tn)$)");

        if (!emailRegex.match(email).hasMatch()) {
            QMessageBox::warning(this, "Erreur", "L'email est invalide (ex: exemple@domaine.com ou exemple@domaine.tn) !");
            return;
        }

        // L'ID du partenaire à modifier, récupéré depuis le QLineEdit
        int partnerId = currentPartnerId;

        Partenaire partenaire;
        partenaire.setNom(nom);
        partenaire.setTypePartenaire(typePartenaire);
        partenaire.setAdresse(adresse);
        partenaire.setVille(ville);
        partenaire.setContactPrincipal(contactPrincipal);
        partenaire.setEmail(email);
        partenaire.setDateDebut(dateDebut);
        partenaire.setDateFin(dateFin);

        // Modifier les informations dans la base de données
        if (partenaire.modifier(partnerId)) {
            setupTableView();
            initialiserCompleter();
            afficherStatistiquesContrats();
            afficherStatistiquesPartenaires();

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
            currentPartnerId=-1;

        } else {
            qDebug() << "❌ Erreur lors de l'enregistrement des modifications.";
            QMessageBox::information(this, QObject::tr("Succès"),
                                     QObject::tr("modification hhhhhhhhhhhh."),
                                     QMessageBox::Cancel);
        }
    }


    void MainWindow::on_annuler_modification_clicked()
    {

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

    void MainWindow::afficherStatistiquesContrats()
    {
        // 1. Créer une instance de Partenaire
        Partenaire partenaire;

        // 2. Obtenir les différents compteurs
        int contratsEnCours = partenaire.nombreContratsEnCours();
        int contratsExpires = partenaire.nombreContratsExpires();
        int contratsFuturs = partenaire.nombreContratsFuturs();

        // 3. Créer le diagramme circulaire
        QPieSeries *series = new QPieSeries();

        // 4. Définir les couleurs spécifiques


        // 5. Ajouter systématiquement les trois catégories
        QPieSlice *sliceEnCours = series->append(QString("En cours (%1)").arg(contratsEnCours), contratsEnCours);
        sliceEnCours->setColor(Qt::green);
        sliceEnCours->setLabelVisible(true);
        sliceEnCours->setLabelColor(Qt::black);
        sliceEnCours->setLabelPosition(QPieSlice::LabelOutside);

        QPieSlice *sliceExpires = series->append(QString("Expirés (%1)").arg(contratsExpires), contratsExpires);
        sliceExpires->setColor(Qt::red);
        sliceExpires->setLabelVisible(true);
        sliceExpires->setLabelColor(Qt::black);
        sliceExpires->setLabelPosition(QPieSlice::LabelOutside);

        QPieSlice *sliceFuturs = series->append(QString("Futurs (%1)").arg(contratsFuturs), contratsFuturs);
        sliceFuturs->setColor(Qt::blue);
        sliceFuturs->setLabelVisible(true);
        sliceFuturs->setLabelColor(Qt::black);
        sliceFuturs->setLabelPosition(QPieSlice::LabelOutside);

        // 6. Configurer le graphique
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(QString("Statut des contrats - %1").arg(QDate::currentDate().toString("dd/MM/yyyy")));
        chart->setTitleFont(QFont("Arial", 12, QFont::Bold));
        chart->legend()->setAlignment(Qt::AlignRight);
        chart->legend()->setFont(QFont("Arial", 9));
        chart->setBackgroundVisible(false);

        // 7. Configurer les animations
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setAnimationDuration(1200);
        chart->setAnimationEasingCurve(QEasingCurve::OutBack);

        // 8. Créer la vue du graphique
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setStyleSheet("background: transparent; border: none;");

        // 9. Nettoyer le conteneur existant
        QLayout *oldLayout = ui->chartContainerContrats->layout();
        if (oldLayout) {
            QLayoutItem *item;
            while ((item = oldLayout->takeAt(0))) {
                if (item->widget()) delete item->widget();
                delete item;
            }
            delete oldLayout;
        }

        // 10. Configurer le nouveau layout
        QVBoxLayout *layout = new QVBoxLayout(ui->chartContainerContrats);
        layout->setContentsMargins(5, 5, 5, 5);
        layout->setSpacing(0);
        layout->addWidget(chartView);

        // 11. Appliquer le style au conteneur
        ui->chartContainerContrats->setStyleSheet(
            "background-color: white;"
            "border-radius: 10px;"
            "border: 1px solid #d0d0d0;"
            );

        // 12. Gestion des tailles
        chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        ui->chartContainerContrats->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }


        void MainWindow::on_recherche_clicked()
        {
            QString rechercheNom = ui->lineEditRechercheNom->text();


            QString queryStr = "SELECT * FROM PARTENAIRES WHERE NOM LIKE :rechercheNom";



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

            QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
            proxyModel->setSourceModel(model);  // Lier le proxy au modèle

            // Activer le tri par colonne
            proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive); // Insensible à la casse
            ui->tableView1->setModel(proxyModel);

            // Activer la possibilité de trier les colonnes par clic
            ui->tableView1->setSortingEnabled(true);

            }


        }


        void MainWindow::on_annuler_recherche_clicked()
        {


            setupTableView();

            ui->lineEditRechercheNom->clear();

        }
        void MainWindow::on_pushButtonExporter_clicked()
        {
            QString fileName = QFileDialog::getSaveFileName(
                this,
                "Enregistrer le fichier PDF",
                QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/export_partenaire.pdf",
                "Fichiers PDF (*.pdf);;Tous les fichiers (*)"
                );

            if (fileName.isEmpty())
                return;

            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(fileName);

            QTextDocument doc;
            QTextCursor cursor(&doc);

            QAbstractItemModel *model = ui->tableView1->model();

            if (!model || model->rowCount() == 0) {
                QMessageBox::warning(this, "Erreur", "Aucune donnée à exporter.");
                return;
            }

            // Titre
            cursor.insertHtml("<h2>Liste des partenaires</h2><br>");

            // Créer un tableau dans le document
            int rows = model->rowCount();
            int cols = model->columnCount();

            QTextTableFormat tableFormat;
            tableFormat.setBorder(1);
            tableFormat.setCellPadding(4);
            tableFormat.setCellSpacing(0);
            QTextTable *table = cursor.insertTable(rows + 1, 3, tableFormat); // 3 colonnes : Nom, Type, Email

            // Entêtes
            table->cellAt(0, 0).firstCursorPosition().insertText("Nom");
            table->cellAt(0, 1).firstCursorPosition().insertText("TypePartenaire");
            table->cellAt(0, 2).firstCursorPosition().insertText("Email");

            for (int row = 0; row < rows; ++row) {
                table->cellAt(row + 1, 0).firstCursorPosition().insertText(model->data(model->index(row, 1)).toString());
                table->cellAt(row + 1, 1).firstCursorPosition().insertText(model->data(model->index(row, 2)).toString());
                table->cellAt(row + 1, 2).firstCursorPosition().insertText(model->data(model->index(row, 6)).toString());
            }

            doc.print(&printer);

            QMessageBox::information(this, "Succès", "Export PDF réussi ! Fichier : " + fileName);
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

void MainWindow::afficherStatistiquesPartenaires()
        {
            // 1. Définir tous les types de partenaires attendus
            QStringList typesPartenaires = {"Architecte", "Fournisseur"}; // Ajoutez d'autres types si nécessaire

            // 2. Préparer la structure pour stocker les comptages
            QMap<QString, int> compteurs;
            foreach (const QString &type, typesPartenaires) {
                compteurs[type] = 0; // Initialiser à 0
            }

            // 3. Récupérer les données existantes depuis la base
            QSqlQuery query("SELECT TYPEPARTENAIRE, COUNT(*) AS NOMBRE FROM PARTENAIRES GROUP BY TYPEPARTENAIRE");
            while (query.next()) {
                QString type = query.value("TYPEPARTENAIRE").toString();
                compteurs[type] = query.value("NOMBRE").toInt();
            }

            // 4. Création du diagramme circulaire
            QPieSeries *series = new QPieSeries();

            // Couleurs prédéfinies (bleu et vert en priorité)
            QList<QColor> couleurs =  {Qt::blue, Qt::green, Qt::red, Qt::yellow, Qt::cyan, Qt::magenta};

            // 5. Ajouter chaque type au graphique
            for (int i = 0; i < typesPartenaires.size(); ++i) {
                QString type = typesPartenaires[i];
                int nombre = compteurs[type];

                // Créer la tranche même si nombre = 0
                QString libelle = QString("%1 (%2)").arg(type).arg(nombre);
                QPieSlice *slice = series->append(libelle, nombre);

                // Configurer l'apparence
                slice->setLabelVisible(true);
                slice->setLabelColor(Qt::black);
                slice->setLabelPosition(QPieSlice::LabelOutside);

                // Attribuer une couleur
                if (i < couleurs.size()) {
                    slice->setColor(couleurs[i]);
                } else {
                    // Couleur par défaut si on dépasse la liste
                    slice->setColor(QColor::fromHsl(rand() % 360, 150 + rand() % 106, 150 + rand() % 106));
                }
            }

            // 6. Configuration du graphique
            QChart *chart = new QChart();
            chart->addSeries(series);
            chart->setTitle("Répartition des partenaires par type");
            chart->setTitleFont(QFont("Arial", 12, QFont::Bold));
            chart->legend()->setAlignment(Qt::AlignRight);
            chart->legend()->setFont(QFont("Arial", 9));
            chart->setBackgroundVisible(false);

            // Animations
            chart->setAnimationOptions(QChart::SeriesAnimations);
            chart->setAnimationDuration(1000);
            chart->setAnimationEasingCurve(QEasingCurve::OutQuart);

            // 7. Configuration de la vue
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            chartView->setStyleSheet("background: transparent;");

            // 8. Nettoyage du conteneur existant
            QLayout *oldLayout = ui->chartContainer->layout();
            if (oldLayout) {
                QLayoutItem *item;
                while ((item = oldLayout->takeAt(0))) {
                    if (item->widget()) {
                        delete item->widget();
                    }
                    delete item;
                }
                delete oldLayout;
            }

            // 9. Mise en place du nouveau layout
            QVBoxLayout *layout = new QVBoxLayout(ui->chartContainer);
            layout->setContentsMargins(5, 5, 5, 5);
            layout->setSpacing(0);
            layout->addWidget(chartView);

            // 10. Style du conteneur
            ui->chartContainer->setStyleSheet(
                "background-color: white;"
                "border-radius: 10px;"
                "border: 1px solid #d0d0d0;"
                );

            // 11. Gestion des tailles
            chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            ui->chartContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        }





        void MainWindow::onEditClicked(int row) {
            QModelIndex index = ui->tableView1->model()->index(row, 0); // Colonne ID
            int partnerId = ui->tableView1->model()->data(index).toInt();

               currentPartnerId = partnerId;

            Partenaire partenaire;
            if (partenaire.recupererParId(partnerId)) {
                ui->nomInput->setText(partenaire.getNom());
                QString typePartenaire = partenaire.getTypePartenaire();
                if(typePartenaire == "Architecte") {
                    ui->typePartenaireInput->setCurrentIndex(1);
                } else {
                    ui->typePartenaireInput->setCurrentIndex(2);
                }
                ui->adresseInput->setText(partenaire.getAdresse());
                ui->villeInput->setText(partenaire.getVille());
                ui->contactPrincipalInput->setText(partenaire.getContactPrincipal());
                ui->emailInput->setText(partenaire.getEmail());
                ui->DD->setDate(partenaire.getDateDebut());
                ui->FF->setDate(partenaire.getDateFin());

                // Activez l'onglet de modification si nécessaire
                ui->tabWidget->setCurrentIndex(2); // Supposant que l'onglet 2 est pour les modifications
            }
        }

        void MainWindow::onDeleteClicked(int row) {
            QModelIndex index = ui->tableView1->model()->index(row, 0); // Colonne ID
            int partnerId = ui->tableView1->model()->data(index).toInt();

            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer ce partenaire?",
                                          QMessageBox::Yes|QMessageBox::No);
            if (reply == QMessageBox::Yes) {
                Partenaire p;
                if (p.supprimer(partnerId)) {
                    // Rafraîchir la table
                    setupTableView();
                    initialiserCompleter();
                    QMessageBox::information(this, "Succès", "Partenaire supprimé avec succès!");
                    afficherStatistiquesContrats();
                    afficherStatistiquesPartenaires();
                } else {
                    QMessageBox::warning(this, "Erreur", "Échec de la suppression!");
                }
            }
        }













        void MainWindow::on_sendButton_clicked()
        {
            QString userInput = ui->inputLineEdit->text();

            ajouterMessageUtilisateur(userInput);     // ✅ Affiche le message utilisateur
            processUserInput(userInput);              // ✅ Ne doit être appelé qu’une seule fois !

            ui->inputLineEdit->clear();
        }


        void MainWindow::on_nouvelle_disccusion_clicked()
        {
            ui->conversationTextEdit->clear();
            ajouterMessageBot("👋 Bonjour ! Je suis votre assistant intelligent. Posez-moi n'importe quelle question concernant les partenaires !");
            ajouterMessageBot(" Voici quelques questions que vous pouvez me poser :<br>"
                              "- quels sont les partenaires de type architecte ?<br>"
                              "- quels sont les partenaires de type fournisseur?<br>"
                              "- quels sont les partenaires dans la ville NomDeLaVille ?<br>"
                              "- quels sont les partenaires qui ont un contrat expiré ?<br>"
                              "- quels sont les partenaires qui ont un contrat en cours ?<br>"
                              );
            // Revenir au début du texte
            QTextCursor cursor = ui->conversationTextEdit->textCursor();
            cursor.movePosition(QTextCursor::Start);
            ui->conversationTextEdit->setTextCursor(cursor);

        }

        void MainWindow::readSerialData() {
            while (serialPort.canReadLine()) {
                QString receivedData = QString::fromUtf8(serialPort.readLine()).trimmed(); // Renommez la variable

                if (receivedData.startsWith("ID_COMPLET:")) {  // Utilisez le nouveau nom
                    QString id = receivedData.mid(11);

                    verifierPartenaire(id);


                }
            }
        }
        // Modifiez verifierPartenaire()
        void MainWindow::verifierPartenaire(const QString &id) {
            QSqlQuery query;

            // CORRECTION: colonne ID au lieu de IDPARTENAIRE
            query.prepare("SELECT DATEDEBUT, DATEFIN FROM PARTENAIRES WHERE ID = ?");
            query.addBindValue(id);

            // Vérifie si la requête SQL s’exécute
            if (!query.exec()) {
                qDebug() << "Erreur SQL:" << query.lastError().text();
                sendToArduino("INCONNU");
                return;
            }

            // Vérifie si l’ID existe
            if (!query.next()) {
                qDebug() << "Aucun partenaire trouvé avec l'ID:" << id;
                sendToArduino("INCONNU");
                return;
            }

            // Récupération des dates
            QDate dateDebut = query.value(0).toDate();
            QDate dateFin = query.value(1).toDate();
            QDate today = QDate::currentDate();

            // Log pour le débogage
            qDebug() << "ID:" << id << " - Début:" << dateDebut << ", Fin:" << dateFin;

            // Vérification de l’état du contrat
            if (today < dateDebut) {
                sendToArduino("CONTRAT_NON_COMMENCE");
            } else if (today > dateFin) {
                sendToArduino("CONTRAT_EXPIRE");
            } else {
                sendToArduino("CONTRAT_EN_COURS");
            }
        }



        // Nouvelle méthode helper
        void MainWindow::sendToArduino(const QString &message) {
            if (serialPort.isOpen()) {
                qDebug() << "Envoi à Arduino:" << message;
                serialPort.write((message + "\n").toUtf8());
                serialPort.waitForBytesWritten(1000);
            } else {
                qDebug() << "Port série fermé !";
            }
        }
        void MainWindow::setupSerialPort()
        {
            // 1. Configuration du port
            serialPort.setPortName("COM3"); // À adapter selon votre système
            serialPort.setBaudRate(QSerialPort::Baud9600);
            serialPort.setDataBits(QSerialPort::Data8);
            serialPort.setParity(QSerialPort::NoParity);
            serialPort.setStopBits(QSerialPort::OneStop);
            serialPort.setFlowControl(QSerialPort::NoFlowControl);

            // 2. Ouverture du port
            if (!serialPort.open(QIODevice::ReadWrite)) {
                QString errorMsg = "Erreur port série: " + serialPort.errorString();
                qDebug() << errorMsg;
                QMessageBox::critical(this, "Erreur", errorMsg);
                return;
            }

            // 3. Connexion du signal readyRead
            connect(&serialPort, &QSerialPort::readyRead,
                    this, &MainWindow::readSerialData);

            // 4. Vérification matérielle
            QTimer::singleShot(1000, [this]() {
                if (serialPort.isOpen()) {
                    qDebug() << "Port série ouvert avec succès sur" << serialPort.portName();
                    QMessageBox::critical(this, "Erreur", "Port série ouvert avec succès su");
                    serialPort.write("SYSTEM_READY\n"); // Signal de test
                }
            });
        }


        //partie mtaa slimm--------------------------------------------------------------------------------------------------------
        bool ascending = true; // declare this in your MainWindow class as a private member

        void MainWindow::on_btn_tri_clicked()
        {
            int salaireColumn = 4;
            ui->tableWidget->sortItems(salaireColumn, ascending ? Qt::AscendingOrder : Qt::DescendingOrder);
            ascending = !ascending; // toggle for next click
        }
        void MainWindow::on_btn_reset_recherche_clicked()
        {
            for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
                ui->tableWidget->setRowHidden(row, false);
            }
            ui->le_recherche_nom->clear();
        }

        void MainWindow::on_btn_recherche_clicked()
        {
            QString searchText = ui->le_recherche_nom->text().toLower();
            int nomColumn = 1;  // Adjust if your "nom" is in another column

            for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
                QTableWidgetItem *item = ui->tableWidget->item(row, nomColumn);
                if (item) {
                    QString nomText = item->text().toLower();
                    bool match = nomText.contains(searchText);
                    ui->tableWidget->setRowHidden(row, !match);
                }
            }
        }


        void MainWindow::on_pdf_clicked()
        {
            emp.exporterPDF(ui->tableWidget);
        }
        void MainWindow::on_btn_stats_clicked()
        {
            QMap<QString, int> statutCounts;

            int rowCount = ui->tableWidget->rowCount();
            int statutColumn = 5;  // Replace with the correct column index for "statut"

            for (int row = 0; row < rowCount; ++row) {
                QTableWidgetItem *item = ui->tableWidget->item(row, statutColumn);
                if (item) {
                    QString statut = item->text();
                    statutCounts[statut]++;
                }
            }

            QString statsText = "Statistiques des statuts:\n\n";
            for (auto it = statutCounts.begin(); it != statutCounts.end(); ++it) {
                statsText += QString("%1: %2\n").arg(it.key()).arg(it.value());
            }

            QMessageBox::information(this, "Statistiques", statsText);
        }

        void MainWindow::showEvent(QShowEvent *event)
        {
            QMainWindow::showEvent(event);
            emp.afficher(ui->tableWidget);  // Load data when window is shown
        }


        // Member object
        Employe emp;

        void MainWindow::on_btn_add_clicked() {
            int id = ui->le_id->text().toInt();
            QString nom = ui->le_nom->text();
            QString prenom = ui->le_prenom->text();
            QString poste = ui->le_poste->text();
            double salaire = ui->le_salaire->text().toDouble();
            QString statut = ui->statut->text();
            QString email = ui->le_email->text();
            QString numero = ui->le_numero->text();

            // Assuming you have a password field (e.g., ui->le_pass), you can do something like:
            QString pass = ui->le_pass->text();  // Declare and initialize pass
            emp.afficher(ui->tableWidget);
            if (emp.ajouter(id, nom, prenom, poste, salaire, statut, email, pass, numero)) {
                emp.afficher(ui->tableWidget);
            }
        }

        // On Delete Button Click
        void MainWindow::on_btn_delete_clicked() {
            int id = ui->le_id->text().toInt();
            if (emp.supprimer(id)) {
                emp.afficher(ui->tableWidget);
            }
        }

        // On Refresh Button Click
        void MainWindow::on_btn_refresh_clicked() {
            emp.afficher(ui->tableWidget);
        }




        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////hajjouni
        void MainWindow::on_pushButton_ajout_clicked()
        {
            ui->stackedWidget_2->setCurrentIndex(1);
        }


        void MainWindow::on_pushButton_clicked()
        {
            QString nomchantier = ui->nom->text().trimmed();
            QString adresse = ui->adresse->text().trimmed();


            QDate datedebut = ui->datedebut->date();


            QDate datefinprevu = ui->datefin->date(); // Will be replaced by prediction
            QDate datefinreelle = ui->datefinr->date();
            QString statut = ui->statut_2->text().trimmed();

            bool ok1, ok2, ok3;
            double budgetinitial = ui->budget->text().toDouble(&ok1);
            double coutreel = ui->coutr->text().toDouble(&ok2);
            int progression = ui->prog->text().toInt(&ok3);
            double temperature =ui->temp->text().toDouble();

            if (nomchantier.isEmpty() || adresse.isEmpty() || statut.isEmpty()) {
                QMessageBox::warning(this, "Erreur de saisie", "Veuillez remplir tous les champs obligatoires.");
                return;
            }

            if (!ok1 || budgetinitial < 0) {
                QMessageBox::warning(this, "Erreur de saisie", "Le budget initial doit être un nombre positif.");
                return;
            }

            if (!ok2 || coutreel < 0) {
                QMessageBox::warning(this, "Erreur de saisie", "Le coût réel doit être un nombre positif.");
                return;
            }

            if (!ok3 || progression < 0 || progression > 100) {
                QMessageBox::warning(this, "Erreur de saisie", "La progression doit être comprise entre 0 et 100.");
                return;
            }

            QString statutLower = statut.toLower();
            if (statutLower != "terminé" && statutLower != "en cours" && statutLower != "en retard") {
                QMessageBox::warning(this, "Erreur de saisie", "Le statut doit être 'terminé', 'en cours' ou 'en retard'.");
                return;
            }

            QDate dateParDefaut(2000, 1, 1);

            if (statutLower == "terminé") {
                if (datefinreelle == dateParDefaut) {
                    QMessageBox::warning(this, "Erreur de saisie", "Veuillez renseigner la date de fin réelle pour un chantier terminé.");
                    return;
                }
                if (datefinreelle < datedebut) {
                    QMessageBox::warning(this, "Erreur de saisie", "La date de fin réelle doit être après la date de début.");
                    return;
                }
            }

            if ((statutLower == "en cours" || statutLower == "en retard" ) && datefinreelle != dateParDefaut) {
                QMessageBox::warning(this, "Erreur de saisie", "La date de fin réelle doit être vide si le chantier n'est pas terminé.");
                return;
            }

            // ⏱️ Prédiction automatique de la date de fin prévue
            QString pythonScript = QCoreApplication::applicationDirPath() + "/predict_duration.py";
            QString pythonPath = "C:/Users/hajjo/AppData/Local/Programs/Python/Python312/python.exe"; // à adapter si besoin

            if (!QFile::exists(pythonScript)) {
                QMessageBox::critical(this, "Erreur", "Script Python introuvable : " + pythonScript);
                return;
            }

            QStringList arguments;
            arguments << pythonScript
                      << QString::number(budgetinitial)
                      << QString::number(progression)
                      << statutLower;

            QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
            env.remove("PYTHONHOME");
            env.remove("PYTHONPATH");

            QProcess process;
            process.setProcessEnvironment(env);
            process.setWorkingDirectory(QCoreApplication::applicationDirPath());
            process.start(pythonPath, arguments);

            if (!process.waitForStarted() || !process.waitForFinished(10000)) {
                QMessageBox::warning(this, "Erreur", "Le script de prédiction a échoué.");
                return;
            }

            QString output = QString::fromUtf8(process.readAllStandardOutput()).trimmed();
            QString error = QString::fromUtf8(process.readAllStandardError()).trimmed();

            if (!error.isEmpty()) {
                QMessageBox::critical(this, "Erreur Python", error);
                return;
            }

            QStringList result = output.split("|");
            if (result.size() == 2) {
                int jours = result[0].trimmed().toInt();
                double confiance = result[1].trimmed().toDouble();
                QDate estimation = QDate::currentDate().addDays(jours);
                datefinprevu = estimation;

                QMessageBox::information(this, "📊 Prédiction IA",
                                         QString("📅 Fin estimée du chantier : %1\n"
                                                 "🔍 Confiance du modèle : %2%")
                                             .arg(estimation.toString("dd/MM/yyyy"))
                                             .arg(confiance * 100.0, 0, 'f', 2));

            } else {
                QMessageBox::warning(this, "Erreur", "Réponse inattendue du script Python :\n" + output);
                return;
            }

            // Création de l'objet chantier avec la date de fin prédite
            chantier c(0, nomchantier, adresse, datedebut, datefinprevu, datefinreelle, statut, budgetinitial, coutreel, progression,temperature);

            if (c.ajouter()) {
                ui->tableView->setModel(c.afficher());
                button_hajjouni();

                QVector<QString> alertes = c.verifierAlertes();
                if (!alertes.isEmpty()) {
                    QString msg = "🔔 Alerte(s) détectée(s) :\n\n" + alertes.join("\n");
                    QMessageBox::warning(this, "Alertes chantier", msg);
                }

                // Reset form and change page
                ui->nom->clear();
                ui->adresse->clear();
                ui->datedebut->setDate(QDate::currentDate());
                ui->datefin->setDate(QDate::currentDate());
                ui->datefinr->setDate(QDate(2000, 1, 1));
                ui->statut_2->clear();
                ui->budget->clear();
                ui->coutr->clear();
                ui->prog->clear();
                ui->temp->clear();

                ui->stackedWidget_2->setCurrentIndex(0);

                QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");
            } else {
                QMessageBox::warning(this, "Erreur", "Échec de l'ajout du chantier !");
            }
        }





        void MainWindow::button_hajjouni()
        {

            // Add buttons after setting the model
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
                    chantier c;

                    c.set_id(ui->tableView->model()->index(row, 0).data().toInt());
                    c.set_nomchantier(ui->tableView->model()->index(row, 1).data().toString());
                    c.set_adresse(ui->tableView->model()->index(row, 2).data().toString());

                    QString dateString = ui->tableView->model()->index(row, 3).data().toString();
                    QStringList parts = dateString.split("T"); // Split at "T" to separate date and time parts
                    QString datePart = parts[0]; // Extract the date part
                    QDate date = QDate::fromString(datePart, "yyyy-MM-dd");
                    if (date.isValid()) {
                        qDebug() << "Parsed date:" << date;
                        c.set_datedebut(date);
                    } else {
                        qDebug() << "Error: Invalid date format!";
                        // You may need to handle this error case appropriately
                    }

                    QString dateString1 = ui->tableView->model()->index(row, 4).data().toString();
                    QStringList parts1 = dateString1.split("T"); // Split at "T" to separate date and time parts
                    QString datePart1 = parts1[0]; // Extract the date part
                    QDate date1 = QDate::fromString(datePart1, "yyyy-MM-dd");
                    if (date1.isValid()) {
                        qDebug() << "Parsed date:" << date1;
                        c.set_datefinprevu(date1);
                    } else {
                        qDebug() << "Error: Invalid date format!";
                        // You may need to handle this error case appropriately
                    }

                    QString dateString2 = ui->tableView->model()->index(row, 5).data().toString();
                    QStringList parts2 = dateString2.split("T"); // Split at "T" to separate date and time parts
                    QString datePart2 = parts2[0]; // Extract the date part
                    QDate date2 = QDate::fromString(datePart2, "yyyy-MM-dd");
                    if (date2.isValid()) {
                        qDebug() << "Parsed date:" << date2;
                        c.set_datefinreelle(date2);
                    } else {
                        qDebug() << "Error: Invalid date format!";
                        // You may need to handle this error case appropriately
                    }
                    c.set_statut(ui->tableView->model()->index(row, 6).data().toString());
                    c.set_budgetinitial(ui->tableView->model()->index(row, 7).data().toFloat());
                    c.set_coutreel(ui->tableView->model()->index(row, 8).data().toFloat());
                    c.set_progression(ui->tableView->model()->index(row, 9).data().toInt());
                    c.set_temperature(ui->tableView->model()->index(row, 10).data().toFloat());

                    on_modifier_chantier_clicked(c);
                });

                connect(delete_button, &QPushButton::clicked, [this, row]() {
                    on_delete_chantier_clicked(ui->tableView->model()->index(row, 0).data().toInt());
                });

                ui->tableView->setIndexWidget(ui->tableView->model()->index(row, 11), update_button);
                ui->tableView->setIndexWidget(ui->tableView->model()->index(row, 12), delete_button);
            }
        }


        void MainWindow::on_modifier_chantier_clicked(chantier c)
        {


            // Set values in UI
            ui->id1->setText(QString::number(c.get_id()));
            ui->id1->setHidden(true);
            ui->stackedWidget_2->setCurrentIndex(2);
            ui->nom1->setText(c.get_nomchantier());
            ui->adresse1->setText(c.get_adresse());

            QDate date = c.get_datedebut();
            QString datestring = date.toString("yyyy-MM-dd");
            ui->dated1->setDate(QDate::fromString(datestring, "yyyy-MM-dd"));
            qDebug() << "Date fin réelle:" << datestring;

            ui->datef1->setDate(c.get_datefinprevu());
            ui->datefr1->setDate(c.get_datefinreelle());

            ui->statut1->setText(c.get_statut());
            ui->budget1->setText(QString::number(c.get_budgetinitial()));
            ui->cout1->setText(QString::number(c.get_coutreel()));
            ui->prog1->setValue(c.get_progression());
            ui->temp1->setText(QString::number(c.get_temperature()));
            // Switch to Modification Page (Page 2)
            ui->stackedWidget_2->setCurrentIndex(2);
        }





        void MainWindow::on_delete_chantier_clicked(int id){
            chantier ch = c.getchantierById(id);
            if (ch.get_id()==-1){
                QMessageBox::critical(this, "Error", "This ID doesn't exist!");
            }else{
                bool test=ch.supprimer(id);

                if (test){
                    ui->tableView->setModel(ch.afficher());
                    button_hajjouni();

                    QMessageBox::information(nullptr, QObject::tr("DONE"),
                                             QObject::tr("An event's been deleted.\n"
                                                         "Click Cancel to exit."), QMessageBox::Cancel);

                }else
                    QMessageBox::critical(nullptr, QObject::tr("FAIL"),
                                          QObject::tr("Error.\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
                ui->stackedWidget_2->setCurrentIndex(0);}

        }


        void MainWindow::on_pushButton_3_clicked()
        {
            // ✅ Récupération de l'ID du chantier en modification

            int id = ui->id1->text().toInt();
            // ✅ Récupération des données depuis l'interface
            QString nomchantier = ui->nom1->text().trimmed();
            QString adresse = ui->adresse1->text().trimmed();
            QDate datedebut = ui->dated1->date();
            QDate datefinprevu = ui->datef1->date();
            QDate datefinreelle = ui->datefr1->date();
            QString statut = ui->statut1->text().trimmed();
            QString statutLower = statut.toLower();

            // ✅ Validation des champs numériques
            bool ok1, ok2;
            double budgetinitial = ui->budget1->text().toDouble(&ok1);
            double coutreel = ui->cout1->text().toDouble(&ok2);
            int progression = ui->prog1->value();
            double temperature = ui->temp1->text().toDouble();

            // ✅ Validation des champs obligatoires
            if (nomchantier.isEmpty() || adresse.isEmpty() || statut.isEmpty()) {
                QMessageBox::warning(this, "Erreur de saisie", "Veuillez remplir tous les champs obligatoires.");
                return;
            }

            if (!ok1 || budgetinitial < 0) {
                QMessageBox::warning(this, "Erreur de saisie", "Le budget initial doit être un nombre positif.");
                return;
            }

            if (!ok2 || coutreel < 0) {
                QMessageBox::warning(this, "Erreur de saisie", "Le coût réel doit être un nombre positif.");
                return;
            }

            if (progression < 0 || progression > 101) {
                QMessageBox::warning(this, "Erreur de saisie", "La progression doit être comprise entre 0 et 100.");
                return;
            }


            // ✅ Statut : contrôle strict
            if (statutLower != "terminé" && statutLower != "en cours" && statutLower != "en retard") {
                QMessageBox::warning(this, "Erreur de saisie", "Le statut doit être 'terminé', 'en cours' ou 'en retard'.");
                return;
            }

            // ✅ Cas spéciaux selon le statut
            QDate dateParDefaut(2000, 1, 1);

            if (statutLower == "terminé") {
                if (datefinreelle == dateParDefaut) {
                    QMessageBox::warning(this, "Erreur de saisie", "Veuillez renseigner la date de fin réelle pour un chantier terminé.");
                    return;
                }
                if (datefinreelle < datedebut) {
                    QMessageBox::warning(this, "Erreur de saisie", "La date de fin réelle doit être après la date de début.");
                    return;
                }
            }

            if ((statutLower == "en cours" || statutLower == "en retard") && datefinreelle != dateParDefaut) {
                QMessageBox::warning(this, "Erreur de saisie", "La date de fin réelle doit être vide si le chantier n'est pas terminé.");
                return;
            }





            // 🔮 PREDICTION IA DE LA DATE DE FIN PREVUE
            QString pythonScript = QCoreApplication::applicationDirPath() + "/predict_duration.py";
            QString pythonPath = "C:/Users/hajjo/AppData/Local/Programs/Python/Python312/python.exe"; // adapter si nécessaire

            if (!QFile::exists(pythonScript)) {
                QMessageBox::critical(this, "Erreur", "Script Python introuvable : " + pythonScript);
                return;
            }

            QStringList arguments;
            arguments << pythonScript
                      << QString::number(budgetinitial)
                      << QString::number(progression)
                      << statutLower;

            QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
            env.remove("PYTHONHOME");
            env.remove("PYTHONPATH");

            QProcess process;
            process.setProcessEnvironment(env);
            process.setWorkingDirectory(QCoreApplication::applicationDirPath());
            process.start(pythonPath, arguments);

            if (!process.waitForStarted() || !process.waitForFinished(10000)) {
                QMessageBox::warning(this, "Erreur", "Le script de prédiction a échoué.");
                return;
            }

            QString output = QString::fromUtf8(process.readAllStandardOutput()).trimmed();
            QString error = QString::fromUtf8(process.readAllStandardError()).trimmed();

            if (!error.isEmpty()) {
                QMessageBox::critical(this, "Erreur Python", error);
                return;
            }

            QStringList result = output.split("|");
            if (result.size() == 2) {
                int jours = result[0].trimmed().toInt();
                double confiance = result[1].trimmed().toDouble();
                QDate estimation = QDate::currentDate().addDays(jours);
                datefinprevu = estimation;

                QMessageBox::information(this, "📊 Prédiction IA",
                                         QString("📅 Fin estimée du chantier : %1\n"
                                                 "🔍 Confiance du modèle : %2%")
                                             .arg(estimation.toString("dd/MM/yyyy"))
                                             .arg(confiance * 100.0, 0, 'f', 2));

            } else {
                QMessageBox::warning(this, "Erreur", "Réponse inattendue du script Python :\n" + output);
                return;
            }








            // ✅ Enregistrement des modifications
            bool test = c.modifier(id, nomchantier, adresse, datedebut, datefinprevu,
                                   datefinreelle, statut, budgetinitial, coutreel, progression,temperature);

            if (test) {
                QMessageBox::information(this, "Succès", "Chantier mis à jour avec succès !");
                QSqlQueryModel *newModel = c.afficher();
                ui->tableView->setModel(newModel);
                button_hajjouni();

                chantier chantierModifie(id, nomchantier, adresse, datedebut, datefinprevu,
                                         datefinreelle, statut, budgetinitial, coutreel, progression,temperature);
                QVector<QString> alertes = chantierModifie.verifierAlertes();

                if (!alertes.isEmpty()) {
                    QString msg = "⚠️ Alerte(s) détectée(s) :\n\n" + alertes.join("\n");
                    QMessageBox::warning(this, "Alertes chantier", msg);
                }


                ui->stackedWidget_2->setCurrentIndex(0);
            } else {
                QMessageBox::critical(this, "Erreur", "Échec de la mise à jour");
            }
        }



        void MainWindow::on_pushButton_8_clicked()
        {
            ui->stackedWidget_2->setCurrentIndex(0);
        }


        void MainWindow::on_pushButton_2_clicked()
        {
            ui->stackedWidget_2->setCurrentIndex(0);
        }





        void MainWindow::on_recherche_input_textChanged(const QString &arg1)
        {
            QSqlQueryModel *searchModel = c.search(arg1);

            if (searchModel!=nullptr) {
                ui->tableView->setModel(searchModel);
                button_hajjouni();
            } else{
                QMessageBox::critical(this, "Error", "Search failed. No results found.");
            }
        }


        void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
        {
            if (arg1=="id"){
                ui->tableView->setModel(c.sort("id"));
                button_hajjouni();
            }else if (arg1=="Nom du chantier"){
                ui->tableView->setModel(c.sort("nomchantier"));
                button_hajjouni();
            }else if (arg1=="Adresse du chantier"){
                ui->tableView->setModel(c.sort("adresse"));
                button_hajjouni();
            }else if (arg1=="Date debut"){
                ui->tableView->setModel(c.sort("datedebut"));
                button_hajjouni();
            }else if (arg1=="date fin relle"){
                ui->tableView->setModel(c.sort("datefinreelle"));
                button_hajjouni();
            }else if (arg1=="Budget"){
                ui->tableView->setModel(c.sort("budgetinitial"));
                button_hajjouni();
            }else if (arg1=="Cout reel"){
                ui->tableView->setModel(c.sort("coutreel"));
                button_hajjouni();
            }else if (arg1=="Progression"){
                ui->tableView->setModel(c.sort("progression"));
                button_hajjouni();
            }
        }


        void MainWindow::on_pushButton_5_clicked()
        {
            if (c.exportToPdf()==true) {
                QMessageBox::information(this, "Done", "PDF exported successfully!");
            } else {
                QMessageBox::critical(this, "Error", "Failed to export PDF!");
            }
        }


        void MainWindow::on_pushButton_13_clicked()
        {
            ui->stackedWidget_2->setCurrentIndex(0);

        }


        void MainWindow::on_pushButton_6_clicked()
        {
            ui->stackedWidget_2->setCurrentIndex(3);
            chantier myChantier;
            QSqlQueryModel *model = myChantier.getEventStatistics();
            qreal tot = 0;
            QMap<QString, qreal> typeCounts;

            if (model) {
                // [Keep your existing data processing code...]
                // Calculate totals and populate typeCounts
                for (int i = 0; i < model->rowCount(); ++i) {
                    QString gouvernorat = model->data(model->index(i, 0)).toString();
                    qreal count = model->data(model->index(i, 1)).toDouble();
                    typeCounts.insert(gouvernorat, count);
                    tot += count; // Accumulate total count
                }
                // Create series with enhanced styling
                QPieSeries *seriesC = new QPieSeries();
                seriesC->setPieSize(0.7);  // Make pie smaller to fit legend
                seriesC->setLabelsVisible(true);
                seriesC->setLabelsPosition(QPieSlice::LabelOutside);

                QMapIterator<QString, qreal> it(typeCounts);
                while (it.hasNext()) {
                    it.next();
                    qreal percentage = (it.value() / tot) * 100;
                    QString label = it.key() + " (" + QString::number(percentage, 'f', 2) + "%)";
                    QPieSlice *slice = seriesC->append(label, it.value());

                    // Custom slice styling
                    slice->setLabelVisible(true);
                    slice->setLabelArmLengthFactor(0.2);
                    slice->setLabelFont(QFont("Arial", 8, QFont::Bold));
                    slice->setLabelColor(Qt::white);
                    slice->setBorderWidth(2);
                }

                // Enhanced chart styling
                QChart *chartC = new QChart();
                chartC->addSeries(seriesC);
                chartC->setTitle("Statistique des Événements");
                chartC->setTitleFont(QFont("Arial", 12, QFont::Bold));
                chartC->setTitleBrush(QBrush(Qt::white));
                chartC->setTheme(QChart::ChartThemeDark);

                // Background styling
                QLinearGradient backgroundGradient;
                backgroundGradient.setStart(QPointF(0, 0));
                backgroundGradient.setFinalStop(QPointF(0, 1));
                backgroundGradient.setColorAt(0.0, QRgb(0x2E86C1));  // Blue
                backgroundGradient.setColorAt(1.0, QRgb(0x0F3460));  // Dark blue
                backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
                chartC->setBackgroundBrush(backgroundGradient);

                // Legend styling
                chartC->legend()->setVisible(true);
                chartC->legend()->setAlignment(Qt::AlignRight);
                chartC->legend()->setFont(QFont("Arial", 9));
                chartC->legend()->setLabelColor(Qt::white);
                chartC->legend()->setMarkerShape(QLegend::MarkerShapeCircle);

                // Chart view setup
                QChartView *chartViewC = new QChartView(chartC);
                chartViewC->setRenderHint(QPainter::Antialiasing);
                chartViewC->setFixedSize(750, 750);

                // Scene setup
                QGraphicsScene *scene = new QGraphicsScene();
                scene->setBackgroundBrush(QBrush(QColor(0x0F3460)));  // Dark blue background
                scene->addWidget(chartViewC);

                // Final display
                QPixmap pixmap(scene->sceneRect().size().toSize());
                pixmap.fill(Qt::transparent);
                QPainter painter(&pixmap);
                scene->render(&painter);
                ui->label_stat->setPixmap(pixmap);
                ui->label_stat->setAlignment(Qt::AlignCenter);

                delete model;
            }
        }




        void MainWindow::detecterChantiersEnRetard()
        {
            QAbstractItemModel* model = ui->tableView->model();
            int rowCount = model->rowCount();
            QDate aujourdHui = QDate::currentDate();

            for (int row = 0; row < rowCount; ++row) {
                QDate dateFinPrevu = model->index(row, 4).data().toDate();   // Colonne DATEFINPREVU
                int progression = model->index(row, 9).data().toInt();       // Colonne PROGRESSION

                if (dateFinPrevu < aujourdHui && progression < 100) {
                    // Marquer comme en retard visuellement
                    for (int col = 0; col < model->columnCount(); ++col) {
                        ui->tableView->model()->setData(
                            model->index(row, col),
                            QBrush(Qt::red),
                            Qt::ForegroundRole
                            );
                    }
                }
            }
        }




        void MainWindow::on_pushButton_ajout_2_clicked()
        {
            // Récupération du chantier sélectionné depuis la table
            QModelIndex index = ui->tableView->currentIndex();
            if (!index.isValid()) {
                QMessageBox::warning(this, "Aucun chantier", "Veuillez sélectionner un chantier.");
                return;
            }

            int row = index.row();
            QAbstractItemModel* model = ui->tableView->model();

            // Extraction des informations de la ligne sélectionnée
            QString nom = model->data(model->index(row, 1)).toString();
            QDate datedebut = model->data(model->index(row, 3)).toDate();
            QDate datefinprevu = model->data(model->index(row, 4)).toDate();

            // Création d'une boîte de dialogue avec calendrier
            QDialog* dialog = new QDialog(this);
            dialog->setWindowTitle("📅 Durée du chantier : " + nom);

            QCalendarWidget* calendar = new QCalendarWidget(dialog);
            calendar->setGridVisible(true);

            // 🟨 Format jaune pour toute la durée du chantier
            QTextCharFormat jaune;
            jaune.setBackground(Qt::yellow);
            jaune.setForeground(Qt::black);

            for (QDate d = datedebut; d <= datefinprevu; d = d.addDays(1)) {
                calendar->setDateTextFormat(d, jaune);
            }

            // 🔴 Format rouge pour la date de fin prévue (appliqué par-dessus le jaune)
            QTextCharFormat rouge;
            rouge.setBackground(Qt::red);
            rouge.setForeground(Qt::white);
            calendar->setDateTextFormat(datefinprevu, rouge);

            // Affichage
            QVBoxLayout* layout = new QVBoxLayout(dialog);
            layout->addWidget(calendar);
            dialog->setLayout(layout);
            dialog->exec();
        }





        void MainWindow::on_tableView_clicked(const QModelIndex &index)
        {
            if (!index.isValid())
                return;

            // Récupérer l'ID du chantier sélectionné
            int chantierId = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toInt();

            // Démarrer l'écoute Arduino pour ce chantier
            temperatureManager->startListening("COM3", chantierId);

            QMessageBox::information(this, "Température", QString("⏳ Écoute de la température pour le chantier ID : %1").arg(chantierId));

        }


        void MainWindow::on_pushButton_9_clicked()
        {
            ui->stackedWidget_2->setCurrentIndex(0);
        }

        void MainWindow::on_pushButton_14_clicked()
        {
            ui->stackedWidget_2->setCurrentIndex(0);
        }

        void MainWindow::on_pushButton_15_clicked()
        {
            ui->stackedWidget_2->setCurrentIndex(0);
        }


//partie mtaa ness lkol besh tzid linterface mteha -----------------------------------------------------------------------------------

        void MainWindow::on_switch_partenaire_clicked()
        {
            ui->stackedWidget->setCurrentIndex(1);
        }


        void MainWindow::on_switch_employe_clicked()
        {
            ui->stackedWidget->setCurrentIndex(0);
        }

        void MainWindow::on_btnchantiers_2_clicked()
        {
            ui->stackedWidget->setCurrentIndex(2);
        }














