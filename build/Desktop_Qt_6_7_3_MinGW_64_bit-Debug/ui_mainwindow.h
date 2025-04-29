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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *maincontent_2;
    QPushButton *pushButton_4;
    QLabel *label_5;
    QLineEdit *recherche_input;
    QTableView *tableView;
    QPushButton *pushButton_5;
    QLabel *label;
    QPushButton *pushButton_ajout;
    QComboBox *comboBox;
    QPushButton *pushButton_ajout_2;
    QWidget *page_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *nom;
    QLineEdit *adresse;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_10;
    QLabel *label_21;
    QLineEdit *budget;
    QLineEdit *coutr;
    QLabel *label_22;
    QLabel *label_24;
    QDateEdit *datedebut;
    QDateEdit *datefin;
    QDateEdit *datefinr;
    QSpinBox *prog;
    QLineEdit *statut;
    QLabel *label_23;
    QLineEdit *temp;
    QWidget *page_3;
    QStackedWidget *stackedWidget_2;
    QWidget *page_4;
    QWidget *maincontent_3;
    QPushButton *pushButton_6;
    QLabel *label_6;
    QLineEdit *lineEdit_9;
    QTableView *tableView_3;
    QPushButton *pushButton_7;
    QLabel *label_11;
    QPushButton *ajmateriel_4;
    QWidget *page_5;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *nom1;
    QLineEdit *adresse1;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QLabel *label_18;
    QLabel *label_25;
    QLineEdit *budget1;
    QLineEdit *cout1;
    QLabel *label_26;
    QLabel *label_28;
    QDateEdit *datefr1;
    QDateEdit *datef1;
    QDateEdit *dated1;
    QSpinBox *prog1;
    QLineEdit *statut1;
    QLabel *id1;
    QLabel *label_27;
    QLineEdit *temp1;
    QWidget *page_6;
    QStackedWidget *stackedWidget_3;
    QWidget *page_7;
    QWidget *maincontent_4;
    QPushButton *pushButton_9;
    QLabel *label_19;
    QLineEdit *lineEdit_24;
    QLabel *label_20;
    QComboBox *comboBox_4;
    QTableWidget *tableWidget_3;
    QPushButton *pushButton_10;
    QLabel *label_29;
    QPushButton *ajmateriel_5;
    QWidget *page_8;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLineEdit *lineEdit_25;
    QLineEdit *lineEdit_26;
    QLineEdit *lineEdit_27;
    QLineEdit *lineEdit_28;
    QLineEdit *lineEdit_29;
    QLineEdit *lineEdit_30;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLabel *label_36;
    QWidget *page_9;
    QWidget *page_10;
    QLabel *label_stat;
    QPushButton *pushButton_13;
    QWidget *page_11;
    QGraphicsView *graphicsView1;
    QPushButton *pushButton_14;
    QWidget *side;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *titlelabel_2;
    QPushButton *btnhome_2;
    QPushButton *btnProjects_2;
    QPushButton *btnclients_2;
    QPushButton *btnemployee_2;
    QPushButton *btnchantiers_2;
    QPushButton *btnmateriels_2;
    QPushButton *btnmateriels_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1303, 825);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(220, 10, 1061, 691));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName("page");
        maincontent_2 = new QWidget(page);
        maincontent_2->setObjectName("maincontent_2");
        maincontent_2->setGeometry(QRect(-20, 10, 1061, 711));
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
        pushButton_4->setGeometry(QRect(570, 600, 201, 41));
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
        label_5->setGeometry(QRect(740, 110, 91, 41));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #0f3460;\n"
