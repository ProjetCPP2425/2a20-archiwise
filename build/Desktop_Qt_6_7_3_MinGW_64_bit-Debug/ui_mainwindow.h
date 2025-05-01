/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *maincontent_2;
    QPushButton *pushButton_4;
    QLabel *label_5;
    QPushButton *btn_stats;
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *btn_add;
    QLineEdit *le_nom;
    QLineEdit *le_poste;
    QLineEdit *le_prenom;
    QLineEdit *le_salaire;
    QLineEdit *statut;
    QLineEdit *le_numero;
    QLineEdit *le_email;
    QLineEdit *le_id;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *le_pass;
    QLabel *label_11;
    QPushButton *btn_tri;
    QLineEdit *le_recherche_nom;
    QPushButton *btn_recherche;
    QPushButton *btn_reset_recherche;
    QPushButton *btn_dashboard;
    QWidget *BarChartWidget;
    QWidget *page_2;
    QLineEdit *lineEdit;
    QWidget *side;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *titlelabel_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnhome_2;
    QPushButton *btnProjects_2;
    QPushButton *btnclients_2;
    QPushButton *btnemployee_2;
    QPushButton *btnchantiers_2;
    QPushButton *btnmateriels_2;
    QPushButton *btnmateriels_3;
    QSpacerItem *verticalSpacer_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1203, 728);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(240, -20, 1021, 691));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName("page");
        maincontent_2 = new QWidget(page);
        maincontent_2->setObjectName("maincontent_2");
        maincontent_2->setGeometry(QRect(-60, 20, 1061, 751));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(16);
        sizePolicy.setHeightForWidth(maincontent_2->sizePolicy().hasHeightForWidth());
        maincontent_2->setSizePolicy(sizePolicy);
        maincontent_2->setStyleSheet(QString::fromUtf8("QWidget#maincontent\n"
" {\n"
"    background-color: white;\n"
"}\n"
""));
        pushButton_4 = new QPushButton(maincontent_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(120, 20, 121, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #007bff;  /* Bleu */\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 12pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0056b3;  /* Bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
""));
        label_5 = new QLabel(maincontent_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 200, 41, 31));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #0f3460;\n"
"    padding-left: 8px;\n"
"}\n"
""));
        btn_stats = new QPushButton(maincontent_2);
        btn_stats->setObjectName("btn_stats");
        btn_stats->setGeometry(QRect(320, 20, 121, 41));
        btn_stats->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #007bff;  /* Bleu */\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 12pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0056b3;  /* Bleu fonc\303\251 au survol */\n"
"}\n"
""));
        label = new QLabel(maincontent_2);
        label->setObjectName("label");
        label->setGeometry(QRect(440, 400, 191, 31));
        label->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
        tableWidget = new QTableWidget(maincontent_2);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(80, 440, 881, 211));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    border: 2px solid #007bff;\n"
"    border-radius: 5px;\n"
"    gridline-color: #007bff;\n"
"    font-size: 12pt;\n"
"    font-weight: bold;\n"
"    background-color: white;  /* Add this */\n"
"    color: black;           /* Add this */\n"
"}\n"
"\n"
"/* Add this to make sure items are visible */\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #007bff;\n"
"    border: 1px solid #0056b3;\n"
"}\n"
"\n"
"/* Header Styling */\n"
"QHeaderView::section {\n"
"    background-color: #007bff; /* Blue header */\n"
"    color: black;\n"
"    padding: 8px;\n"
"    border: 1px solid #0056b3; /* Dark blue border */\n"
"    font-size: 12pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Table Cells */\n"
"QTableWidget::item {\n"
"    padding: 8px;\n"
"	color: black\n"
"text-color:black;\n"
"}\n"
"\n"
"/* Selected Row Styling */\n"
"QTableWidget::item:selected {\n"
"    background-color: #0056b3; /* Darker blue */\n"
"    color: black;\n"
"}\n"
""));
        btn_add = new QPushButton(maincontent_2);
        btn_add->setObjectName("btn_add");
        btn_add->setGeometry(QRect(130, 70, 201, 41));
        btn_add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #007bff;  /* Bleu */\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 12pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0056b3;  /* Bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
