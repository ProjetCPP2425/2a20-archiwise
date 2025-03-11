#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "materiel.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajmateriel_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;
    Materiel materiel ;    // Modèle pour afficher les matériels
    void afficherMateriel();

};
#endif // MAINWINDOW_H
