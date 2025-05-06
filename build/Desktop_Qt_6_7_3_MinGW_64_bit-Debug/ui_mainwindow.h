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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
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
    QStackedWidget *stackedWidget;
    QWidget *page_5;
    QWidget *page;
    QWidget *maincontent_2;
    QPushButton *btn_export_pdf;
    QLabel *label_5;
    QLineEdit *lineEditRecherche;
    QLabel *label_6;
    QComboBox *comboBox_3;
    QPushButton *showStatsButton;
    QLabel *lis;
    QPushButton *ajmateriel_3;
    QComboBox *comboBox_tri;
    QLabel *labell;
    QLabel *label;
    QLabel *label_19;
    QTableView *tableViewMateriel;
    QPushButton *pushButton_9;
    QComboBox *comboBox;
    QPushButton *pushButton_11;
    QComboBox *comboBoxCritere;
    QWidget *page_2;
    QGroupBox *groupBox;
    QLineEdit *nom;
    QLineEdit *lineEditQuantite;
    QLineEdit *lineEditCout;
    QLineEdit *lineEditGarantie;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QDateEdit *dateEditAchat;
    QPushButton *pushButton_13;
    QPushButton *pushButton_genererQR;
    QComboBox *comboBoxEtat;
    QLabel *label_20;
    QLabel *label_qrcode;
    QWidget *pageStatistiques;
    QWidget *widgetStats;
    QWidget *page_3;
    QStackedWidget *stackedWidget_2;
    QWidget *stackedWidget_2Page1;
    QWidget *stackedWidget_2Page2;
    QGroupBox *groupBox_2;
    QLineEdit *nom_2;
    QLineEdit *qu;
    QLineEdit *date;
    QLineEdit *cout;
    QLineEdit *garantie;
    QLabel *label_10;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_10;
    QComboBox *comboBox_2;
    QPushButton *pushButton_12;
    QComboBox *comboBoxEtat_2;
    QLabel *label_21;
    QWidget *stackedWidget_2Page3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1292, 759);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        side = new QWidget(centralwidget);
        side->setObjectName("side");
        side->setGeometry(QRect(0, 0, 231, 701));
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
"        font: 18pt \"Segoe UI\";\n"
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

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(270, -10, 1021, 721));
        stackedWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #f8f9fa; /* Couleur de fond douce */\n"
"}\n"
"\n"
"QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"    padding-bottom: 5px;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: white;\n"
"    border: 1px solid #ccc;\n"
"    border-radius: 5px;\n"
"    padding: 6px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #007bff; /* Bordure bleue quand le champ est actif */\n"
"    background-color: #eaf4ff;\n"
"}\n"
"\n"
"QPushButton {\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton#ajouter {\n"
"    background-color: #007bff;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton#ajouter:hover {\n"
"    background-color: #0056b3;\n"
"}\n"
"\n"
"QPushButton#annuler {\n"
"    background-color: #dc3545;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton#annuler:hover {\n"
"    background-color: #b02a37;\n"
"}\n"
""));
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        stackedWidget->addWidget(page_5);
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
        btn_export_pdf = new QPushButton(maincontent_2);
        btn_export_pdf->setObjectName("btn_export_pdf");
        btn_export_pdf->setGeometry(QRect(50, 600, 201, 41));
        btn_export_pdf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_5->setGeometry(QRect(730, 140, 81, 31));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #0f3460;\n"