""));
        le_nom = new QLineEdit(maincontent_2);
        le_nom->setObjectName("le_nom");
        le_nom->setGeometry(QRect(150, 160, 171, 31));
        le_nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f5f5f5;  /* Fond gris clair moderne */\n"
"    border: 2px solid #0f3460;  /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 8px;  /* Coins arrondis */\n"
"    padding: 8px 12px;  /* Espacement du texte */\n"
"    font-size: 14px;\n"
"    color: #333;  /* Couleur du texte */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #e94560;  /* Bordure rouge clair quand on clique */\n"
"    background-color: white;  /* Fond blanc au focus */\n"
"}\n"
""));
        le_poste = new QLineEdit(maincontent_2);
        le_poste->setObjectName("le_poste");
        le_poste->setGeometry(QRect(150, 220, 171, 31));
        le_poste->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f5f5f5;  /* Fond gris clair moderne */\n"
"    border: 2px solid #0f3460;  /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 8px;  /* Coins arrondis */\n"
"    padding: 8px 12px;  /* Espacement du texte */\n"
"    font-size: 14px;\n"
"    color: #333;  /* Couleur du texte */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #e94560;  /* Bordure rouge clair quand on clique */\n"
"    background-color: white;  /* Fond blanc au focus */\n"
"}\n"
""));
        le_prenom = new QLineEdit(maincontent_2);
        le_prenom->setObjectName("le_prenom");
        le_prenom->setGeometry(QRect(150, 190, 171, 31));
        le_prenom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f5f5f5;  /* Fond gris clair moderne */\n"
"    border: 2px solid #0f3460;  /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 8px;  /* Coins arrondis */\n"
"    padding: 8px 12px;  /* Espacement du texte */\n"
"    font-size: 14px;\n"
"    color: #333;  /* Couleur du texte */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #e94560;  /* Bordure rouge clair quand on clique */\n"
"    background-color: white;  /* Fond blanc au focus */\n"
"}\n"
""));
        le_salaire = new QLineEdit(maincontent_2);
        le_salaire->setObjectName("le_salaire");
        le_salaire->setGeometry(QRect(150, 250, 171, 31));
        le_salaire->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f5f5f5;  /* Fond gris clair moderne */\n"
"    border: 2px solid #0f3460;  /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 8px;  /* Coins arrondis */\n"
"    padding: 8px 12px;  /* Espacement du texte */\n"
"    font-size: 14px;\n"
"    color: #333;  /* Couleur du texte */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #e94560;  /* Bordure rouge clair quand on clique */\n"
"    background-color: white;  /* Fond blanc au focus */\n"
"}\n"
""));
        statut = new QLineEdit(maincontent_2);
        statut->setObjectName("statut");
        statut->setGeometry(QRect(150, 280, 171, 31));
        statut->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f5f5f5;  /* Fond gris clair moderne */\n"
"    border: 2px solid #0f3460;  /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 8px;  /* Coins arrondis */\n"
"    padding: 8px 12px;  /* Espacement du texte */\n"
"    font-size: 14px;\n"
"    color: #333;  /* Couleur du texte */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #e94560;  /* Bordure rouge clair quand on clique */\n"
"    background-color: white;  /* Fond blanc au focus */\n"
"}\n"
""));
        le_numero = new QLineEdit(maincontent_2);
        le_numero->setObjectName("le_numero");
        le_numero->setGeometry(QRect(150, 340, 171, 31));
        le_numero->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f5f5f5;  /* Fond gris clair moderne */\n"
