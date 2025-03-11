#include "employeee.h"
#include<QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>

employee::employee(QString nom, QString prenom, QString email, QString numero, double salaire, QString action, QString password)
{
    this->nom = nom;
    this->prenom = prenom;
    this->email = email;
    this->numero = numero;
    this->salaire = salaire;
    this->action = action;
    this->password = password;
}

bool employee::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYEE (NOM, PRENOM, EMAIL, NUMERO, SALAIRE, ACTION, PASSWORD) "
                  "VALUES (:nom, :prenom, :email, :numero, :salaire, :action, :password)");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":numero", numero);
    query.bindValue(":salaire", salaire);
    query.bindValue(":action", action);
    query.bindValue(":password", password);

    return query.exec();
}

bool employee::supprimer(QString email)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYEE WHERE EMAIL = :email");
    query.bindValue(":email", email);
    return query.exec();
}

QSqlQueryModel * employee::afficher()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYEE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMERO"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("SALAIRE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ACTION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("PASSWORD"));

    return model;
}

bool employee::modifier(QString nom, QString prenom, QString email, QString numero, double salaire, QString action, QString password)
{
    QSqlQuery query;

    if (!query.prepare("UPDATE EMPLOYEE SET NOM = :nom, PRENOM = :prenom, NUMERO = :numero, "
                       "SALAIRE = :salaire, ACTION = :action, PASSWORD = :password "
                       "WHERE EMAIL = :email"))
    {
        qDebug() << "Erreur de préparation de la requête:" << query.lastError().text();
        return false;
    }

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":numero", numero);
    query.bindValue(":salaire", salaire);
    query.bindValue(":action", action);
    query.bindValue(":password", password);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification:" << query.lastError().text();
        return false;
    }

    return true;
}
