#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chantier.h"
#include "SerialTemperatureManager.h"

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

    void button_hajjouni();
    void on_pushButton_ajout_clicked();
    void on_modifier_chantier_clicked(chantier c);
    void on_delete_chantier_clicked(int id);

    void on_pushButton_clicked();
    void on_pushButton_3_clicked();



    void on_pushButton_8_clicked();
    void on_pushButton_2_clicked();


    void on_recherche_input_textChanged(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_ajout_2_clicked();

    void detecterChantiersEnRetard();


    void on_tableView_clicked(const QModelIndex &index);




private:
    Ui::MainWindow *ui;
    chantier c;
    int id;
    SerialTemperatureManager *temperatureManager;
};
#endif // MAINWINDOW_H
