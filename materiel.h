#ifndef MATERIEL_H
#define MATERIEL_H

#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
<<<<<<< HEAD
=======
#include <QChartView>
#include <QPieSeries>
#include <QtCharts>

//QT_CHARTS_USE_NAMESPACE
    class QChartView;
>>>>>>> f963b09 (projet qt)

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

<<<<<<< HEAD
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier(int id, double cout, QString nom, int quantite, QString etat, QDate dateachat, QString garantie);
};

=======
    // Getters
    QString getNom() const;
    int getQuantite() const;
    double getCout() const;
    QString getEtat() const;
    QDate getDateAchat() const;
    QString getGarantie() const;

    // Méthodes CRUD
    bool ajouter();
    QSqlQueryModel* afficher(const QString &sortBy = "");
    bool supprimer(int id);
    bool modifier(int id, double cout, QString nom, int quantite, QString etat, QDate dateachat, QString garantie);
    bool recupererParId(int id);
    QSqlQueryModel* afficherTrié(QString critere, QString ordre);
    QSqlQueryModel* rechercher(const QString &critere, const QString &valeur);
    void exporterPDF();
    static void verifierStockCritique(QWidget *parent = nullptr);
};
>>>>>>> f963b09 (projet qt)
#endif // MATERIEL_H