"    border: 2px solid #0f3460;  /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 8px;  /* Coins arrondis */\n"
"    padding: 8px 12px;  /* Espacement du texte */\n"
"    font-size: 14px;\n"
"    color: #333;  /* Couleur du texte */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #e94560;  /* Bordure rouge clair quand on clique */\n"
"    background-color: white;  /* Fond blanc au focus */\n"
"}\n"
""));
        le_email = new QLineEdit(maincontent_2);
        le_email->setObjectName("le_email");
        le_email->setGeometry(QRect(150, 310, 171, 31));
        le_email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f5f5f5;  /* Fond gris clair moderne */\n"
"    border: 2px solid #0f3460;  /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 8px;  /* Coins arrondis */\n"
"    padding: 8px 12px;  /* Espacement du texte */\n"
"    font-size: 14px;\n"
"    color: #333;  /* Couleur du texte */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #e94560;  /* Bordure rouge clair quand on clique */\n"
"    background-color: white;  /* Fond blanc au focus */\n"
"}\n"
""));
        le_id = new QLineEdit(maincontent_2);
        le_id->setObjectName("le_id");
        le_id->setGeometry(QRect(150, 130, 171, 31));
        le_id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f5f5f5;  /* Fond gris clair moderne */\n"
"    border: 2px solid #0f3460;  /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 8px;  /* Coins arrondis */\n"
"    padding: 8px 12px;  /* Espacement du texte */\n"
"    font-size: 14px;\n"
"    color: #333;  /* Couleur du texte */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #e94560;  /* Bordure rouge clair quand on clique */\n"
"    background-color: white;  /* Fond blanc au focus */\n"
"}\n"
""));
        label_2 = new QLabel(maincontent_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 130, 31, 21));
        label_2->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
        label_3 = new QLabel(maincontent_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 210, 51, 31));
        label_3->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
        label_4 = new QLabel(maincontent_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 250, 61, 21));
        label_4->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
        label_6 = new QLabel(maincontent_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(70, 280, 51, 21));
        label_6->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
        label_7 = new QLabel(maincontent_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(90, 160, 41, 21));
        label_7->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
        label_8 = new QLabel(maincontent_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(60, 340, 71, 21));
        label_8->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
        label_9 = new QLabel(maincontent_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(70, 310, 51, 21));
        label_9->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
        label_10 = new QLabel(maincontent_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(70, 180, 61, 31));
        label_10->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
        le_pass = new QLineEdit(maincontent_2);
        le_pass->setObjectName("le_pass");
        le_pass->setGeometry(QRect(150, 370, 171, 31));
        le_pass->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f5f5f5;  /* Fond gris clair moderne */\n"
"    border: 2px solid #0f3460;  /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 8px;  /* Coins arrondis */\n"
"    padding: 8px 12px;  /* Espacement du texte */\n"
"    font-size: 14px;\n"
"    color: #333;  /* Couleur du texte */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #e94560;  /* Bordure rouge clair quand on clique */\n"
"    background-color: white;  /* Fond blanc au focus */\n"
"}\n"
""));
        label_11 = new QLabel(maincontent_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(70, 370, 41, 21));
        label_11->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
        btn_tri = new QPushButton(maincontent_2);
        btn_tri->setObjectName("btn_tri");
        btn_tri->setGeometry(QRect(560, 20, 121, 41));
        btn_tri->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #007bff;  /* Bleu */\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 12pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0056b3;  /* Bleu fonc\303\251 au survol */\n"
"}\n"
""));
        le_recherche_nom = new QLineEdit(maincontent_2);
        le_recherche_nom->setObjectName("le_recherche_nom");
        le_recherche_nom->setGeometry(QRect(430, 160, 321, 31));
        le_recherche_nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f5f5f5;  /* Fond gris clair moderne */\n"
