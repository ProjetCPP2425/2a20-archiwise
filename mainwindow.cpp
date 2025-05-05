#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
<<<<<<< HEAD
#include <QSqlError> // Pour QSqlError
#include <QSqlDatabase> // Pour QSqlDatabase (si vous l'utilisez)
=======
#include <QSqlError>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QMessageBox>
#include <QSortFilterProxyModel>
#include <QTimer>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QUrl>
#include <QSqlTableModel>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "  ..\..\..\..\Downloads\qrcode.h "
using namespace qrcodegen;

>>>>>>> f963b09 (projet qt)
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD
    model = new QSqlQueryModel(this);
    // Connect the "Ajouter" button to the slot
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;

=======
    ui->stackedWidget->setCurrentIndex(1);
    remplirComboBoxEtats();

    // Initialiser le modèle
    model = new QSqlQueryModel(this);


    // Remplir la table view
    afficherMateriel();
    setupStatsChart(ui->widgetStats); // <- Ajouter cette ligne

    // Connecter les boutons
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::on_pushButton_11_clicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::on_pushButton_9_clicked);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::on_pushButton_10_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_pushButton_3_clicked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::on_btnSupprimer_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(1); });
    connect(ui->pushButton_13, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(1); });
    connect(ui->pushButton_12, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(1); });
    connect(ui->pushButton_8, &QPushButton::clicked, this, [this]() { ui->stackedWidget->setCurrentIndex(1); });
    // Remplir les comboBox
    remplirComboBox();
    connect(ui->comboBox_tri, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, [this]() { afficherMateriel(); });

    connect(ui->lineEditRecherche, &QLineEdit::textChanged,
            this, &MainWindow::on_recherche_textChanged);
    connect(ui->btn_export_pdf, &QPushButton::clicked, this, &MainWindow::on_btn_export_pdf_clicked);
    // Dans le constructeur
    // Ajouter cette connexion dans le constructeur
    connect(ui->pushButton_genererQR, &QPushButton::clicked, this, &MainWindow::on_pushButton_genererQR_clicked);
    connect(ui->showStatsButton, &QPushButton::clicked, this, &MainWindow::on_showStatsButton_clicked);

    // Vérification du stock critique
    QTimer::singleShot(100, this, []() {
        Materiel::verifierStockCritique();
    });
}
void MainWindow::remplirComboBoxEtats()
{
    QStringList etats = {
        "En service",
        "En panne",
        "En maintenance",
        "Hors service",
        "En stock"
    };

    ui->comboBoxEtat->clear();      // pour formulaire d’ajout
    ui->comboBoxEtat->addItems(etats);

    ui->comboBoxEtat_2->clear();    // pour formulaire de modification
    ui->comboBoxEtat_2->addItems(etats);
}

void MainWindow::remplirComboBox()
{
    QSqlQuery query("SELECT ID FROM MATERIEL");
    ui->comboBox->clear();
    ui->comboBox_2->clear();

    ui->comboBox->addItem("Sélectionnez un id");
    ui->comboBox_2->addItem("Sélectionnez un id");

    while (query.next()) {
        int id = query.value(0).toInt();
        ui->comboBox->addItem(QString::number(id), id);
        ui->comboBox_2->addItem(QString::number(id), id);
    }
}

#include <QSortFilterProxyModel>  // Ajoutez cette ligne en haut du fichier

void MainWindow::afficherMateriel() {
    QString critereTri;

    if (ui->comboBox_tri->currentText() == "nom") {
        critereTri = "nom ASC";
    }
    else if (ui->comboBox_tri->currentText() == "cout") {
        critereTri = "cout ASC";
    }
    else {
        critereTri = ""; // Pas de tri spécifique
    }

    QSqlQueryModel *nouveauModel = materiel.afficher(critereTri);

    if (!nouveauModel) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les matériels");
        return;
    }

    // Suppression de l'ancien modèle
    QAbstractItemModel *oldModel = ui->tableViewMateriel->model();
    if (oldModel) {
        delete oldModel;
    }

    ui->tableViewMateriel->setModel(nouveauModel);
    ui->tableViewMateriel->resizeColumnsToContents();
}
MainWindow::~MainWindow()
{
    delete ui;
>>>>>>> f963b09 (projet qt)
}

