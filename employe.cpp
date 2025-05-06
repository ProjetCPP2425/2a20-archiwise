#include "employe.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include <QHeaderView>  // For column resizing
#include <QDebug>       // For debugging if needed
#include <QMessageBox>

Employe::Employe() {}

bool Employe::ajouter(int id, QString nom, QString prenom, QString poste, double salaire,
                      QString statut, QString email, QString pass, QString numero)
{
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYES (ID, NOM, PRENOM, POSTE, SALAIRE, STATUT, EMAIL, PASS, NUMERO) "
                  "VALUES (:id, :nom, :prenom, :poste, :salaire, :statut, :email, :pass, :numero)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire);
    query.bindValue(":statut", statut);
    query.bindValue(":email", email);
    query.bindValue(":pass", pass);
    query.bindValue(":numero", numero);

    return query.exec();
}

bool Employe::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYES WHERE ID = :id");
    query.bindValue(":id", id);

    return query.exec();
}
bool Employe::exporterPDF(QTableWidget *tableWidget) {
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");

    if (fileName.isEmpty()) {
        return false;
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QString html = "<h1 align='center'>Liste des Employés</h1>";
    html += "<table border='1' cellspacing='0' cellpadding='5' width='100%'>";

    // Add headers
    html += "<tr>";
    for (int col = 0; col < tableWidget->columnCount() - 1; ++col) { // Skip actions column
        html += "<th>" + tableWidget->horizontalHeaderItem(col)->text() + "</th>";
    }
    html += "</tr>";

    // Add data rows
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < tableWidget->columnCount() - 1; ++col) { // Skip actions column
            QTableWidgetItem *item = tableWidget->item(row, col);
            html += "<td>" + (item ? item->text() : "") + "</td>";
        }
        html += "</tr>";
    }
    html += "</table>";

    doc.setHtml(html);
    doc.setPageSize(printer.pageRect(QPrinter::Point).size());

    doc.print(&printer);

    return true;
}

bool Employe::modifier(int id, QString nom, QString prenom, QString poste, double salaire,
                       QString statut, QString email, QString pass, QString numero)
{
    QSqlQuery query;
    query.prepare("UPDATE EMPLOYES SET NOM=:nom, PRENOM=:prenom, POSTE=:poste, SALAIRE=:salaire, "
                  "STATUT=:statut, EMAIL=:email, PASS=:pass, NUMERO=:numero WHERE ID=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaire);
    query.bindValue(":statut", statut);
    query.bindValue(":email", email);
    query.bindValue(":pass", pass);
    query.bindValue(":numero", numero);

    return query.exec();
}

void Employe::afficher(QTableWidget *tableWidget)
{
    // Clear existing content but keep columns
    tableWidget->clearContents();
    tableWidget->setRowCount(0);

    // Set up columns if not already done
    if (tableWidget->columnCount() != 10) {
        tableWidget->setColumnCount(10);
        QStringList headers = {"ID", "Nom", "Prénom", "Poste", "Salaire", "Statut", "Email", "Pass", "Numéro", "Actions"};
        tableWidget->setHorizontalHeaderLabels(headers);
    }

    QSqlQuery query("SELECT * FROM EMPLOYES");
    int row = 0;

    while (query.next()) {
        tableWidget->insertRow(row);

        // Fill data columns
        for (int col = 0; col < 9; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
            tableWidget->setItem(row, col, item);
        }

        // Create container widget for buttons
        QWidget *buttonWidget = new QWidget(tableWidget);
        QHBoxLayout *buttonLayout = new QHBoxLayout(buttonWidget);
        buttonLayout->setContentsMargins(2, 2, 2, 2);
        buttonLayout->setSpacing(2);

        // Create Delete button
        QPushButton *deleteButton = new QPushButton("Supprimer", buttonWidget);
        deleteButton->setFixedSize(80, 25);
        deleteButton->setStyleSheet("QPushButton { font-size: 10pt; }");

        // Create Edit button
        QPushButton *editButton = new QPushButton("Modifier", buttonWidget);
        editButton->setFixedSize(80, 25);
        editButton->setStyleSheet("QPushButton { font-size: 10pt; }");

        // Add buttons to layout
        buttonLayout->addWidget(editButton);
        buttonLayout->addWidget(deleteButton);
        buttonWidget->setLayout(buttonLayout);
        deleteButton->setStyleSheet("QPushButton { "
                                    "background-color: #e94560; "
                                    "color: white; "
                                    "font-size: 10pt; "
                                    "border-radius: 4px; "
                                    "padding: 2px; "
                                    "}");

        // For edit button
        editButton->setStyleSheet("QPushButton { "
                                  "background-color: #007bff; "
                                  "color: white; "
                                  "font-size: 10pt; "
                                  "border-radius: 4px; "
                                  "padding: 2px; "
                                  "}");
        // Set widget in the table
        tableWidget->setCellWidget(row, 9, buttonWidget);

        // Get the ID for this row
        int id = query.value(0).toInt();

        // Connect delete button
        QObject::connect(deleteButton, &QPushButton::clicked, [this, tableWidget, id]() {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(nullptr, "Confirmation",
                                          "Voulez-vous vraiment supprimer cet employé?",
                                          QMessageBox::Yes|QMessageBox::No);

            if (reply == QMessageBox::Yes && this->supprimer(id)) {
                this->afficher(tableWidget);
            }
        });

        // Connect edit button
        QObject::connect(editButton, &QPushButton::clicked, [this, tableWidget, row, id]() {
            // Get current values from the row
            QString nom = tableWidget->item(row, 1)->text();
            QString prenom = tableWidget->item(row, 2)->text();
            QString poste = tableWidget->item(row, 3)->text();
            double salaire = tableWidget->item(row, 4)->text().toDouble();
            QString statut = tableWidget->item(row, 5)->text();
            QString email = tableWidget->item(row, 6)->text();
            QString pass = tableWidget->item(row, 7)->text();
            QString numero = tableWidget->item(row, 8)->text();

            if (this->modifier(id, nom, prenom, poste, salaire, statut, email, pass, numero)) {
                QMessageBox::information(nullptr, "Succès", "Modification réussie!");
                this->afficher(tableWidget);
            }
        });

        row++;
    }

    // Ensure the table displays properly
    tableWidget->resizeColumnsToContents();
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    tableWidget->horizontalHeader()->setStretchLastSection(true);
}
