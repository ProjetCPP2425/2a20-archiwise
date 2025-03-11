#include "connection.h"

connection::connection()
{

}

bool connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A20");//inserer le nom de la source de données
    db.setUserName("slouma");//inserer nom de l'utilisateur
    db.setPassword("123");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;


    return  test;
}
void connection::closeconnection(){db.close();}
