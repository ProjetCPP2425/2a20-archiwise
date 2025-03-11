#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
public slots:
    void on_btnAjouter_clicked();


    void verifierEtModifier();

        void on_pushButton_9_clicked();

    void on_recuperer_clicked();
    void on_modifier_clicked();
        void remplirComboBoxAvecIds();

private slots:






    void on_supprimerr_clicked();

    void on_annuler_modification_clicked();

    void on_annuler_ajout_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
