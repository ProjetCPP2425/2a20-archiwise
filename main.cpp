#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    if (test== true) {
        w.show();
        QMessageBox::information(nullptr, "Connexion", "Connexion réussie à la base de données !");

    } else {
        QMessageBox::critical(nullptr, "Connexion", "Échec de la connexion à la base de données !");

    }

    return a.exec();
}
