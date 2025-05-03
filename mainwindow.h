#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "projet.h"
#include "arduino.h"
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
    QSqlDatabase db;

private slots:
    void on_ajmateriel_3_clicked();
    void on_ajouterClient_clicked();
    void button_doudi();
    void on_modifier_projet_clicked(Projet p);
    void on_delete_projet_clicked(int id);
    void on_pushButton_3_clicked();
    void on_modifier_clicked();
    //QSqlQueryModel * recherche(QString searchText);
    //void on_recherche_btn_clicked();

    void on_tri_currentTextChanged(const QString &arg1);

    void on_recherche_label_textChanged(const QString &arg1);

    void on_back_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_map_clicked();

    void on_uploadButton_clicked();
    void detecterBadge();

private:
    Ui::MainWindow *ui;
    Projet ptmp;
    QString originalnom;
    QString originaldescription;
    QString originalchefDeProjet;
    QString originalstatut;
    QDate originaldateDebut;
    QDate originaldateFinPrevu;
    float originalbudget;
    bool imageEstValide = false;
    QString cheminImageValide;
    Arduino A;


signals:
    void setLocationMarking(QVariant,QVariant);
    void setCenterPosition(QVariant,QVariant);
};
#endif // MAINWINDOW_H

