#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QRegularExpression>
#include <QTimer>
#include <QSqlQuery>
#include <QHeaderView>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTextDocument>
#include <QMessageBox>
#include <QDate>
#include <QAbstractItemModel>
#include <QSqlError>
#include "sms.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupTableView();
    setupHistoriqueTable();

    // Initialisation de l'interface
    ui->comboBox_type->addItem("Particulier");
    ui->comboBox_type->addItem("Entreprise");
    ui->comboBox_type->addItem("Premium");

    // Crée un widget pour les stats et l'ajoute à ton stackedWidget
    QWidget *statsPage = new QWidget();
    setupStatsChart(statsPage);
    ui->stackedWidget->addWidget(statsPage);
    // Connecter le nouveau bouton d'export PDF
    connect(ui->exportPdfButton, &QPushButton::clicked, this, &MainWindow::on_exportPdfButton_clicked);
    // Dans le constructeur :
    /*connect(ui->staClient_4_clicked, &QPushButton::clicked, this, [this]() {
                                 ui->stackedWidget->setCurrentIndex(1);
                             });*/

    connect(ui->showStatsButton_clicked, &QPushButton::clicked, this, &MainWindow::on_showStatsButton_clicked_clicked);

    connect(ui->showStatsButton_clicked, &QPushButton::clicked, this, [this]() {
        updateClientStats();
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);
    });

    /*connect(ui->staClient_4_clicked, &QPushButton::clicked, this, [this]() {
         ui->stackedWidget->setCurrentIndex(1);
     });*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupTableView()
{
    // Configuration du proxyModel et du tableView
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(client.afficher());
    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Connexion pour le tri au clic sur les en-têtes
    connect(ui->tableView->horizontalHeader(), &QHeaderView::sectionClicked,
            [this](int logicalIndex) {
                static Qt::SortOrder order = Qt::AscendingOrder;
                proxyModel->sort(logicalIndex, order);
                order = (order == Qt::AscendingOrder) ? Qt::DescendingOrder : Qt::AscendingOrder;
                QTimer::singleShot(100, this, &MainWindow::button_maram);
            });

    // Ajout des boutons
    button_maram();
}

void MainWindow::button_maram()
{
    QSortFilterProxyModel *proxy = qobject_cast<QSortFilterProxyModel*>(ui->tableView->model());
    if (!proxy) return;

    // Ajouter des colonnes pour les boutons si nécessaire
    while (proxy->columnCount() < 8) {
        proxy->insertColumn(proxy->columnCount());
    }

    // Définir les en-têtes des colonnes
    proxy->setHeaderData(6, Qt::Horizontal, "Update");
    proxy->setHeaderData(7, Qt::Horizontal, "Delete");

    for (int row = 0; row < proxy->rowCount(); ++row) {
        // Bouton Update
        QPushButton *update_button = new QPushButton("Update", this);
        update_button->setStyleSheet("background-color:#437FF7;border-radius:5px;color:#fff;padding:5px;min-width:70px;");

        connect(update_button, &QPushButton::clicked, [this, row, proxy]() {
            QModelIndex sourceIndex = proxy->mapToSource(proxy->index(row, 0));
            int id = sourceIndex.data().toInt();
            this->currentClientId = id;
            Client client = this->client.getclientById(id);

            ui->n->setText(client.get_nom());
            ui->p->setText(client.get_prenom());
            ui->a->setText(client.get_adresse());
            ui->t->setText(client.get_tel());
            ui->comboBox_type->setCurrentText(client.get_typeString());
            ui->di->setDate(client.get_dateInscription());
            ui->stackedWidget->setCurrentIndex(2);
        });

        // Bouton Delete
        QPushButton *delete_button = new QPushButton("Delete", this);
        delete_button->setStyleSheet("background-color:#ef1f22;border-radius:5px;color:#fff;padding:5px;min-width:70px;");

        connect(delete_button, &QPushButton::clicked, [this, row, proxy]() {
            QModelIndex sourceIndex = proxy->mapToSource(proxy->index(row, 0));
            int id = sourceIndex.data().toInt();

            if (this->client.supprimer(id)) {
                // Rafraîchir le modèle
                proxy->setSourceModel(this->client.afficher());
                button_maram(); // Recréer les boutons
                setupHistoriqueTable(); // Rafraîchir l'historique

                QMessageBox::information(this, "Succès", "Client supprimé avec succès");
            } else {
                QMessageBox::critical(this, "Erreur", "Échec de la suppression !");
            }
        });

        // Placement des boutons
        ui->tableView->setIndexWidget(proxy->index(row, 6), update_button);
        ui->tableView->setIndexWidget(proxy->index(row, 7), delete_button);
    }
}

void MainWindow::on_ajouterClient_clicked()
{
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString prenom = ui->lineEdit_prenom->text().trimmed();
    QString adresse = ui->lineEdit_adresse->text().trimmed();
    QString tel = ui->lineEdit_tel->text().trimmed();
    QString typeStr = ui->comboBox_type->currentText();
    QDate dateInscription = ui->dateEdit_inscription->date();

    // Validation
    if (nom.isEmpty() || prenom.isEmpty() || adresse.isEmpty() || tel.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    if (!tel.contains(QRegularExpression("^[0-9]{8}$"))) {
        QMessageBox::warning(this, "Téléphone invalide", "Le numéro doit contenir 8 chiffres.");
        return;
    }

    Client client(nom, prenom, adresse, tel, ClientType::Particulier, dateInscription);
    client.set_type(typeStr);

    if (client.ajouter()) {
        SmsSender sender("71256cbaabc3fc040753ea0f2854966d-2f1fae87-b2f6-4b0c-b3fb-9ecb56a0abc0", "447491163443");
        sender.sendSms("+21692550388", "Bienvenue ! Vous êtes maintenant inscrit"); // Replace with the recipient's phone number
        QMessageBox::information(this, "sms sent", "sms sent to your number");
        QMessageBox::information(this, "Succès", "Client ajouté !");
        proxyModel->setSourceModel(this->client.afficher());
        button_maram();
        setupHistoriqueTable(); // Rafraîchir l'historique

        ui->stackedWidget->setCurrentIndex(0);

        // Nettoyer les champs
        ui->lineEdit_nom->clear();
        ui->lineEdit_prenom->clear();
        ui->lineEdit_adresse->clear();
        ui->lineEdit_tel->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout.");
    }
}

void MainWindow::on_modifierClient_clicked()
{
    QString nom = ui->n->text().trimmed();
    QString prenom = ui->p->text().trimmed();
    QString adresse = ui->a->text().trimmed();
    QString tel = ui->t->text().trimmed();
    QString typeStr = ui->comboBox_type->currentText();
    QDate dateInscription = ui->di->date();

    Client clientModifie;
    clientModifie.set_nom(nom);
    clientModifie.set_prenom(prenom);
    clientModifie.set_adresse(adresse);
    clientModifie.set_tel(tel);
    clientModifie.set_type(typeStr);
    clientModifie.set_dateInscription(dateInscription);

    if (clientModifie.modifier(currentClientId)) {


        QMessageBox::information(this, "Succès", "Client modifié !");
        proxyModel->setSourceModel(this->client.afficher());
        button_maram();
        setupHistoriqueTable(); // Rafraîchir l'historique

        ui->stackedWidget->setCurrentIndex(0);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification.");
    }
}

void MainWindow::on_lineEdit_recherche_textChanged(const QString &text)
{
    static QTimer timer;
    timer.setSingleShot(true);
    timer.setInterval(300);

    connect(&timer, &QTimer::timeout, this, [this, text]() {
        if (text == ui->lineEdit_recherche->text()) {
            proxyModel->setSourceModel(client.rechercher(text.trimmed()));
            button_maram();
        }
    });

    timer.start();
}

void MainWindow::on_supprimerClient_clicked(int id)
{
    Client client = client.getclientById(id);
    if (client.get_id() == -1) {
        QMessageBox::critical(this, "Error", "This ID doesn't exist!");
    } else {
        bool test = client.supprimer(id);

        if (test) {
            proxyModel->setSourceModel(this->client.afficher());
            button_maram();
            setupHistoriqueTable(); // Rafraîchir l'historique
            QMessageBox::information(nullptr, QObject::tr("DONE"),
                                     QObject::tr("An event's been deleted.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        } else {
            QMessageBox::critical(nullptr, QObject::tr("FAIL"),
                                  QObject::tr("Error.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
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

void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::trierClients(int column, Qt::SortOrder order)
{
    proxyModel->sort(column, order);
}

void MainWindow::on_exportPdfButton_clicked()
{
    exportToPdf();
}

void MainWindow::exportToPdf() {
    QString html;

    html += "<html><head><meta charset='utf-8'>";
    html += "<style>";
    html += "body { font-family: 'Arial', sans-serif; }";
    html += "h2 { font-size: 24px; }";
    html += "p { font-size: 14px; }";
    html += "table { width: 100%; border-collapse: collapse; margin-top: 20px; }";
    html += "th, td { border: 1px solid #aaa; padding: 8px; text-align: left; word-wrap: break-word; }";
    html += "th { background-color: #f2f2f2; }";
    html += "</style></head><body>";

    html += "<h2>Liste des Clients</h2>";
    html += "<p>Générée le: " + QDate::currentDate().toString("dd/MM/yyyy") + "</p>";
    html += "<p>Nombre total de clients: " + QString::number(ui->tableView->model()->rowCount()) + "</p>";

    html += "<table>";
    html += "<tr><th>ID</th><th>Nom</th><th>Prenom</th><th>Adresse</th><th>Tel</th></tr>";

    QAbstractItemModel *model = ui->tableView->model();

    for (int row = 0; row < model->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < 5; ++col) {
            QString data = model->index(row, col).data().toString();
            html += "<td>" + data.toHtmlEscaped() + "</td>";
        }
        html += "</tr>";
    }

    html += "</table>";
    html += "</body></html>";

    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);

    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le PDF",
                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/clients.pdf",
                                                    "Fichiers PDF (*.pdf)");

    if (filePath.isEmpty())
        return;

    printer.setOutputFileName(filePath);
    document.print(&printer);

    QMessageBox::information(this, "Export", "PDF exporté avec succès !");
}

void MainWindow::setupStatsChart(QWidget *parentWidget)
{
    QVBoxLayout *layout = new QVBoxLayout(parentWidget);
    parentWidget->setLayout(layout);

    // Création du graphique
    QChart *chart = new QChart();
    chart->setTitle("Répartition des clients par type");

    // Création de la vue du graphique
    m_chartView = new QChartView(chart);
    m_chartView->setRenderHint(QPainter::Antialiasing);
    layout->addWidget(m_chartView);

    // Boutons
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *backButton = new QPushButton("Retour");
    connect(backButton, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });

    QPushButton *refreshButton = new QPushButton("Actualiser");
    connect(refreshButton, &QPushButton::clicked, this, &MainWindow::updateClientStats);

    buttonLayout->addWidget(backButton);
    buttonLayout->addWidget(refreshButton);
    layout->addLayout(buttonLayout);
}

void MainWindow::updateClientStats()
{
    if (!m_chartView) {
        qDebug() << "Erreur: m_chartView non initialisé";
        return;
    }

    QSqlQuery query;
    QString queryStr = "SELECT TYPE, COUNT(*) as count FROM CLIENTS GROUP BY TYPE";

    if (!query.exec(queryStr)) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        qDebug() << "Requête:" << queryStr;
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les statistiques: " + query.lastError().text());
        return;
    }

    QChart *chart = m_chartView->chart();
    chart->removeAllSeries();

    if (!query.next()) {
        qDebug() << "Aucune donnée trouvée";
        chart->setTitle("Aucune donnée disponible");
        return;
    }

    QPieSeries *series = new QPieSeries();
    do {
        QString type = query.value("TYPE").toString();
        int count = query.value("count").toInt();

        QPieSlice *slice = series->append(type + " (" + QString::number(count) + ")", count);
        slice->setLabelVisible(true);
    } while (query.next());

    chart->addSeries(series);
    chart->setTitle("Répartition des clients par type");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
}
// Ajoute cette méthode pour basculer vers la page des stats
/*void MainWindow::on_showStatsButton_clicked()  // Connecte ce slot à ton bouton
{
    updateClientStats();
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);  // Dernière page
}*/

void MainWindow::on_showStatsButton_clicked_clicked()
{
    updateClientStats();
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->count() - 1);  // Dernière page
}




void MainWindow::on_staClient_4_clicked_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_exportPdfButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::setupHistoriqueTable() {
    QSqlQueryModel *historiqueModel = client.afficherHistorique();



    ui->tableView_historique->setModel(historiqueModel);

    // Ajuster les colonnes
    ui->tableView_historique->setColumnHidden(0, true); // Cache la colonne ID
    ui->tableView_historique->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableView_historique->resizeColumnsToContents();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