"    padding-left: 8px;\n"
"}\n"
""));
        recherche_input = new QLineEdit(maincontent_2);
        recherche_input->setObjectName("recherche_input");
        recherche_input->setGeometry(QRect(800, 110, 141, 41));
        recherche_input->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        tableView = new QTableView(maincontent_2);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(50, 200, 931, 381));
        tableView->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_5 = new QPushButton(maincontent_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(800, 600, 201, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label->setGeometry(QRect(430, 10, 161, 51));
        label->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
        pushButton_ajout = new QPushButton(maincontent_2);
        pushButton_ajout->setObjectName("pushButton_ajout");
        pushButton_ajout->setGeometry(QRect(60, 600, 201, 41));
        pushButton_ajout->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        comboBox = new QComboBox(maincontent_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(60, 110, 151, 41));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: #f5f5f5;  /* Fond gris clair moderne */\n"
"    border: 2px solid #0f3460;  /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 8px;  /* Coins arrondis */\n"
"    padding: 8px 12px;  /* Espacement du texte */\n"
"    font-size: 14px;\n"
"    color: #333;  /* Couleur du texte */"));
        pushButton_ajout_2 = new QPushButton(maincontent_2);
        pushButton_ajout_2->setObjectName("pushButton_ajout_2");
        pushButton_ajout_2->setGeometry(QRect(290, 600, 201, 41));
        pushButton_ajout_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 110, 141, 31));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 170, 141, 41));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(50, 230, 131, 31));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_7 = new QLabel(page_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(50, 290, 121, 31));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_8 = new QLabel(page_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(50, 350, 121, 41));
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_9 = new QLabel(page_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 430, 141, 31));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        nom = new QLineEdit(page_2);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(190, 100, 301, 51));
        nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        adresse = new QLineEdit(page_2);
        adresse->setObjectName("adresse");
        adresse->setGeometry(QRect(190, 160, 301, 51));
        adresse->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(420, 580, 141, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2196f3; /* Fond bleu */\n"
"    color: white; /* Texte blanc */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espace int\303\251rieur */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1976d2; /* Fond bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #0d47a1; /* Fond bleu tr\303\250s fonc\303\251 au clic */\n"
"}"));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(590, 580, 141, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f44336; /* Fond rouge */\n"
"    color: white; /* Texte blanc */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espace int\303\251rieur */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #d32f2f; /* Fond rouge fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #b71c1c; /* Fond rouge tr\303\250s fonc\303\251 au clic */\n"
"}"));
        label_10 = new QLabel(page_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(350, 20, 231, 51));
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_21 = new QLabel(page_2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(570, 100, 141, 31));
        label_21->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        budget = new QLineEdit(page_2);
        budget->setObjectName("budget");
        budget->setGeometry(QRect(710, 90, 301, 51));
        budget->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        coutr = new QLineEdit(page_2);
        coutr->setObjectName("coutr");
        coutr->setGeometry(QRect(710, 170, 301, 51));
        coutr->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        label_22 = new QLabel(page_2);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(560, 180, 141, 31));
        label_22->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_24 = new QLabel(page_2);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(560, 260, 161, 31));
        label_24->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        datedebut = new QDateEdit(page_2);
        datedebut->setObjectName("datedebut");
        datedebut->setGeometry(QRect(230, 230, 211, 29));
        datedebut->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        datefin = new QDateEdit(page_2);
        datefin->setObjectName("datefin");
        datefin->setEnabled(false);
        datefin->setGeometry(QRect(230, 290, 211, 29));
        datefin->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        datefinr = new QDateEdit(page_2);
        datefinr->setObjectName("datefinr");
        datefinr->setGeometry(QRect(230, 360, 211, 29));
        datefinr->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        prog = new QSpinBox(page_2);
        prog->setObjectName("prog");
        prog->setGeometry(QRect(760, 260, 211, 29));
        prog->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        prog->setMaximum(100);
        statut = new QLineEdit(page_2);
        statut->setObjectName("statut");
        statut->setGeometry(QRect(190, 420, 301, 51));
        statut->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        label_23 = new QLabel(page_2);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(580, 360, 101, 31));
        label_23->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        temp = new QLineEdit(page_2);
        temp->setObjectName("temp");
        temp->setGeometry(QRect(710, 350, 301, 51));
        temp->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget_2 = new QStackedWidget(page_3);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(0, 0, 1061, 691));
        stackedWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        maincontent_3 = new QWidget(page_4);
        maincontent_3->setObjectName("maincontent_3");
        maincontent_3->setGeometry(QRect(-20, 10, 1061, 711));
        sizePolicy.setHeightForWidth(maincontent_3->sizePolicy().hasHeightForWidth());
        maincontent_3->setSizePolicy(sizePolicy);
        maincontent_3->setStyleSheet(QString::fromUtf8("QWidget#maincontent\n"
" {\n"
"    background-color: white;\n"
"}\n"
""));
        pushButton_6 = new QPushButton(maincontent_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(570, 600, 201, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_6 = new QLabel(maincontent_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(810, 140, 81, 31));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #0f3460;\n"
"    padding-left: 8px;\n"
"}\n"
""));
        lineEdit_9 = new QLineEdit(maincontent_3);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(860, 140, 131, 31));
        lineEdit_9->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        tableView_3 = new QTableView(maincontent_3);
        tableView_3->setObjectName("tableView_3");
        tableView_3->setGeometry(QRect(50, 190, 931, 381));
        tableView_3->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #ffffff; /* Fond blanc pour un look \303\251pur\303\251 */\n"
