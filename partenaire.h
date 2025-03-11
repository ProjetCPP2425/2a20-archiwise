#ifndef PARTENAIRE_H
#define PARTENAIRE_H


#include <QString>             // Corrected from Qstring to QString
#include <QSqlQuery>           // For database queries
#include <QSqlQueryModel>      // For database model
#include <QTableView>          // For displaying data in a table view
#include <QDebug>              // For debug output
#include <QSqlError>           // For error handling

#include <QMessageBox>
#include <QSqlQueryModel>
class Partenaire
{
private:
    int Id;
    QString Nom;
    QString TypePartenaire;
    QString Adresse;
    QString Ville;
    QString ContactPrincipal;
    QString Email;

public:
    // Constructors
    Partenaire();  // Default constructor
    Partenaire(QString Nom, QString TypePartenaire, QString Adresse, QString Ville, QString ContactPrincipal, QString Email);

    // Getters
    int getId() { return Id; }
    QString getNom() { return Nom; }
    QString getTypePartenaire() { return TypePartenaire; }
    QString getAdresse() { return Adresse; }
    QString getVille() { return Ville; }
    QString getContactPrincipal() { return ContactPrincipal; }
    QString getEmail() { return Email; }

    // Setters
    void setId(int id) { Id = id; }
    void setNom(const QString& nom) { Nom = nom; }
    void setTypePartenaire(const QString& typePartenaire) { TypePartenaire = typePartenaire; }
    void setAdresse(const QString& adresse) { Adresse = adresse; }
    void setVille(const QString& ville) { Ville = ville; }
    void setContactPrincipal(const QString& contactPrincipal) { ContactPrincipal = contactPrincipal; }
    void setEmail(const QString& email) { Email = email; }

    // Database functions
    bool ajouter();                 // Function to add a new partner to the database
    QSqlQueryModel* afficher();     // Function to display partners in a table
    bool supprimer(int id);        // Function to delete a partner by ID

    bool recupererParId(int id);  // Récupérer un partenaire par ID
    bool modifier(int id);
    QList<int> recupererTousLesIds();
    // Function to read data from the database and populate QTableView

};

#endif // PARTENAIRE_H
