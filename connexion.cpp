#include "connexion.h"

// Constructeur par défaut
Connection::Connection() {}

// Méthode pour établir la connexion à la base de données
bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    // Nom de la source de données (DSN)
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("maryem");  // Remplace par ton utilisateur SQL
    db.setPassword("maryem");  // Remplace par ton mot de passe SQL

    if (db.open()) {
        test = true;
    } else {
        throw QString("Erreur de connexion : " + db.lastError().text());
    }

    return test;
}

// Méthode pour fermer la connexion
void Connection::closeconnect()
{
    QSqlDatabase db = QSqlDatabase::database();
    db.close();
}
