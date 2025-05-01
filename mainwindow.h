#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    // Constructor
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void showEvent(QShowEvent *event) override;
private slots:
    void on_btn_add_clicked();
    void on_btn_delete_clicked();
    void on_btn_refresh_clicked();
     void on_pdf_clicked();
    void on_btn_stats_clicked();
     void on_btn_tri_clicked();
    void on_btn_recherche_clicked();
     void on_btn_reset_recherche_clicked();

private:
    Ui::MainWindow *ui;
    Employe emp;
};

#endif // MAINWINDOW_H
