#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "partenaire.h"
#include "ButtonDelegate.h"
#include <QRegularExpression>

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


    botResponses << "Bonjour! Comment puis-je vous aider avec les partenaires ?"
                 << "D'accord, je vais vérifier les partenaires."
                 << "Je peux vous aider à gérer les informations des partenaires."
                 << "Quel type de partenaire voulez-vous consulter ?"
                 << "Avez-vous des questions sur les contrats ?";


    ajouterMessageBot("👋 Bonjour ! Je suis votre assistant intelligent. Posez-moi n'importe quelle question concernant les partenaires !");
    ajouterMessageBot(QSslSocket::supportsSsl() ? "✅ SSL OK !" : "❌ SSL non supporté");



    // Créez un objet Partenaire


    // Récupérez le modèle et vérifiez qu'il n'est pas nul


    // Liez le modèle au QTableView
    rappelContratsFinissants();

    setupTableView();
    // Colonne "Actions"



afficherStatistiquesContrats();

    afficherStatistiquesPartenaires();

    qDebug() << "✅ Affichage des partenaires réussi.";

    QSqlQuery query("SELECT ID FROM PARTENAIRES");








}
// Destructeur
MainWindow::~MainWindow()
{
    delete ui;
    delete tts;
    delete timer;
}
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
}
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>





void MainWindow::processUserInput(const QString &input)
{
    QString response;

    // Exemple de gestion des entrées
    if (input.contains("combien de partenaires de type fournisseur", Qt::CaseInsensitive)) {
        // Requête SQL pour obtenir le nombre de fournisseurs
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM PARTENAIRES WHERE TYPEPARTENAIRE = :type");
        query.bindValue(":type", "Fournisseur");

        if (query.exec()) {
            if (query.next()) {
                int count = query.value(0).toInt();
                response = QString("Il y a %1 partenaires de type fournisseur.").arg(count);
            }
        } else {
            qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError();
            response = "Je n'ai pas pu obtenir le nombre de fournisseurs pour l'instant.";
        }
    } else if (input.contains("combien de partenaires de type architecte", Qt::CaseInsensitive)) {
        // Requête SQL pour obtenir le nombre d'architectes
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM PARTENAIRES WHERE TYPEPARTENAIRE = :type");
        query.bindValue(":type", "Architecte");

        if (query.exec()) {
            if (query.next()) {
                int count = query.value(0).toInt();
                response = QString("Il y a %1 partenaires de type architecte.").arg(count);
            }
        } else {
            qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError();
            response = "Je n'ai pas pu obtenir le nombre d'architectes pour l'instant.";
        }
    } else if (input.contains("combien de partenaires dans la ville", Qt::CaseInsensitive)) {
        // Extraction de la ville de la question (simple exemple ici)
        QRegularExpression regExp("ville ([\\w\\s]+)");
        QRegularExpressionMatch match = regExp.match(input);
        QString ville;
        if (match.hasMatch()) {
            ville = match.captured(1);
        }

        // Requête SQL pour obtenir le nombre de partenaires dans la ville
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM PARTENAIRES WHERE VILLE = :ville");
        query.bindValue(":ville", ville);

        if (query.exec()) {
            if (query.next()) {
                int count = query.value(0).toInt();
                response = QString("Il y a %1 partenaires dans la ville %2.").arg(count).arg(ville);
            }
        } else {
            qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError();
            response = "Je n'ai pas pu obtenir le nombre de partenaires dans cette ville pour l'instant.";
        }
    } else if (input.contains("quels partenaires ont un contrat expiré", Qt::CaseInsensitive)) {
        // Requête SQL pour obtenir les partenaires dont le contrat est expiré
        QSqlQuery query;
        query.prepare("SELECT NOM FROM PARTENAIRES WHERE DATEFINCONTRAT < CURRENT_DATE");

        if (query.exec()) {
            QStringList partenaires;
            while (query.next()) {
                partenaires.append(query.value(0).toString());
            }

            if (!partenaires.isEmpty()) {
                response = "Les partenaires dont le contrat est expiré sont : " + partenaires.join(", ");
            } else {
                response = "Aucun partenaire n'a de contrat expiré.";
            }
        } else {
            qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError();
            response = "Je n'ai pas pu obtenir la liste des partenaires avec contrat expiré.";
        }
    } else if (input.contains("aide", Qt::CaseInsensitive)) {
        response = "Je peux vous aider à gérer les partenaires, les contrats, et plus encore!";
    } else {
        // Réponse aléatoire si aucune correspondance
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, botResponses.size() - 1);
        response = botResponses[dis(gen)];
    }

    // Ajouter la réponse du bot dans la zone de texte
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

