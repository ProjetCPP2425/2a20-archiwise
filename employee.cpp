#include "employee.h"
#include "ui_employee.h"  // Correct header generated from employee.ui
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>

employee::employee(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::employee)  // Correct Ui class
{
    ui->setupUi(this);  // Set up the UI
    emp = new employee();  // Initialize emp object
    ui->tableView->setModel(emp->afficher());  // Use emp to access the afficher method
}

employee::~employee()
{
    delete ui;  // Clean up the UI object
    delete emp;  // Clean up emp object memory
}

void employee::on_pushButton_ajouter_clicked()
{
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString email = ui->email->text();
    QString numero = ui->numero->text();
    double salaire = ui->salaire->text().toDouble();
    QString action = ui->action->text();
    QString password = ui->password->text();

    employee E(nom, prenom, email, numero, salaire, action, password);
    bool test = E.ajouter();

    if (test)
    {
        ui->tableView->setModel(E.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\nCliquez sur Annuler pour quitter."),
                                 QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Ajout non effectué.\nCliquez sur Annuler pour quitter."),
                              QMessageBox::Cancel);
    }
}

void employee::on_pushButton_supprimer_clicked()
{
    QString email = ui->email_suppression->text();
    bool test = emp->supprimer(email);  // Use emp-> for accessing supprimer method

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée\nCliquez sur Annuler pour quitter."),
                                 QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Suppression non effectuée.\nCliquez sur Annuler pour quitter."),
                              QMessageBox::Cancel);
    }
}

void employee::on_tableView_clicked(const QModelIndex &index)
{
    if (!index.isValid()) return;

    int row = index.row();
    QAbstractItemModel *model = ui->tableView->model();

    QString nom = model->data(model->index(row, 0)).toString().trimmed();
    QString prenom = model->data(model->index(row, 1)).toString().trimmed();
    QString email = model->data(model->index(row, 2)).toString().trimmed();
    QString numero = model->data(model->index(row, 3)).toString().trimmed();
    double salaire = model->data(model->index(row, 4)).toDouble();
    QString action = model->data(model->index(row, 5)).toString().trimmed();
    QString password = model->data(model->index(row, 6)).toString().trimmed();

    ui->nom->setText(nom);
    ui->prenom->setText(prenom);
    ui->email->setText(email);
    ui->numero->setText(numero);
    ui->salaire->setText(QString::number(salaire));
    ui->action->setText(action);
    ui->password->setText(password);
}

void employee::on_pushButton_modifier_clicked()
{
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
    QString email = ui->email->text();
    QString numero = ui->numero->text();
    double salaire = ui->salaire->text().toDouble();
    QString action = ui->action->text();
    QString password = ui->password->text();

    if (nom.isEmpty() || prenom.isEmpty() || email.isEmpty() || numero.isEmpty() || salaire <= 0 || action.isEmpty() || password.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }

    employee emp;  // Declare the emp object for modification
    bool test = emp.modifier(nom, prenom, email, numero, salaire, action, password);

    if (test) {
        QMessageBox::information(this, "Modification réussie", "Les informations ont été modifiées avec succès !");
        ui->tableView->setModel(emp.afficher());
    } else {
        QMessageBox::critical(this, "Échec", "La modification a échoué !");
    }
}
