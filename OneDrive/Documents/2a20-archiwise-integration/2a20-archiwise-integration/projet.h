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
    QString nom, description, chefDeProjet, statut,adresse,upload;
    QDate dateDebut, dateFinPrevu;
    float budget;

public:
    Projet();
    Projet(int, QString, QString, QString, QDate, QDate, float, QString,QString,QString);

    // Getters
    int get_id(){return id;}
    QString get_nom(){return nom;}
    QString get_description(){return description;}
    QString get_chefDeProjet(){return chefDeProjet;}
    QString get_statut(){return statut;}
    QDate get_dateDebut(){return dateDebut;}
    QDate get_dateFinPrevu(){return dateFinPrevu;}
    float get_budget(){return budget;}
    QString get_adresse(){return adresse;}
    QString get_upload(){return upload;}

    // Setters
    void set_id(int id) { this->id = id; }
    void set_nom(QString n) { nom = n; }
    void set_description(QString ds) { description = ds; }
    void set_chefDeProjet(QString c) { chefDeProjet = c; }
    void set_statut(QString s) { statut = s; }
    void set_dateDebut(QDate d) { dateDebut = d; }
    void set_dateFinPrevu(QDate d1) { dateFinPrevu = d1; }
    void set_budget(float b) { budget = b; }
    void set_adresse(QString s) { adresse = s; }
    void set_upload(QString u) { upload = u; }


    // Fonctionnalités
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    Projet getprojetById(int id);
    QSqlQueryModel *search(const QString &criteria);
    QSqlQueryModel *sort(const QString &criteria);
    QSqlQueryModel *getEventStatistics();
    bool exportToPdf();

};

#endif // PROJET_H