"    border: 2px solid #e0e0e0; /* Bordure grise l\303\251g\303\250re */\n"
"    gridline-color: #e0e0e0; /* Lignes de grille gris clair */\n"
"    selection-background-color: #757575; /* Couleur de s\303\251lection grise */\n"
"    selection-color: white; /* Texte en blanc sur la s\303\251lection */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    border-radius: 8px; /* Coins arrondis pour le tableau */\n"
"    padding: 5px; /* Espace int\303\251rieur */\n"
"    alternate-background-color: #f5f5f5; /* Couleur alternative pour les lignes */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #616161; /* En-t\303\252tes en gris fonc\303\251 */\n"
"    color: white; /* Texte blanc */\n"
"    font-weight: bold;\n"
"    padding: 10px; /* Espacement dans les en-t\303\252tes */\n"
"    border: none; /* Supprimer les bordures par d\303\251faut */\n"
"    border-bottom: 2px solid #424242; /* Ligne d"
                        "e s\303\251paration sous l'en-t\303\252te */\n"
"    border-radius: 4px; /* Coins l\303\251g\303\250rement arrondis pour les en-t\303\252tes */\n"
"    font-size: 15px; /* Taille du texte des en-t\303\252tes */\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 8px; /* Espacement dans les cellules */\n"
"    border-bottom: 1px solid #e0e0e0; /* S\303\251paration douce des lignes */\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #eeeeee; /* Couleur de survol gris clair */\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #757575; /* Couleur de s\303\251lection grise */\n"
"    color: white; /* Texte en blanc sur la s\303\251lection */\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background-color: #ffffff; /* Fond de la barre de d\303\251filement */\n"
"    width: 12px; /* Largeur de la barre de d\303\251filement */\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #757575; /* Couleur de la poign\303\251e grise */\n"
""
                        "    border-radius: 6px; /* Coins arrondis pour la poign\303\251e */\n"
"    min-height: 20px; /* Hauteur minimale de la poign\303\251e */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    background: none; /* Supprimer les fl\303\250ches de d\303\251filement */\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical {\n"
"    background: none; /* Supprimer l'arri\303\250re-plan de la barre */\n"
"}"));
        pushButton_7 = new QPushButton(maincontent_3);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(800, 600, 201, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_11 = new QLabel(maincontent_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(430, 50, 191, 31));
        label_11->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
        ajmateriel_4 = new QPushButton(maincontent_3);
        ajmateriel_4->setObjectName("ajmateriel_4");
        ajmateriel_4->setGeometry(QRect(50, 130, 201, 41));
        ajmateriel_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        stackedWidget_2->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        label_12 = new QLabel(page_5);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(50, 110, 141, 31));
        label_12->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_13 = new QLabel(page_5);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(50, 170, 141, 41));
        label_13->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_14 = new QLabel(page_5);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(50, 230, 131, 31));
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_15 = new QLabel(page_5);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(50, 290, 121, 31));
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_16 = new QLabel(page_5);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(50, 350, 121, 41));
        label_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_17 = new QLabel(page_5);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(40, 430, 141, 31));
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        nom1 = new QLineEdit(page_5);
        nom1->setObjectName("nom1");
        nom1->setGeometry(QRect(190, 100, 301, 51));
        nom1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        adresse1 = new QLineEdit(page_5);
        adresse1->setObjectName("adresse1");
        adresse1->setGeometry(QRect(190, 160, 301, 51));
        adresse1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        pushButton_3 = new QPushButton(page_5);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(420, 580, 141, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2196f3; /* Fond bleu */\n"
"    color: white; /* Texte blanc */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espace int\303\251rieur */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1976d2; /* Fond bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #0d47a1; /* Fond bleu tr\303\250s fonc\303\251 au clic */\n"
"}"));
        pushButton_8 = new QPushButton(page_5);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(590, 580, 141, 41));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f44336; /* Fond rouge */\n"
