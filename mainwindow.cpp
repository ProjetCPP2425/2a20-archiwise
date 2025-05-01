
#include "employe.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChart>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     // Optional: load data at startup
    connect(ui->btn_add, &QPushButton::clicked, this, &MainWindow::on_btn_add_clicked);
     connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_pdf_clicked);
    emp.afficher(ui->tableWidget);

}
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
// Destructor
MainWindow::~MainWindow()
{
    delete ui;
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

