#ifndef MATERIEL_H
#define MATERIEL_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Materiel {
private:
    int id;
    double cout;
    QString nom;
    int quantite;
    QString etat;
    QDate dateachat;
    QString garantie;

public:
    Materiel();
    Materiel(int id, double cout, QString nom, int quantite, QString etat, QDate dateachat, QString garantie);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier(int id, double cout, QString nom, int quantite, QString etat, QDate dateachat, QString garantie);
};

#endif // MATERIEL_H
