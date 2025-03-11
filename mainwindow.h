#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouterClient_clicked();
    void on_supprimerClient_clicked(int id);
    void on_pushButton_2_clicked();
    void button_maram();
    void on_lineEdit_id_clicked();
    void on_modifierClient_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    Client client;
    QSqlQueryModel *model;
    int currentClientId;


};

#endif // MAINWINDOW_H