"    padding-left: 8px;\n"
"}\n"
""));
        lineEditRecherche = new QLineEdit(maincontent_2);
        lineEditRecherche->setObjectName("lineEditRecherche");
        lineEditRecherche->setGeometry(QRect(870, 140, 181, 31));
        lineEditRecherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_6 = new QLabel(maincontent_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(510, 140, 63, 21));
        label_6->setStyleSheet(QString::fromUtf8("Qlabel_6 {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #555; /* Gris fonc\303\251 pour un bon contraste */\n"
"    padding: 3px;\n"
"    border-radius: 5px;\n"
"    background-color: transparent; /* Fond transparent pour un design propre */\n"
"}\n"
""));
        comboBox_3 = new QComboBox(maincontent_2);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(550, 140, 76, 26));
        comboBox_3->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        showStatsButton = new QPushButton(maincontent_2);
        showStatsButton->setObjectName("showStatsButton");
        showStatsButton->setGeometry(QRect(270, 600, 201, 41));
        showStatsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lis = new QLabel(maincontent_2);
        lis->setObjectName("lis");
        lis->setGeometry(QRect(430, 20, 231, 51));
        lis->setStyleSheet(QString::fromUtf8("QLabel#lis {\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    color: #007BFF; /* Bleu vif */\n"
"    text-transform: uppercase;\n"
"    letter-spacing: 1px;\n"
"    border-bottom: 3px solid #007BFF; /* Ligne de s\303\251paration */\n"
"    padding-bottom: 5px;\n"
"}\n"
""));
        ajmateriel_3 = new QPushButton(maincontent_2);
        ajmateriel_3->setObjectName("ajmateriel_3");
        ajmateriel_3->setGeometry(QRect(50, 130, 201, 41));
        ajmateriel_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        comboBox_tri = new QComboBox(maincontent_2);
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->setObjectName("comboBox_tri");
        comboBox_tri->setGeometry(QRect(390, 140, 76, 26));
        comboBox_tri->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        labell = new QLabel(maincontent_2);
        labell->setObjectName("labell");
        labell->setGeometry(QRect(320, 140, 63, 21));
        labell->setStyleSheet(QString::fromUtf8("QLabell\n"
" {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #555; /* Gris fonc\303\251 pour un bon contraste */\n"
"    padding: 3px;\n"
"    border-radius: 5px;\n"
"    background-color: transparent; /* Fond transparent pour un design propre */\n"
"}\n"
""));
        label = new QLabel(maincontent_2);
        label->setObjectName("label");
        label->setGeometry(QRect(930, 580, 111, 91));
        label->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/mmm.png")));
        label->setScaledContents(true);
        label_19 = new QLabel(maincontent_2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(980, -10, 71, 71));
        label_19->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/Capture_d_\303\251cran_2025-02-17_212705-removebg-preview.png")));
        label_19->setScaledContents(true);
        tableViewMateriel = new QTableView(maincontent_2);
        tableViewMateriel->setObjectName("tableViewMateriel");
        tableViewMateriel->setGeometry(QRect(55, 191, 661, 291));
        tableViewMateriel->setStyleSheet(QString::fromUtf8("/* ---------------------------- */\n"
"/* Style du tableau principal   */\n"
"/* ---------------------------- */\n"
"QTableView {\n"
"    background-color: #ffffff;              /* Fond blanc */\n"
"    alternate-background-color: #f8f9fa;    /* Alternance de lignes gris clair */\n"
"    gridline-color: #e9ecef;                /* Couleur des lignes de grille */\n"
"    border: 1px solid #dee2e6;              /* Bordure subtile */\n"
"    border-radius: 8px;                     /* Coins arrondis */\n"
"    font-family: \"Segoe UI\";                /* Police moderne */\n"
"    font-size: 12px;                        /* Taille de texte */\n"
"}\n"
"\n"
"/* ---------------------------- */\n"
"/* En-t\303\252tes du tableau           */\n"
"/* ---------------------------- */\n"
"QHeaderView::section {\n"
"    background-color: #0f3460;              /* Bleu fonc\303\251 */\n"
"    color: white;                           /* Texte blanc */\n"
"    padding: 12px;                          /* Espacement interne */\n"
"   "
                        " border: none;                           /* Pas de bordure */\n"
"    font-weight: bold;                      /* Texte en gras */\n"
"    font-size: 13px;                        /* Taille l\303\251g\303\250rement plus grande */\n"
"}\n"
"\n"
"QHeaderView::section:hover {\n"
"    background-color: #1a5276;              /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"}\n"
"\n"
"/* ---------------------------- */\n"
"/* Lignes et s\303\251lection           */\n"
"/* ---------------------------- */\n"
"QTableView::item {\n"
"    padding: 8px;                           /* Espacement dans les cellules */\n"
"    border-bottom: 1px solid #e9ecef;       /* Ligne de s\303\251paration entre les lignes */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #e94560;              /* Rouge vif pour la s\303\251lection */\n"
"    color: white;                           /* Texte blanc en s\303\251lection */\n"
"}\n"
"\n"
"/* ---------------------------- */\n"
"/* Barre de d\303\251filement       "
                        "    */\n"
"/* ---------------------------- */\n"
"QScrollBar:vertical {\n"
"    background: #f8f9fa;                    /* Fond gris clair */\n"
"    width: 10px;                            /* Largeur r\303\251duite */\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #0f3460;                    /* Bleu fonc\303\251 */\n"
"    min-height: 30px;                       /* Hauteur minimale */\n"
"    border-radius: 4px;                     /* Coins arrondis */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0px;                            /* Masquer les fl\303\250ches */\n"
"}"));
        pushButton_9 = new QPushButton(maincontent_2);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(720, 530, 141, 41));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        comboBox = new QComboBox(maincontent_2);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(620, 540, 76, 26));
        pushButton_11 = new QPushButton(maincontent_2);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(870, 530, 141, 41));
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
        comboBoxCritere = new QComboBox(maincontent_2);
        comboBoxCritere->addItem(QString());
        comboBoxCritere->addItem(QString());
        comboBoxCritere->addItem(QString());
        comboBoxCritere->setObjectName("comboBoxCritere");
        comboBoxCritere->setGeometry(QRect(780, 140, 81, 31));
        comboBoxCritere->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(180, 0, 691, 671));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #007bff;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #007bff;\n"
