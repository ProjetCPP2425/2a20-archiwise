#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class employee
{
private:
    QString nom;
    QString prenom;
    QString email;
    QString numero;
    double salaire;
    QString action;
    QString password;

public:
    employee() {}
    employee(QString, QString, QString, QString, double, QString, QString);

    QString getNom() { return nom; }
    QString getPrenom() { return prenom; }
    QString getEmail() { return email; }
    QString getNumero() { return numero; }
    double getSalaire() { return salaire; }
    QString getAction() { return action; }
    QString getPassword() { return password; }

    void setNom(QString n) { nom = n; }
    void setPrenom(QString p) { prenom = p; }
    void setEmail(QString e) { email = e; }
    void setNumero(QString num) { numero = num; }
    void setSalaire(double s) { salaire = s; }
    void setAction(QString a) { action = a; }
    void setPassword(QString pass) { password = pass; }

    bool ajouter();
    bool supprimer(QString email);
    QSqlQueryModel *afficher();
    bool modifier(QString nom, QString prenom, QString email, QString numero, double salaire, QString action, QString password);
};

#endif // EMPLOYEE_H
