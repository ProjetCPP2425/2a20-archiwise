#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QTextToSpeech>
#include <QMainWindow>
#include <QStyledItemDelegate>
#include <QDate>
#include <QPainter>
#include <QSerialPort>

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QDate>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
     void resizeEvent(QResizeEvent *event) override;


    ~MainWindow();
public slots:
    void on_btnAjouter_clicked();


     void on_modifier_clicked();
    void on_annuler_modification_clicked();
       void on_annuler_ajout_clicked();
      void afficherStatistiquesContrats();
        void on_annuler_recherche_clicked();
      void on_pushButtonExporter_clicked();
         void rappelContratsFinissants();
      void afficherStatistiquesPartenaires();
         void on_recherche_clicked();
    void onDeleteClicked(int row);
    void onEditClicked(int row);




    void setupTableView();


    void setupSerialPort();


private slots:

    void on_nouvelle_disccusion_clicked();
    void initialiserCompleter();

 void on_sendButton_clicked();
    void ajouterMessageUtilisateur(const QString &message);
 void ajouterMessageBot(const QString &message);
    void appelerOpenAI(const QString &question);

 void verifierPartenaire(const QString &id);


 void sendToArduino(const QString &message);
 void readSerialData();

    void on_sendButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QTextToSpeech *tts;  // Pour la synthèse vocale
    QTimer *timer;
    int currentPartnerId;
    Qt::SortOrder currentSortOrder = Qt::AscendingOrder;
    QString currentSortColumn = "";
     QSortFilterProxyModel *proxyModel;
     QStringList botResponses;
     QSerialPort serialPort;
    void processUserInput(const QString &input); // Fonction pour traiter les entrées de l'utilisateur
    void addBotMessage(const QString &message);


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