"    color: white; /* Texte blanc */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espace int\303\251rieur */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #d32f2f; /* Fond rouge fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #b71c1c; /* Fond rouge tr\303\250s fonc\303\251 au clic */\n"
"}"));
        label_18 = new QLabel(page_5);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(350, 20, 231, 51));
        label_18->setMaximumSize(QSize(231, 51));
        label_18->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(6, 81, 255);\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_25 = new QLabel(page_5);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(570, 100, 141, 31));
        label_25->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        budget1 = new QLineEdit(page_5);
        budget1->setObjectName("budget1");
        budget1->setGeometry(QRect(710, 90, 301, 51));
        budget1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        cout1 = new QLineEdit(page_5);
        cout1->setObjectName("cout1");
        cout1->setGeometry(QRect(710, 170, 301, 51));
        cout1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        label_26 = new QLabel(page_5);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(560, 180, 141, 31));
        label_26->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_28 = new QLabel(page_5);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(560, 260, 161, 31));
        label_28->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        datefr1 = new QDateEdit(page_5);
        datefr1->setObjectName("datefr1");
        datefr1->setGeometry(QRect(250, 350, 201, 29));
        datefr1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        datef1 = new QDateEdit(page_5);
        datef1->setObjectName("datef1");
        datef1->setEnabled(false);
        datef1->setGeometry(QRect(250, 290, 201, 29));
        datef1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        dated1 = new QDateEdit(page_5);
        dated1->setObjectName("dated1");
        dated1->setGeometry(QRect(250, 240, 201, 29));
        dated1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        prog1 = new QSpinBox(page_5);
        prog1->setObjectName("prog1");
        prog1->setGeometry(QRect(760, 260, 181, 29));
        prog1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        prog1->setMaximum(100);
        statut1 = new QLineEdit(page_5);
        statut1->setObjectName("statut1");
        statut1->setGeometry(QRect(190, 420, 301, 51));
        statut1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        id1 = new QLabel(page_5);
        id1->setObjectName("id1");
        id1->setEnabled(false);
        id1->setGeometry(QRect(660, 330, 141, 31));
        id1->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_27 = new QLabel(page_5);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(560, 380, 91, 31));
        label_27->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        temp1 = new QLineEdit(page_5);
        temp1->setObjectName("temp1");
        temp1->setGeometry(QRect(670, 370, 301, 51));
        temp1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        stackedWidget_2->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        stackedWidget_3 = new QStackedWidget(page_6);
        stackedWidget_3->setObjectName("stackedWidget_3");
        stackedWidget_3->setGeometry(QRect(0, 0, 1021, 691));
        stackedWidget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        maincontent_4 = new QWidget(page_7);
        maincontent_4->setObjectName("maincontent_4");
        maincontent_4->setGeometry(QRect(-20, 10, 1061, 711));
        sizePolicy.setHeightForWidth(maincontent_4->sizePolicy().hasHeightForWidth());
        maincontent_4->setSizePolicy(sizePolicy);
        maincontent_4->setStyleSheet(QString::fromUtf8("QWidget#maincontent\n"
" {\n"
"    background-color: white;\n"
"}\n"
""));
        pushButton_9 = new QPushButton(maincontent_4);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(570, 600, 201, 41));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_19 = new QLabel(maincontent_4);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(810, 140, 81, 31));
        label_19->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #0f3460;\n"
"    padding-left: 8px;\n"
"}\n"
""));
        lineEdit_24 = new QLineEdit(maincontent_4);
        lineEdit_24->setObjectName("lineEdit_24");
        lineEdit_24->setGeometry(QRect(860, 140, 131, 31));
        lineEdit_24->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_20 = new QLabel(maincontent_4);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(510, 140, 63, 21));
        comboBox_4 = new QComboBox(maincontent_4);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(550, 140, 76, 26));
        comboBox_4->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #f5f5f5;  /* Fond gris clair */\n"
