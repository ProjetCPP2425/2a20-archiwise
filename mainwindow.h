#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QSqlQueryModel>
#include "client.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

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
    void on_lineEdit_recherche_textChanged(const QString &arg1);
    //void on_pushButton_6_clicked();
    //void on_on_triDate_clicked_clicked();
    void on_exportPdfButton_clicked();  // Nouveau slot pour l'export PDF
     void trierClients(int column, Qt::SortOrder order);
    //void on_statsTabSelected();
    void on_showStatsButton_clicked_clicked();
    void on_staClient_4_clicked_clicked();

private:
    Ui::MainWindow *ui;
    Client client;
    QSqlQueryModel *model;
    int currentClientId;
    QSortFilterProxyModel *proxyModel;

    void exportToPdf();  // Méthode pour l'export PDF
    void setupTableView();
    void setupStatsChart(QWidget *parentWidget);  // Modification ici
    void updateClientStats();
    QChartView *m_chartView;  // Ajoute ce membre pour garder une référence
};

#endif // MAINWINDOW_H
