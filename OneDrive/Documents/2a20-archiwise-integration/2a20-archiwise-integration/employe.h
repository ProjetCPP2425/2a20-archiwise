#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QTextDocument>

class Employe {
public:
    Employe();

    bool ajouter(int id, QString nom, QString prenom, QString poste, double salaire,
                 QString statut, QString email, QString pass, QString numero);
    bool supprimer(int id);
    void afficher(QTableWidget *tableWidget);
    bool modifier(int id, QString nom, QString prenom, QString poste, double salaire,
                  QString statut, QString email, QString pass, QString numero);
    bool exporterPDF(QTableWidget *tableWidget);
};

#endif // EMPLOYE_H