"    border: 2px solid #0f3460;  /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 8px;  /* Coins arrondis */\n"
"    padding: 8px 12px;  /* Espacement du texte */\n"
"    font-size: 14px;\n"
"    color: #333;  /* Couleur du texte */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #e94560;  /* Bordure rouge clair quand on clique */\n"
"    background-color: white;  /* Fond blanc au focus */\n"
"}\n"
""));
        btn_recherche = new QPushButton(maincontent_2);
        btn_recherche->setObjectName("btn_recherche");
        btn_recherche->setGeometry(QRect(460, 100, 201, 41));
        btn_recherche->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #007bff;  /* Bleu */\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 12pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0056b3;  /* Bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
""));
        btn_reset_recherche = new QPushButton(maincontent_2);
        btn_reset_recherche->setObjectName("btn_reset_recherche");
        btn_reset_recherche->setGeometry(QRect(760, 160, 141, 31));
        btn_reset_recherche->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #007bff;  /* Bleu */\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 12pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0056b3;  /* Bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
""));
        btn_dashboard = new QPushButton(maincontent_2);
        btn_dashboard->setObjectName("btn_dashboard");
        btn_dashboard->setGeometry(QRect(770, 20, 201, 41));
        btn_dashboard->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #007bff;  /* Bleu */\n"
"    color: white;\n"
"    border-radius: 5px;\n"
"    padding: 8px 15px;\n"
"    font-size: 12pt;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0056b3;  /* Bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
""));
        BarChartWidget = new QWidget(maincontent_2);
        BarChartWidget->setObjectName("BarChartWidget");
        BarChartWidget->setGeometry(QRect(320, 220, 631, 181));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(230, 40, 301, 51));
        stackedWidget->addWidget(page_2);
        side = new QWidget(centralWidget);
        side->setObjectName("side");
        side->setGeometry(QRect(0, -20, 231, 741));
        side->setStyleSheet(QString::fromUtf8("QWidget#side {\n"
"    background-color: #1e1e1e;\n"
"}\n"
""));
        layoutWidget_2 = new QWidget(side);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(9, 19, 211, 521));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titlelabel_2 = new QLabel(layoutWidget_2);
        titlelabel_2->setObjectName("titlelabel_2");
        titlelabel_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font: 18pt \"Segoe UI\";\n"
"    color: white;\n"
"}\n"
""));

        verticalLayout_2->addWidget(titlelabel_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_3);

        btnhome_2 = new QPushButton(layoutWidget_2);
        btnhome_2->setObjectName("btnhome_2");
        btnhome_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0f3460;  /* Bleu fonc\303\251 moderne */\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #0f3460;\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 10px 15px;\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1a5276;  /* Bleu plus clair au survol */\n"
"    border: 2px solid white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e94560; /* Rouge clair au clic */\n"
"    border: 2px solid #e94560;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #e94560;\n"
"    border: 2px solid #e94560;\n"
"    transform: scale(0.95); /* Effet d'appui */\n"
"}\n"
""));

        verticalLayout_2->addWidget(btnhome_2);

        btnProjects_2 = new QPushButton(layoutWidget_2);
        btnProjects_2->setObjectName("btnProjects_2");
        btnProjects_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0f3460;  /* Bleu fonc\303\251 moderne */\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #0f3460;\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 10px 15px;\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1a5276;  /* Bleu plus clair au survol */\n"
"    border: 2px solid white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e94560; /* Rouge clair au clic */\n"
"    border: 2px solid #e94560;\n"
"}\n"
""));

        verticalLayout_2->addWidget(btnProjects_2);

        btnclients_2 = new QPushButton(layoutWidget_2);
        btnclients_2->setObjectName("btnclients_2");
        btnclients_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0f3460;  /* Bleu fonc\303\251 moderne */\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #0f3460;\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 10px 15px;\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1a5276;  /* Bleu plus clair au survol */\n"
