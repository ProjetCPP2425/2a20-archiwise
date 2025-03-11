#include "connection.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c; // Création d'un objet connexion

    bool test = c.createconnect(); // Tentative de connexion
    MainWindow w;

    if (test) {
        QMessageBox::information(nullptr, "Connexion", "Connexion réussie à la base de données !");
        w.show();
    } else {
        QMessageBox::critical(nullptr, "Connexion", "Échec de la connexion à la base de données !");
        return 1; // Quitte le programme si la connexion échoue
    }

    return a.exec();
}
