#include "connection.h"

Connection::Connection() {}

bool Connection::createconnect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_project_2A");
    db.setUserName("marambns");
    db.setPassword("maram");

    if (db.open()) {
        return true;
    } else {
        qDebug() << "Erreur de connexion : " << db.lastError().text();
        return false;
    }
}

void Connection::closeconnect() {
    QSqlDatabase db = QSqlDatabase::database();
    db.close();
}
