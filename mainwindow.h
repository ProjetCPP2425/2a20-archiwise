#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QTextToSpeech>
#include <QMainWindow>
#include <QStyledItemDelegate>
#include <QDate>
#include <QPainter>
#include <QSerialPort>
#include "employe.h"
#include <QSortFilterProxyModel>
#include <QDate>

////////////////////////////////////////////////////////////////////////////hajjouni
#include "chantier.h"
#include "SerialTemperatureManager.h"
#include "projet.h"
#include "client.h"


#include <QChartView>

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


 void verifierPartenaire(const QString &id);


 void sendToArduino(const QString &message);
 void readSerialData();


 void on_switch_partenaire_clicked();

 void on_switch_employe_clicked();



//parrtie mtaa slim
 void on_btn_add_clicked();
 void on_btn_delete_clicked();
 void on_btn_refresh_clicked();
 void on_pdf_clicked();
 void on_btn_stats_clicked();
 void on_btn_tri_clicked();
 void on_btn_recherche_clicked();
 void on_btn_reset_recherche_clicked();
 void showEvent(QShowEvent *event) override;



 //////////////////////////////////////////////////////////////////////////////hajjouni
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

 void on_pushButton_13_clicked();

 void on_pushButton_5_clicked();

 void on_pushButton_ajout_2_clicked();

 void detecterChantiersEnRetard();


 void on_tableView_clicked(const QModelIndex &index);







 void on_btnchantiers_2_clicked();

 void on_pushButton_6_clicked();

 void on_pushButton_9_clicked();

 void on_pushButton_14_clicked();

 void on_pushButton_15_clicked();

 //doudi
 void button_doudi();

 void on_ajmateriel_7_clicked();

 void on_modifier_4_clicked();
 void on_delete_projet_clicked(int id);
 void on_modifier_projet_clicked(Projet p);
 void on_uploadButton_3_clicked();

 void on_pushButton_26_clicked();

 void on_pushButton_27_clicked();

 void on_tri_3_currentTextChanged(const QString &arg1);

 void on_recherche_label_3_textChanged(const QString &arg1);

 void on_pushButton_25_clicked();

 void on_pushButton_24_clicked();

 void on_map_3_clicked();

 void on_btnProjects_2_clicked();

 void on_ajouterClient_3_clicked();

 void on_pushButton_29_clicked();

 void on_pushButton_28_clicked();

 ////////maram

 void on_lineEdit_id_clicked();


 void on_ajouterClient_clicked();

 void on_modifierClient_clicked();
 void on_supprimerClient_clicked(int id);

 void on_exportPdfButton_clicked();

 void on_showStatsButton_clicked_clicked();

 void on_exportPdfButton_2_clicked();
 void button_maram();
 void setupHistoriqueTable() ;


 void on_lineEdit_recherche_textChanged(const QString &arg1);

 void on_pushButton_22_clicked();

 void on_pushButton_23_clicked();

 void on_pushButton_30_clicked();

 void on_btnclients_2_clicked();

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

    Employe emp;



    /////////////////////////////////////////////////hajjouni
    chantier c;
    int id;
    SerialTemperatureManager *temperatureManager;

////////////////////////////////doudiii
    Projet ptmp;
    bool imageEstValide = false;
    QString cheminImageValide;
    //Arduino A;
////////////////////////maaraaam
    Client client;
    QSqlQueryModel *model;
    int currentClientId;
    QSortFilterProxyModel *proxyModel1;
    void exportToPdf();  // Méthode pour l'export PDF
    void setupTableView1();
    void setupStatsChart(QWidget *parentWidget);  // Modification ici
    void updateClientStats();
    QChartView *m_chartView;  // Ajoute ce membre pour garder une référence


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
