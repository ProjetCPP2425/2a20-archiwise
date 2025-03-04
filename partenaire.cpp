#include "partenaire.h"

Partenaire::Partenaire(QString Nom,QString TypePartenaire,QString Adresse,QString Ville,QString ContactPrincipal,QString Email){
        this->Nom=Nom;
        this->TypePartenaire=TypePartenaire;
        this->Adresse=Adresse;
        this->Ville=Ville;
        this->ContactPrincipal=ContactPrincipal;
        this->Email=Email;
    }


    bool Partenaire::ajouter()
    {
        QSqlQuery query;
        QString res = QString:: number(id);
        //prepare() prend la requête en paramètre pour la préparer à l'exécution.
        query.prepare "insert into Partenaires (ID, NOM, TYPEPARTENAIRE, ADRESSE,VILLE ,CONTRATPRINCIPAL,EMAIL)" values (:id, :nom, :prenom ,:typepartenaire, :adresse,:ville,:contratprincipal,:email)");
            //Création des variables liées
            query.bindValue(":ID", res);
        query.bindValue(":NOM", nom);
        query.bindValue(":prenom", prenom);
        return query.exec(); //exec() envoie la requête pour l'exécuter
    }
    etudiant.cpp