"    border: 2px solid #0f3460;  /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 8px;  /* Coins arrondis */\n"
"    padding: 5px 10px;  /* Espacement interne */\n"
"    font-size: 14px;\n"
"    color: #333;  /* Texte noir */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"    width: 25px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(dropdown-icon.png);  /* Ic\303\264ne personnalis\303\251e */\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;\n"
"    border: 1px solid #0f3460;  /* Bordure bleu fonc\303\251 */\n"
"    selection-background-color: #e94560;  /* Fond rouge clair au survol */\n"
"    selection-color: white;  /* Texte blanc */\n"
"    padding: 5px;\n"
"}\n"
""));
        tableWidget_3 = new QTableWidget(maincontent_4);
        if (tableWidget_3->columnCount() < 7)
            tableWidget_3->setColumnCount(7);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        QFont font;
        font.setFamilies({QString::fromUtf8("Sans Serif Collection")});
        font.setBold(true);
        font.setStyleStrategy(QFont::PreferDefault);
        font.setHintingPreference(QFont::PreferDefaultHinting);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        __qtablewidgetitem->setForeground(brush);
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font1;
        font1.setBold(true);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        __qtablewidgetitem1->setBackground(QColor(152, 152, 152));
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font2);
        tableWidget_3->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget_3->rowCount() < 5)
            tableWidget_3->setRowCount(5);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::WeatherShowers));
        QBrush brush1(QColor(155, 144, 155, 255));
        brush1.setStyle(Qt::Dense1Pattern);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setForeground(brush1);
        __qtablewidgetitem7->setIcon(icon);
        tableWidget_3->setItem(0, 0, __qtablewidgetitem7);
        QFont font3;
        font3.setStrikeOut(false);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font3);
        tableWidget_3->setItem(0, 1, __qtablewidgetitem8);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::NoBrush);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::NoBrush);
        QFont font4;
        font4.setItalic(false);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font4);
        __qtablewidgetitem9->setBackground(brush3);
        __qtablewidgetitem9->setForeground(brush2);
        tableWidget_3->setItem(1, 0, __qtablewidgetitem9);
        tableWidget_3->setObjectName("tableWidget_3");
        tableWidget_3->setGeometry(QRect(50, 190, 931, 381));
        tableWidget_3->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #ffffff; /* Fond blanc pour un look \303\251pur\303\251 */\n"
"    border: 2px solid #e0e0e0; /* Bordure grise l\303\251g\303\250re */\n"
"    gridline-color: #e0e0e0; /* Lignes de grille gris clair */\n"
"    selection-background-color: #757575; /* Couleur de s\303\251lection grise */\n"
"    selection-color: white; /* Texte en blanc sur la s\303\251lection */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    border-radius: 8px; /* Coins arrondis pour le tableau */\n"
"    padding: 5px; /* Espace int\303\251rieur */\n"
"    alternate-background-color: #f5f5f5; /* Couleur alternative pour les lignes */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #616161; /* En-t\303\252tes en gris fonc\303\251 */\n"
"    color: white; /* Texte blanc */\n"
"    font-weight: bold;\n"
"    padding: 10px; /* Espacement dans les en-t\303\252tes */\n"
"    border: none; /* Supprimer les bordures par d\303\251faut */\n"
"    border-bottom: 2px solid #424242; /* Ligne d"
                        "e s\303\251paration sous l'en-t\303\252te */\n"
"    border-radius: 4px; /* Coins l\303\251g\303\250rement arrondis pour les en-t\303\252tes */\n"
"    font-size: 15px; /* Taille du texte des en-t\303\252tes */\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 8px; /* Espacement dans les cellules */\n"
"    border-bottom: 1px solid #e0e0e0; /* S\303\251paration douce des lignes */\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #eeeeee; /* Couleur de survol gris clair */\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #757575; /* Couleur de s\303\251lection grise */\n"
"    color: white; /* Texte en blanc sur la s\303\251lection */\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background-color: #ffffff; /* Fond de la barre de d\303\251filement */\n"
"    width: 12px; /* Largeur de la barre de d\303\251filement */\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background-color: #757575; /* Couleur de la poign\303\251e grise */\n"
""
                        "    border-radius: 6px; /* Coins arrondis pour la poign\303\251e */\n"