void MainWindow::on_ajmateriel_3_clicked()
{
<<<<<<< HEAD
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
=======
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_clicked() {
    QString nom = ui->nom->text().trimmed();
    QString etat = ui->comboBoxEtat->currentText().trimmed();  // ✅ Correction ici
    QString garantie = ui->lineEditGarantie->text().trimmed();
    bool ok;

    // Validate cost
    double cout = ui->lineEditCout->text().toDouble(&ok);
    if (!ok || cout <= 0) {
        QMessageBox::warning(this, "Erreur", "Le coût doit être un nombre positif !");
        return;
    }

    // Validate quantity
    int quantite = ui->lineEditQuantite->text().toInt(&ok);
    if (!ok || quantite <= 0) {
        QMessageBox::warning(this, "Erreur", "La quantité doit être un nombre entier positif !");
        return;
    }

    // Validate name (only letters)
    QRegularExpression regex("^[A-Za-zÀ-ÿ ]+$");
    if (!regex.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom ne doit contenir que des lettres !");
        return;
    }

    // Validate state
    if (etat.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'état ne doit pas être vide !");
        return;
    }

    // Validate warranty
    if (garantie.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "La garantie ne doit pas être vide !");
        return;
    }

    // Retrieve date
    QDate dateAchat = ui->dateEditAchat->date();
    if (!dateAchat.isValid()) {
        QMessageBox::warning(this, "Erreur", "Date invalide !");
        return;
    }
    // Vérification que la garantie est une chaîne de caractères et non négative
    QRegularExpression regexGarantie("^[A-Za-zÀ-ÿ0-9 ]+$"); // Accepte lettres, chiffres et espaces
    if (!regexGarantie.match(garantie).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "La garantie doit être une chaîne de caractères valide !");
        return;
    }

    // Add Material
    Materiel m(0, cout, nom, quantite, etat, dateAchat, garantie);
    if (m.ajouter()) {
        QMessageBox::information(this, "Succès", "Matériel ajouté avec succès !");
        afficherMateriel();
        remplirComboBox();
        ui->stackedWidget->setCurrentIndex(0);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du matériel !");
>>>>>>> f963b09 (projet qt)
    }
}


