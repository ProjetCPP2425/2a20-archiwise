#ifndef PARTENAIRE_H
#define PARTENAIRE_H
#include <Qstring>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Partenaire
{
    int Id;
    QString Nom;
    QString TypePartenaire;
    QString Adresse;
    QString Ville;
    QString ContactPrincipal;
    QString Email;

public:
    Partenaire();
    Partenaire(QString Nom,QString TypePartenaire,QString Adresse,QString Ville,QString ContactPrincipal,QString Email);
    int getId(){return Id;}
    QString getNom(){return Nom;}
    QString getTypePartenaire(){return TypePartenaire;}
    QString getAdresse(){return Adresse;}
    QString getVille(){return Ville;}
    QString getContactPrincipal(){return ContactPrincipal;}
    QString getEmail(){return Email;}


    void setId(int id) { Id = id; }
    void setNom(const QString& nom) { Nom = nom; }
    void setTypePartenaire(const QString& typePartenaire) { TypePartenaire = typePartenaire; }
    void setAdresse(const QString& adresse) { Adresse = adresse; }
    void setVille(const QString& ville) { Ville = ville; }
    void setContactPrincipal(const QString& contactPrincipal) { ContactPrincipal = contactPrincipal; }
    void setEmail(const QString& email) { Email = email; }

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int);
};

#endif // PARTENAIRE_H
