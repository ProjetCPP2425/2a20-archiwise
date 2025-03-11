#ifndef PROJET_H
#define PROJET_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Projet
{
private:
    int id;
    QString nom, description, chefDeProjet, statut;
    QDate dateDebut, dateFinPrevu;
    float budget;

public:
    Projet();
    Projet(int, QString, QString, QString, QDate, QDate, float, QString);

    // Getters
    int get_id(){return id;}
    QString get_nom(){return nom;}
    QString get_description(){return description;}
    QString get_chefDeProjet(){return chefDeProjet;}
    QString get_statut(){return statut;}
    QDate get_dateDebut(){return dateDebut;}
    QDate get_dateFinPrevu(){return dateFinPrevu;}
    float get_budget(){return budget;}

    // Setters
    void set_id(int id) { this->id = id; }
    void set_nom(QString n) { nom = n; }
    void set_description(QString d) { description = d; }
    void set_chefDeProjet(QString c) { chefDeProjet = c; }
    void set_statut(QString s) { statut = s; }
    void set_dateDebut(QDate d) { dateDebut = d; }
    void set_dateFinPrevu(QDate d) { dateFinPrevu = d; }
    void set_budget(float b) { budget = b; }

    // Fonctionnalités
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int, QString, QString, QString, QDate, QDate, float, QString);
    Projet getprojetById(int id);

};

#endif // PROJET_H