"}\n"
""));
        nom = new QLineEdit(groupBox);
        nom->setObjectName("nom");
        nom->setGeometry(QRect(190, 60, 301, 51));
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
        lineEditQuantite = new QLineEdit(groupBox);
        lineEditQuantite->setObjectName("lineEditQuantite");
        lineEditQuantite->setGeometry(QRect(190, 130, 301, 51));
        lineEditQuantite->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEditCout = new QLineEdit(groupBox);
        lineEditCout->setObjectName("lineEditCout");
        lineEditCout->setGeometry(QRect(190, 200, 301, 51));
        lineEditCout->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEditGarantie = new QLineEdit(groupBox);
        lineEditGarantie->setObjectName("lineEditGarantie");
        lineEditGarantie->setGeometry(QRect(190, 410, 301, 51));
        lineEditGarantie->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 60, 111, 51));
        label_2->setStyleSheet(QString::fromUtf8("label_2 {\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"    display: block;\n"
"    margin-bottom: 5px;\n"
"}\n"
""));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 140, 111, 41));
        label_3->setStyleSheet(QString::fromUtf8("label_3\n"
" {\n"
"    font-weight: bold;\n"
"    color: #333;\n"
"    display: block;\n"
"    margin-bottom: 5px;\n"
"}\n"
""));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 210, 121, 31));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(70, 280, 111, 31));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(70, 340, 101, 41));
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(60, 410, 111, 51));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 510, 141, 41));
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
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(350, 510, 141, 41));
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
        dateEditAchat = new QDateEdit(groupBox);
        dateEditAchat->setObjectName("dateEditAchat");
        dateEditAchat->setGeometry(QRect(190, 330, 301, 51));
        pushButton_13 = new QPushButton(groupBox);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(540, 580, 141, 71));
        pushButton_genererQR = new QPushButton(groupBox);
        pushButton_genererQR->setObjectName("pushButton_genererQR");
        pushButton_genererQR->setGeometry(QRect(10, 470, 171, 61));
        comboBoxEtat = new QComboBox(groupBox);
        comboBoxEtat->addItem(QString());
        comboBoxEtat->addItem(QString());
        comboBoxEtat->addItem(QString());
        comboBoxEtat->addItem(QString());
        comboBoxEtat->addItem(QString());
        comboBoxEtat->setObjectName("comboBoxEtat");
        comboBoxEtat->setGeometry(QRect(190, 265, 291, 51));
        label_20 = new QLabel(page_2);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(950, 10, 71, 71));
        label_20->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/Capture_d_\303\251cran_2025-02-17_212705-removebg-preview.png")));
        label_20->setScaledContents(true);
        label_qrcode = new QLabel(page_2);
        label_qrcode->setObjectName("label_qrcode");
        label_qrcode->setGeometry(QRect(200, 510, 150, 150));
        label_qrcode->setScaledContents(true);
        stackedWidget->addWidget(page_2);
        pageStatistiques = new QWidget();
        pageStatistiques->setObjectName("pageStatistiques");
        widgetStats = new QWidget(pageStatistiques);
        widgetStats->setObjectName("widgetStats");
        widgetStats->setGeometry(QRect(89, 39, 831, 561));
        stackedWidget->addWidget(pageStatistiques);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget_2 = new QStackedWidget(page_3);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(10, 30, 1021, 691));
        stackedWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        stackedWidget_2Page1 = new QWidget();
        stackedWidget_2Page1->setObjectName("stackedWidget_2Page1");
        stackedWidget_2->addWidget(stackedWidget_2Page1);
        stackedWidget_2Page2 = new QWidget();
        stackedWidget_2Page2->setObjectName("stackedWidget_2Page2");
        groupBox_2 = new QGroupBox(stackedWidget_2Page2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(160, 10, 691, 671));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #007bff;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #007bff;\n"
