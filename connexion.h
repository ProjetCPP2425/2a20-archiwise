#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection(); // Constructeur
    bool createconnect(); // Établit la connexion à la base de données
    void closeconnect();  // Ferme la connexion à la base de données
};

#endif // CONNECTION_H
