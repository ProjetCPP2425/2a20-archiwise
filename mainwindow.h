#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QTextToSpeech>
#include <QMainWindow>
#include <QStyledItemDelegate>
#include <QDate>
#include <QPainter>

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
    void on_pushButtonExporter_clicked();
    void rappelContratsFinissants();
    void statistique();
    void on_annuler_recherche_clicked();
    void verifierEtModifier();

        void on_pushButton_9_clicked();

    void afficherNombreContratsEnCours();
    void on_recuperer_clicked();
    void on_modifier_clicked();
        void remplirComboBoxAvecIds();

private slots:






    void on_supprimerr_clicked();

    void on_annuler_modification_clicked();

    void on_annuler_ajout_clicked();

    void on_rechercher_clicked();


    void on_recherche_clicked();



private:
    Ui::MainWindow *ui;
    QTextToSpeech *tts;  // Pour la synthèse vocale
    QTimer *timer;

};
#include <QStyledItemDelegate>
#include <QPainter>

class ContratFinissantDelegate : public QStyledItemDelegate {
public:
    ContratFinissantDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override {
        QStyleOptionViewItem opt = option;

        // Vérifie la colonne cachée : la 9ᵉ (index 9) = IS_EXPIRING_SOON
        QModelIndex isExpiringIndex = index.sibling(index.row(), 9); // 9ᵉ colonne
        if (isExpiringIndex.isValid() && isExpiringIndex.data().toInt() == 1) {
            painter->fillRect(option.rect, QColor(255, 200, 200));  // Rouge clair
        }

        QStyledItemDelegate::paint(painter, opt, index);
    }
};

#endif // MAINWINDOW_H
