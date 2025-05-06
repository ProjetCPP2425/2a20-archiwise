#ifndef CHANTIER_H
#define CHANTIER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class chantier
{
private:
    int id;
    QString nomchantier;
    QString adresse;
    QDate datedebut;
    QDate datefinprevu;
    QDate datefinreelle;
    QString statut;
    double budgetinitial;
    double coutreel;
    int progression;
    double temperature; // 🆕 New attribute

public:
    chantier();
    chantier(int, QString, QString, QDate, QDate, QDate, QString, double, double, int, double);

    // Getters
    int get_id() { return id; }
    QString get_nomchantier() { return nomchantier; }
    QString get_adresse() { return adresse; }
    QDate get_datedebut() { return datedebut; }
    QDate get_datefinprevu() { return datefinprevu; }
    QDate get_datefinreelle() { return datefinreelle; }
    QString get_statut() { return statut; }
    double get_budgetinitial() { return budgetinitial; }
    double get_coutreel() { return coutreel; }
    int get_progression() { return progression; }
    double get_temperature() { return temperature; } // 🆕 Getter for temperature

    // Setters
    void set_id(int id) { this->id = id; }
    void set_nomchantier(QString n) { nomchantier = n; }
    void set_adresse(QString a) { adresse = a; }
    void set_datedebut(QDate d) { datedebut = d; }
    void set_datefinprevu(QDate d) { datefinprevu = d; }
    void set_datefinreelle(QDate d) { datefinreelle = d; }
    void set_statut(QString s) { statut = s; }
    void set_budgetinitial(double b) { budgetinitial = b; }
    void set_coutreel(double c) { coutreel = c; }
    void set_progression(int p) { progression = p; }
    void set_temperature(double t) { temperature = t; } // 🆕 Setter for temperature

    // Fonctionnalités
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int id, const QString &nomchantier, const QString &adresse, const QDate &datedebut,
                  const QDate &datefinprevu, const QDate &datefinreelle, const QString &statut,
                  double budgetinitial, double coutreel, int progression, double temperature); // 🆕 updated modifier

    static chantier getchantierById(int id);
    QSqlQueryModel *search(const QString &criteria);
    QSqlQueryModel *sort(const QString &criteria);
    QSqlQueryModel *getEventStatistics();
    bool exportToPdf();

    QVector<QString> verifierAlertes() const;
};

#endif // CHANTIER_H