"    min-height: 20px; /* Hauteur minimale de la poign\303\251e */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    background: none; /* Supprimer les fl\303\250ches de d\303\251filement */\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical {\n"
"    background: none; /* Supprimer l'arri\303\250re-plan de la barre */\n"
"}"));
        pushButton_10 = new QPushButton(maincontent_4);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(800, 600, 201, 41));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_29 = new QLabel(maincontent_4);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(430, 50, 191, 31));
        label_29->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
        ajmateriel_5 = new QPushButton(maincontent_4);
        ajmateriel_5->setObjectName("ajmateriel_5");
        ajmateriel_5->setGeometry(QRect(50, 130, 201, 41));
        ajmateriel_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        stackedWidget_3->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        label_30 = new QLabel(page_8);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(102, 109, 131, 31));
        label_30->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_31 = new QLabel(page_8);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(102, 170, 131, 41));
        label_31->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_32 = new QLabel(page_8);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(112, 239, 121, 31));
        label_32->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_33 = new QLabel(page_8);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(110, 300, 111, 31));
        label_33->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_34 = new QLabel(page_8);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(100, 360, 121, 41));
        label_34->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_35 = new QLabel(page_8);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(112, 420, 131, 51));
        label_35->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        lineEdit_25 = new QLineEdit(page_8);
        lineEdit_25->setObjectName("lineEdit_25");
        lineEdit_25->setGeometry(QRect(240, 100, 301, 51));
        lineEdit_25->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        lineEdit_26 = new QLineEdit(page_8);
        lineEdit_26->setObjectName("lineEdit_26");
        lineEdit_26->setGeometry(QRect(240, 160, 301, 51));
        lineEdit_26->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        lineEdit_27 = new QLineEdit(page_8);
        lineEdit_27->setObjectName("lineEdit_27");
        lineEdit_27->setGeometry(QRect(240, 230, 301, 51));
        lineEdit_27->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        lineEdit_28 = new QLineEdit(page_8);
        lineEdit_28->setObjectName("lineEdit_28");
        lineEdit_28->setGeometry(QRect(240, 290, 301, 51));
        lineEdit_28->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        lineEdit_29 = new QLineEdit(page_8);
        lineEdit_29->setObjectName("lineEdit_29");
        lineEdit_29->setGeometry(QRect(240, 420, 301, 51));
        lineEdit_29->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        lineEdit_30 = new QLineEdit(page_8);
        lineEdit_30->setObjectName("lineEdit_30");
        lineEdit_30->setGeometry(QRect(240, 360, 301, 51));
        lineEdit_30->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff; /* Fond blanc */\n"
"    border: 1px solid #cccccc; /* Bordure grise */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 8px; /* Espace int\303\251rieur */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2196f3; /* Bordure bleue lorsqu'il est s\303\251lectionn\303\251 */\n"
"}"));
        pushButton_11 = new QPushButton(page_8);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(240, 530, 141, 41));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2196f3; /* Fond bleu */\n"
"    color: white; /* Texte blanc */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espace int\303\251rieur */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1976d2; /* Fond bleu fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #0d47a1; /* Fond bleu tr\303\250s fonc\303\251 au clic */\n"
"}"));
        pushButton_12 = new QPushButton(page_8);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(390, 530, 141, 41));
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f44336; /* Fond rouge */\n"
"    color: white; /* Texte blanc */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espace int\303\251rieur */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #d32f2f; /* Fond rouge fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #b71c1c; /* Fond rouge tr\303\250s fonc\303\251 au clic */\n"
"}"));
        label_36 = new QLabel(page_8);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(320, 30, 231, 51));
        label_36->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        stackedWidget_3->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        stackedWidget_3->addWidget(page_9);
        stackedWidget_2->addWidget(page_6);
        stackedWidget->addWidget(page_3);
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        label_stat = new QLabel(page_10);
        label_stat->setObjectName("label_stat");
        label_stat->setGeometry(QRect(70, 10, 951, 601));
        pushButton_13 = new QPushButton(page_10);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(110, 630, 191, 51));
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f44336; /* Fond rouge */\n"
"    color: white; /* Texte blanc */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espace int\303\251rieur */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #d32f2f; /* Fond rouge fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #b71c1c; /* Fond rouge tr\303\250s fonc\303\251 au clic */\n"
"}"));
        stackedWidget->addWidget(page_10);
        page_11 = new QWidget();
        page_11->setObjectName("page_11");
        graphicsView1 = new QGraphicsView(page_11);
        graphicsView1->setObjectName("graphicsView1");
        graphicsView1->setGeometry(QRect(75, 50, 941, 541));
        pushButton_14 = new QPushButton(page_11);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(120, 620, 191, 51));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #f44336; /* Fond rouge */\n"