<<<<<<< HEAD
=======
void MainWindow::on_pushButton_9_clicked()
{
    int id = ui->comboBox->currentData().toInt();
    if (ui->comboBox->currentIndex() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un id!");
        return;
    }

    if (materiel.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Matériel supprimé avec succès");
        afficherMateriel();
        remplirComboBox();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression");
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    int materielId = ui->comboBox_2->currentData().toInt();
    if (ui->comboBox_2->currentIndex() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un ID !");
        return;
    }

    if (materiel.recupererParId(materielId)) {
        ui->nom_2->setText(materiel.getNom());
        ui->qu->setText(QString::number(materiel.getQuantite()));
        ui->cout->setText(QString::number(materiel.getCout()));
        ui->comboBoxEtat_2->setCurrentText(materiel.getEtat()); // ✅ CORRECTION ICI
        ui->date->setText(materiel.getDateAchat().toString("yyyy-MM-dd"));
        ui->garantie->setText(materiel.getGarantie());
        ui->comboBox_2->setEnabled(false);
    } else {
        QMessageBox::warning(this, "Erreur", "Aucun matériel trouvé avec cet ID");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    int materielId = ui->comboBox_2->currentData().toInt();
    if (ui->comboBox_2->currentIndex() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un ID valide !");
        return;
    }

    // Validation des champs
    if (ui->nom_2->text().isEmpty() || ui->qu->text().isEmpty() || ui->cout->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs obligatoires doivent être remplis");
        return;
    }

    // Conversion sécurisée
    bool conversionOk;
    double cout = ui->cout->text().toDouble(&conversionOk);
    if (!conversionOk || cout < 0) {
        QMessageBox::warning(this, "Erreur", "Le coût doit être un nombre positif");
        return;
    }

    int quantite = ui->qu->text().toInt(&conversionOk);
    if (!conversionOk || quantite <= 0) {
        QMessageBox::warning(this, "Erreur", "La quantité doit être un entier positif");
        return;
    }

    // Récupération des valeurs
    QString nom = ui->nom_2->text().trimmed();
    QString etat = ui->comboBoxEtat_2->currentText().trimmed(); // ✅ correction ici
    QDate dateAchat = QDate::fromString(ui->date->text(), "yyyy-MM-dd");
    QString garantie = ui->garantie->text().trimmed();

    if (!dateAchat.isValid()) {
        QMessageBox::warning(this, "Erreur", "Date d'achat invalide");
        return;
    }

    // Debug avant modification
    qDebug() << "Tentative de modification - ID:" << materielId;
    qDebug() << "Valeurs:" << nom << cout << quantite << etat << dateAchat << garantie;

    if (materiel.modifier(materielId, cout, nom, quantite, etat, dateAchat, garantie)) {
        QMessageBox::information(this, "Succès", "Matériel modifié avec succès");
        afficherMateriel();
        remplirComboBox();
        // Réinitialisation
        ui->nom_2->clear();
        ui->qu->clear();
        ui->cout->clear();
        ui->comboBoxEtat_2->clear();
        ui->date->clear();
        ui->garantie->clear();
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_2->setCurrentIndex(0);
    } else {
        QMessageBox::critical(this, "Erreur",
                              "Échec de la modification.\n"
                              "Veuillez vérifier que:\n"
                              "- L'ID existe bien\n"
                              "- Vous avez les droits nécessaires\n"
                              "- Les valeurs sont valides");
    }
}
void MainWindow::on_pushButton_11_clicked()
{   ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_btnSupprimer_clicked()
{
    int id = ui->comboBox->currentData().toInt();
    if (id == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un ID !");
        return;
    }

    if (materiel.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Matériel supprimé avec succès");
        afficherMateriel();
        remplirComboBox();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression");
    }
}


void MainWindow::on_pushButton_12_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::on_comboBox_tri_currentIndexChanged(int index) {
    Q_UNUSED(index); // On n'utilise pas directement l'index
    afficherMateriel(); // On recharge simplement les données
}
void MainWindow::on_recherche_textChanged(const QString &text) {
    QString critere = ui->comboBoxCritere->currentText();
    QSqlQueryModel *nouveauModel = materiel.rechercher(critere, text);

    if (nouveauModel) {
        // Suppression de l'ancien modèle
        QAbstractItemModel *ancienModel = ui->tableViewMateriel->model();
        if (ancienModel) ancienModel->deleteLater();

        ui->tableViewMateriel->setModel(nouveauModel);
        ui->tableViewMateriel->resizeColumnsToContents();
    }
}
void MainWindow::on_btn_export_pdf_clicked() {
    Materiel m;
    m.exporterPDF();

    QMessageBox::information(this, "Export PDF", "Le fichier materiels.pdf a été généré avec succès !");
}

void MainWindow::verifierStockAuto() {
    Materiel::verifierStockCritique(this);

    // Planifier la prochaine vérification (ex: toutes les 4 heures)
    QTimer::singleShot(4 * 60 * 60 * 1000, this, &MainWindow::verifierStockAuto);
}
QImage MainWindow::generateQRCodeImage(const QString &text, int size)
{
    QrCode qr = QrCode::encodeText(text.toStdString().c_str(), QrCode::Ecc::LOW);

    int border = 4;
    int qrSize = qr.getSize();
    QImage image((qrSize + border * 2), (qrSize + border * 2), QImage::Format_RGB888);
    image.fill(Qt::white);

    QPainter painter(&image);
    painter.setBrush(Qt::black);
    painter.setPen(Qt::NoPen);

    for (int y = 0; y < qrSize; y++) {
        for (int x = 0; x < qrSize; x++) {
            if (qr.getModule(x, y)) {
                painter.drawRect(border + x, border + y, 1, 1);
            }
        }
    }

    return image.scaled(size, size);
}

void MainWindow::on_pushButton_genererQR_clicked() {
    QSqlQuery query("SELECT nom, quantite FROM materiel");
    QString qrText;

    // Générer le texte pour le QR Code
    while (query.next()) {
        QString nom = query.value(0).toString();
        int quantite = query.value(1).toInt();
        qrText += nom + " : " + QString::number(quantite) + "\n";
    }

    if (qrText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun matériel trouvé.");
        return;
    }

    // Générer l'image du QR Code
    QImage qrImage = generateQRCodeImage(qrText, 150); // Taille 200x200

    // Afficher directement le QR Code dans l'interface
    ui->label_qrcode->setPixmap(QPixmap::fromImage(qrImage));
    ui->stackedWidget->setCurrentWidget(ui->page_2); // Afficher la page du QR Code
}
void MainWindow::setupStatsChart(QWidget *parentWidget)
{
    QVBoxLayout *layout = new QVBoxLayout(parentWidget);
    parentWidget->setLayout(layout);

    QChart *chart = new QChart();
    chart->setTitle("Répartition des matériels par état");

    m_chartView = new QChartView(chart);
    m_chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(m_chartView);

    // Boutons Retour et Actualiser
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *backButton = new QPushButton("Retour");
    connect(backButton, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });

    QPushButton *refreshButton = new QPushButton("Actualiser");
    connect(refreshButton, &QPushButton::clicked, this, &MainWindow::updateMaterielStats);

    buttonLayout->addWidget(backButton);
    buttonLayout->addWidget(refreshButton);
    layout->addLayout(buttonLayout);
}
void MainWindow::updateMaterielStats()
{
    if (!m_chartView) {
        qDebug() << "Erreur: m_chartView non initialisé";
        return;
    }

    QSqlQuery query;
    QString queryStr = "SELECT etat, COUNT(*) as count FROM materiel GROUP BY etat";

    if (!query.exec(queryStr)) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les statistiques: " + query.lastError().text());
        return;
    }

    QChart *chart = m_chartView->chart();
    chart->removeAllSeries();

    if (!query.next()) {
        chart->setTitle("Aucune donnée disponible");
        return;
    }

    QPieSeries *series = new QPieSeries();
    do {
        QString etat = query.value("etat").toString();
        int count = query.value("count").toInt();
        QPieSlice *slice = series->append(etat + " (" + QString::number(count) + ")", count);
        slice->setLabelVisible(true);
    } while (query.next());

    chart->addSeries(series);
    chart->setTitle("Répartition des matériels par état");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
}

void MainWindow::on_showStatsButton_clicked()
{
    updateMaterielStats();
    ui->stackedWidget->setCurrentWidget(ui->pageStatistiques);
}
>>>>>>> f963b09 (projet qt)