"    border: 2px solid white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e94560; /* Rouge clair au clic */\n"
"    border: 2px solid #e94560;\n"
"}\n"
""));

        verticalLayout_2->addWidget(btnclients_2);

        btnemployee_2 = new QPushButton(layoutWidget_2);
        btnemployee_2->setObjectName("btnemployee_2");
        btnemployee_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0f3460;  /* Bleu fonc\303\251 moderne */\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #0f3460;\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 10px 15px;\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1a5276;  /* Bleu plus clair au survol */\n"
"    border: 2px solid white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e94560; /* Rouge clair au clic */\n"
"    border: 2px solid #e94560;\n"
"}\n"
""));

        verticalLayout_2->addWidget(btnemployee_2);

        btnchantiers_2 = new QPushButton(layoutWidget_2);
        btnchantiers_2->setObjectName("btnchantiers_2");
        btnchantiers_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0f3460;  /* Bleu fonc\303\251 moderne */\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #0f3460;\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 10px 15px;\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1a5276;  /* Bleu plus clair au survol */\n"
"    border: 2px solid white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e94560; /* Rouge clair au clic */\n"
"    border: 2px solid #e94560;\n"
"}\n"
""));

        verticalLayout_2->addWidget(btnchantiers_2);

        btnmateriels_2 = new QPushButton(layoutWidget_2);
        btnmateriels_2->setObjectName("btnmateriels_2");
        btnmateriels_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0f3460;  /* Bleu fonc\303\251 moderne */\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #0f3460;\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 10px 15px;\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1a5276;  /* Bleu plus clair au survol */\n"
"    border: 2px solid white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e94560; /* Rouge clair au clic */\n"
"    border: 2px solid #e94560;\n"
"}\n"
""));

        verticalLayout_2->addWidget(btnmateriels_2);

        btnmateriels_3 = new QPushButton(layoutWidget_2);
        btnmateriels_3->setObjectName("btnmateriels_3");
        btnmateriels_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0f3460;  /* Bleu fonc\303\251 moderne */\n"
"    color: white;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #0f3460;\n"
"    border-radius: 8px; /* Coins arrondis */\n"
"    padding: 10px 15px;\n"
"    transition: 0.3s;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1a5276;  /* Bleu plus clair au survol */\n"
"    border: 2px solid white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #e94560; /* Rouge clair au clic */\n"
"    border: 2px solid #e94560;\n"
"}\n"
""));

        verticalLayout_2->addWidget(btnmateriels_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1203, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215", nullptr));
        btn_stats->setText(QCoreApplication::translate("MainWindow", "STAT", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Liste des employ\303\251s", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Numero", nullptr));
        btn_add->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "poste", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "salaire", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "statut", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Numero", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "prenom", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "pass", nullptr));
        btn_tri->setText(QCoreApplication::translate("MainWindow", "TRI", nullptr));
        btn_recherche->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        btn_reset_recherche->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        btn_dashboard->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "               remplir le formulaire ", nullptr));
        titlelabel_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Archi<span style=\" font-weight:700; color:#3282f6;\">Wise</span></p></body></html>", nullptr));
        btnhome_2->setText(QCoreApplication::translate("MainWindow", "\360\237\217\240 Accueil", nullptr));
        btnProjects_2->setText(QCoreApplication::translate("MainWindow", "\360\237\223\202 Projets", nullptr));
        btnclients_2->setText(QCoreApplication::translate("MainWindow", "\360\237\221\245 Clients", nullptr));
        btnemployee_2->setText(QCoreApplication::translate("MainWindow", "\360\237\221\267 Employ\303\251s", nullptr));
        btnchantiers_2->setText(QCoreApplication::translate("MainWindow", "\360\237\217\227\357\270\217 Chantiers", nullptr));
        btnmateriels_2->setText(QCoreApplication::translate("MainWindow", "\360\237\233\240\357\270\217 Mat\303\251riels", nullptr));
        btnmateriels_3->setText(QCoreApplication::translate("MainWindow", "fournisseurs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
