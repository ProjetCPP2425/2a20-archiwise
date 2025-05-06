#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "materiel.h"
#include <QPrinter>
#include "QPainter"
#include <QtCharts/QChartView>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void afficherListeMaterielsCritiques();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajmateriel_3_clicked();
    void on_btnSupprimer_clicked();
    void on_pushButton_clicked();
    // void button_maryem();
    void on_pushButton_9_clicked();
    // void on_pushButton_2_clicked(); // Annuler ajout
    //void on_pushButton_8_clicked(); // Annuler modification
    void on_pushButton_10_clicked();

    void verifierStockAuto();
    void on_pushButton_3_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_comboBox_tri_currentIndexChanged(int index);
    void on_recherche_textChanged(const QString &text);
    void on_btn_export_pdf_clicked();
    void on_pushButton_genererQR_clicked();


    // void on_pushButtonExportPDF_clicked();
    // Nouvelle méthode pour l'export PDF

    void on_showStatsButton_clicked();

private:
    Ui::MainWindow *ui;
    QChartView *m_chartView = nullptr;
    QSqlQueryModel *model;
    Materiel materiel ;    // Modèle pour afficher les matériels
    void afficherMateriel();
    void remplirComboBox();
    void     remplirComboBoxEtats();
    void setupStatsChart(QWidget *parentWidget);
    void updateMaterielStats();

    void afficherStatistiques();
    QImage generateQRCodeImage(const QString &text, int size);

};
#endif // MAINWINDOW_H
