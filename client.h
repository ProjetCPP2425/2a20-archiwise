#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>


enum class ClientType {
    Particulier,
    Entreprise,
    Premium
};

class Client {
public:

    // Constructeurs
    Client();
    Client(QString nom, QString prenom, QString adresse, QString tel, ClientType type, QDate dateInscription);

    // Getters
    int get_id() const { return id; }
    QString get_nom() const { return nom; }
    QString get_prenom() const { return prenom; }
    QString get_adresse() const { return adresse; }
    QString get_tel() const { return tel; }
    ClientType get_type() const { return type; }
    QString get_typeString() const;
    QDate get_dateInscription() const { return dateInscription; }

    // Setters
    void set_id(int id) { this->id = id; }
    void set_nom(const QString &nom) { this->nom = nom; }
    void set_prenom(const QString &prenom) { this->prenom = prenom; }
    void set_adresse(const QString &adresse) { this->adresse = adresse; }
    void set_tel(const QString &tel) { this->tel = tel; }
    void set_type(ClientType type) { this->type = type; }
    void set_type(const QString &typeStr);
    void set_dateInscription(const QDate &dateInscription) { this->dateInscription = dateInscription; }

    // Fonctionnalités
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier(int id);
    QSqlQueryModel* rechercher(const QString &critere);
    Client getclientById(int id);
    QSqlQueryModel* afficherHistorique();
    bool logAction(const QString &action, int clientId, const QString &details);


private:
    int id;
    QString nom;
    QString prenom;
    QString adresse;
    QString tel;
    ClientType type;
    QDate dateInscription;

};


#endif // CLIENT_H