"    color: white; /* Texte blanc */\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    border: none; /* Pas de bordure */\n"
"    border-radius: 5px; /* Coins arrondis */\n"
"    padding: 10px 20px; /* Espace int\303\251rieur */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #d32f2f; /* Fond rouge fonc\303\251 au survol */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #b71c1c; /* Fond rouge tr\303\250s fonc\303\251 au clic */\n"
"}"));
        stackedWidget->addWidget(page_11);
        side = new QWidget(centralwidget);
        side->setObjectName("side");
        side->setGeometry(QRect(0, 10, 231, 691));
        side->setStyleSheet(QString::fromUtf8("QWidget#side {\n"
"    background-color: #1e1e1e;\n"
"}\n"
""));
        layoutWidget_2 = new QWidget(side);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(9, 19, 211, 521));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
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

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1303, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(1);
        stackedWidget_3->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "exporter en PDF", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "statistique", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Liste des chantier", nullptr));
        pushButton_ajout->setText(QCoreApplication::translate("MainWindow", "ajouter chantier", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Trier par:", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "id", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Nom du chantier", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Adresse du chantier", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Date debut ", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Date fin relle ", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Budget ", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "Cout reel", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "Progression", nullptr));

        pushButton_ajout_2->setText(QCoreApplication::translate("MainWindow", "voir calendrier", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "nom du chantier", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "adresse", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "date de debut", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "date fin prevu", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "date de fin reelle", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "statut", nullptr));
        nom->setText(QString());
        adresse->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "remplir ce formulaire", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "budget initial", nullptr));
        budget->setText(QString());
        coutr->setText(QString());
        label_22->setText(QCoreApplication::translate("MainWindow", "cout reel", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "niveau de progression", nullptr));
        statut->setText(QString());
        label_23->setText(QCoreApplication::translate("MainWindow", "temp\303\251rature", nullptr));
        temp->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "exporter en PDF", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "statistique", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Liste des chantier", nullptr));
        ajmateriel_4->setText(QCoreApplication::translate("MainWindow", "ajouter mat\303\251riel", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "nom du chantier", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "adresse", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "date de debut", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "date fin prevu", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "date de fin reelle", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "statut", nullptr));
        nom1->setText(QString());
        adresse1->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:8pt;\">Modifier ce formulaire</span></p></body></html>", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "budget initial", nullptr));
        budget1->setText(QString());
        cout1->setText(QString());
        label_26->setText(QCoreApplication::translate("MainWindow", "cout reel", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "niveau de progression", nullptr));
        statut1->setText(QString());
        id1->setText(QString());
        label_27->setText(QCoreApplication::translate("MainWindow", "temp\303\251rature", nullptr));
        temp1->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "exporter en PDF", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "voir ", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "10", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "25", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("MainWindow", "50", nullptr));
        comboBox_4->setItemText(3, QCoreApplication::translate("MainWindow", "100", nullptr));

        QTableWidgetItem *___qtablewidgetitem = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "cout", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "etat", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "date achat", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_3->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "garantie", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_3->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "action", nullptr));

        const bool __sortingEnabled = tableWidget_3->isSortingEnabled();
        tableWidget_3->setSortingEnabled(false);
        tableWidget_3->setSortingEnabled(__sortingEnabled);

        pushButton_10->setText(QCoreApplication::translate("MainWindow", "statistique", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Liste des mat\303\251riels", nullptr));
        ajmateriel_5->setText(QCoreApplication::translate("MainWindow", "ajouter mat\303\251riel", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "quantit\303\251", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "cout", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "etat", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "date d'achat", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "Garantie", nullptr));
        lineEdit_25->setText(QString());
        lineEdit_26->setText(QString());
        lineEdit_27->setText(QString());
        lineEdit_28->setText(QString());
        lineEdit_29->setText(QString());
        lineEdit_30->setText(QString());
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "modifier ce formulaire", nullptr));
        label_stat->setText(QString());
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
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