"}\n"
""));
        nom_2 = new QLineEdit(groupBox_2);
        nom_2->setObjectName("nom_2");
        nom_2->setGeometry(QRect(190, 60, 301, 51));
        nom_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        qu = new QLineEdit(groupBox_2);
        qu->setObjectName("qu");
        qu->setGeometry(QRect(190, 130, 301, 51));
        qu->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        date = new QLineEdit(groupBox_2);
        date->setObjectName("date");
        date->setGeometry(QRect(190, 340, 301, 51));
        date->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        cout = new QLineEdit(groupBox_2);
        cout->setObjectName("cout");
        cout->setGeometry(QRect(190, 200, 301, 51));
        cout->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        garantie = new QLineEdit(groupBox_2);
        garantie->setObjectName("garantie");
        garantie->setGeometry(QRect(190, 410, 301, 51));
        garantie->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(70, 60, 111, 51));
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(60, 140, 111, 41));
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(60, 210, 121, 31));
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(70, 280, 111, 31));
        label_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(70, 340, 101, 41));
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(60, 410, 111, 51));
        label_18->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(170, 510, 141, 41));
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
        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(330, 510, 141, 41));
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
        pushButton_10 = new QPushButton(groupBox_2);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(360, 10, 141, 41));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(250, 20, 76, 26));
        pushButton_12 = new QPushButton(groupBox_2);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(540, 580, 141, 71));
        comboBoxEtat_2 = new QComboBox(groupBox_2);
        comboBoxEtat_2->addItem(QString());
        comboBoxEtat_2->addItem(QString());
        comboBoxEtat_2->addItem(QString());
        comboBoxEtat_2->addItem(QString());
        comboBoxEtat_2->addItem(QString());
        comboBoxEtat_2->setObjectName("comboBoxEtat_2");
        comboBoxEtat_2->setGeometry(QRect(200, 270, 291, 51));
        label_21 = new QLabel(stackedWidget_2Page2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(950, 0, 71, 71));
        label_21->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/Capture_d_\303\251cran_2025-02-17_212705-removebg-preview.png")));
        label_21->setScaledContents(true);
        stackedWidget_2->addWidget(stackedWidget_2Page2);
        stackedWidget_2Page3 = new QWidget();
        stackedWidget_2Page3->setObjectName("stackedWidget_2Page3");
        stackedWidget_2->addWidget(stackedWidget_2Page3);
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1292, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        stackedWidget_2->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        titlelabel_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">Archi<span style=\" font-weight:700; color:#3282f6;\">Wise</span></p></body></html>", nullptr));
        btnhome_2->setText(QCoreApplication::translate("MainWindow", "\360\237\217\240 Accueil", nullptr));
        btnProjects_2->setText(QCoreApplication::translate("MainWindow", "\360\237\223\202 Projets", nullptr));
        btnclients_2->setText(QCoreApplication::translate("MainWindow", "\360\237\221\245 Clients", nullptr));
        btnemployee_2->setText(QCoreApplication::translate("MainWindow", "\360\237\221\267 Employ\303\251s", nullptr));
        btnchantiers_2->setText(QCoreApplication::translate("MainWindow", "\360\237\217\227\357\270\217 Chantiers", nullptr));
        btnmateriels_2->setText(QCoreApplication::translate("MainWindow", "\360\237\233\240\357\270\217 Mat\303\251riels", nullptr));
        btnmateriels_3->setText(QCoreApplication::translate("MainWindow", "fournisseurs", nullptr));
        btn_export_pdf->setText(QCoreApplication::translate("MainWindow", "exporter en PDF", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "voir ", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "10", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "25", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "50", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("MainWindow", "100", nullptr));

        showStatsButton->setText(QCoreApplication::translate("MainWindow", "statistique", nullptr));
        lis->setText(QCoreApplication::translate("MainWindow", "Liste des mat\303\251riels", nullptr));
        ajmateriel_3->setText(QCoreApplication::translate("MainWindow", "ajouter mat\303\251riel", nullptr));
        comboBox_tri->setItemText(0, QCoreApplication::translate("MainWindow", "nom", nullptr));
        comboBox_tri->setItemText(1, QCoreApplication::translate("MainWindow", "cout", nullptr));

        labell->setText(QCoreApplication::translate("MainWindow", "trier par", nullptr));
        label->setText(QString());
        label_19->setText(QString());
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        comboBoxCritere->setItemText(0, QCoreApplication::translate("MainWindow", "id", nullptr));
        comboBoxCritere->setItemText(1, QCoreApplication::translate("MainWindow", "nom", nullptr));
        comboBoxCritere->setItemText(2, QCoreApplication::translate("MainWindow", "cout", nullptr));

        groupBox->setTitle(QCoreApplication::translate("MainWindow", "remplir ce formulaire", nullptr));
        nom->setText(QString());
        lineEditQuantite->setText(QString());
        lineEditCout->setText(QString());
        lineEditGarantie->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "quantit\303\251", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "cout", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "etat", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "date d'achat", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Garantie", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "\342\227\200\357\270\217", nullptr));
        pushButton_genererQR->setText(QCoreApplication::translate("MainWindow", "G\303\251n\303\251rer QR Code\n"
"", nullptr));
        comboBoxEtat->setItemText(0, QCoreApplication::translate("MainWindow", "En service", nullptr));
        comboBoxEtat->setItemText(1, QCoreApplication::translate("MainWindow", "En panne", nullptr));
        comboBoxEtat->setItemText(2, QCoreApplication::translate("MainWindow", "en maintenance", nullptr));
        comboBoxEtat->setItemText(3, QCoreApplication::translate("MainWindow", "Hors service", nullptr));
        comboBoxEtat->setItemText(4, QCoreApplication::translate("MainWindow", "En stock", nullptr));

        label_20->setText(QString());
        label_qrcode->setText(QString());
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "modifier ce formulaire", nullptr));
        nom_2->setText(QString());
        qu->setText(QString());
        date->setText(QString());
        cout->setText(QString());
        garantie->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "quantit\303\251", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "cout", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "etat", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "date d'achat", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Garantie", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "recupurer ", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "\342\227\200\357\270\217", nullptr));
        comboBoxEtat_2->setItemText(0, QCoreApplication::translate("MainWindow", "En service", nullptr));
        comboBoxEtat_2->setItemText(1, QCoreApplication::translate("MainWindow", "En panne", nullptr));
        comboBoxEtat_2->setItemText(2, QCoreApplication::translate("MainWindow", "en maintenance", nullptr));
        comboBoxEtat_2->setItemText(3, QCoreApplication::translate("MainWindow", "Hors service", nullptr));
        comboBoxEtat_2->setItemText(4, QCoreApplication::translate("MainWindow", "En stock", nullptr));

        label_21->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
