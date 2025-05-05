/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
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
    QWidget *page;
    QWidget *maincontent_2;
    QPushButton *pushButton_4;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QComboBox *comboBox_3;
    QTableWidget *tableWidget_2;
    QPushButton *pushButton_5;
    QLabel *label;
    QPushButton *ajmateriel_3;
    QWidget *page_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_10;
    QWidget *page_3;
    QStackedWidget *stackedWidget_2;
    QWidget *page_4;
    QWidget *maincontent_3;
    QPushButton *pushButton_6;
    QLabel *label_11;
    QLineEdit *lineEdit_9;
    QLabel *label_12;
    QComboBox *comboBox_4;
    QTableWidget *tableWidget_3;
    QPushButton *pushButton_7;
    QLabel *label_13;
    QPushButton *ajmateriel_4;
    QWidget *page_5;
    QTabWidget *tabWidget;
    QWidget *ajout;
    QGroupBox *groupBox_3;
    QLineEdit *Nom;
    QLabel *label_21;
    QLineEdit *Ville;
    QLineEdit *Adresse;
    QLineEdit *ContactPrincipal;
    QLineEdit *Email;
    QLabel *label_14;
    QPushButton *btnAjouter;
    QPushButton *annuler_ajout;
    QLabel *label_15;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_22;
    QComboBox *TypePartenaire;
    QLabel *label_20;
    QLabel *label_23;
    QDateEdit *dateEdit;
    QDateEdit *dateEdit_2;
    QWidget *affichage;
    QLineEdit *lineEditRechercheNom;
    QPushButton *recherche;
    QPushButton *pushButtonExporter;
    QTableView *tableView1;
    QLabel *label_16;
    QPushButton *annuler_recherche;
    QWidget *chartContainer;
    QWidget *chartContainerContrats;
    QTextEdit *conversationTextEdit;
    QLineEdit *inputLineEdit;
    QPushButton *sendButton;
    QPushButton *nouvelle_disccusion;
    QLineEdit *statusBar;
    QWidget *tab;
    QGroupBox *groupBox_4;
    QLineEdit *nomInput;
    QLineEdit *villeInput;
    QLineEdit *adresseInput;
    QLineEdit *contactPrincipalInput;
    QLineEdit *emailInput;
    QLabel *label_25;
    QPushButton *modifier;
    QPushButton *annuler_modification;
    QLabel *label_26;
    QLabel *label_28;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_39;
    QComboBox *typePartenaireInput;
    QDateEdit *DD;
    QDateEdit *FF;
    QLabel *label_24;
    QLabel *label_27;
    QWidget *page_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1387, 782);
        MainWindow->setIconSize(QSize(70, 70));
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

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(240, 10, 1111, 751));
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
        label_5->setGeometry(QRect(810, 140, 81, 31));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #0f3460;\n"
"    padding-left: 8px;\n"
"}\n"
""));
        lineEdit_3 = new QLineEdit(maincontent_2);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(860, 140, 131, 31));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        tableWidget_2 = new QTableWidget(maincontent_2);
        if (tableWidget_2->columnCount() < 7)
            tableWidget_2->setColumnCount(7);
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
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font1;
        font1.setBold(true);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        __qtablewidgetitem1->setBackground(QColor(152, 152, 152));
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font2);
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget_2->rowCount() < 5)
            tableWidget_2->setRowCount(5);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::WeatherShowers));
        QBrush brush1(QColor(155, 144, 155, 255));
        brush1.setStyle(Qt::Dense1Pattern);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setForeground(brush1);
        __qtablewidgetitem7->setIcon(icon);
        tableWidget_2->setItem(0, 0, __qtablewidgetitem7);
        QFont font3;
        font3.setStrikeOut(false);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font3);
        tableWidget_2->setItem(0, 1, __qtablewidgetitem8);
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
        tableWidget_2->setItem(1, 0, __qtablewidgetitem9);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(50, 190, 931, 381));
        tableWidget_2->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        label->setGeometry(QRect(430, 50, 191, 31));
        label->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
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
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(102, 109, 131, 31));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(102, 170, 131, 41));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(112, 239, 121, 31));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_7 = new QLabel(page_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(110, 300, 111, 31));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_8 = new QLabel(page_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(100, 360, 121, 41));
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_9 = new QLabel(page_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(112, 420, 131, 51));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        lineEdit_2 = new QLineEdit(page_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(240, 100, 301, 51));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_4 = new QLineEdit(page_2);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(240, 160, 301, 51));
        lineEdit_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_5 = new QLineEdit(page_2);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(240, 230, 301, 51));
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_6 = new QLineEdit(page_2);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(240, 290, 301, 51));
        lineEdit_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_7 = new QLineEdit(page_2);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(240, 420, 301, 51));
        lineEdit_7->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_8 = new QLineEdit(page_2);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(240, 360, 301, 51));
        lineEdit_8->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        pushButton->setGeometry(QRect(240, 530, 141, 41));
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
        pushButton_2->setGeometry(QRect(390, 530, 141, 41));
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
        label_10->setGeometry(QRect(320, 30, 231, 51));
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget_2 = new QStackedWidget(page_3);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setGeometry(QRect(10, -10, 1021, 691));
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
        label_11 = new QLabel(maincontent_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(810, 140, 81, 31));
        label_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        label_12 = new QLabel(maincontent_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(510, 140, 63, 21));
        comboBox_4 = new QComboBox(maincontent_3);
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
        tableWidget_3 = new QTableWidget(maincontent_3);
        if (tableWidget_3->columnCount() < 7)
            tableWidget_3->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        __qtablewidgetitem10->setForeground(brush);
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font1);
        __qtablewidgetitem11->setBackground(QColor(152, 152, 152));
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font1);
        tableWidget_3->setHorizontalHeaderItem(5, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font2);
        tableWidget_3->setHorizontalHeaderItem(6, __qtablewidgetitem16);
        if (tableWidget_3->rowCount() < 5)
            tableWidget_3->setRowCount(5);
        QBrush brush4(QColor(155, 144, 155, 255));
        brush4.setStyle(Qt::Dense1Pattern);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setForeground(brush4);
        __qtablewidgetitem17->setIcon(icon);
        tableWidget_3->setItem(0, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font3);
        tableWidget_3->setItem(0, 1, __qtablewidgetitem18);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::NoBrush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font4);
        __qtablewidgetitem19->setBackground(brush6);
        __qtablewidgetitem19->setForeground(brush5);
        tableWidget_3->setItem(1, 0, __qtablewidgetitem19);
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
        label_13 = new QLabel(maincontent_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(430, 50, 191, 31));
        label_13->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
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
        tabWidget = new QTabWidget(page_5);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 30, 1031, 691));
        tabWidget->setStyleSheet(QString::fromUtf8("/* Style pour le QTabWidget */\n"
"QTabWidget {\n"
"    background-color: #0f3460;  /* Couleur de fond du QTabWidget */\n"
"    border: 1px solid #0f3460;  /* Bordure autour du QTabWidget */\n"
"    padding: 2px;\n"
"}\n"
"\n"
"/* Style pour les onglets (tab) */\n"
"QTabBar::tab {\n"
"    background-color: #0f3460; /* Couleur de fond des onglets */\n"
"    color: white;              /* Texte en blanc */\n"
"    padding: 10px;\n"
"    border: 1px solid #0f3460; /* Bordure des onglets */\n"
"    border-radius: 5px;        /* Bords arrondis des onglets */\n"
"}\n"
"\n"
"/* Effet au survol d'un onglet */\n"
"QTabBar::tab:hover {\n"
"    background-color: #3a4d79;  /* Couleur de fond lors du survol */\n"
"    color: white;               /* Texte en blanc lors du survol */\n"
"}\n"
"\n"
"/* Style pour l'onglet s\303\251lectionn\303\251 */\n"
"QTabBar::tab:selected {\n"
"    background-color: #1f4578; /* Couleur de fond de l'onglet s\303\251lectionn\303\251 */\n"
"    color: white;              /* Texte en blanc */\n"
""
                        "    font-weight: bold;         /* Mettre le texte en gras */\n"
"    border-color: #1f4578;     /* Bordure de l'onglet s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"/* Style pour la bordure de l'onglet */\n"
"QTabWidget::pane {\n"
"    border: 1px solid #0f3460;  /* Bordure de la zone contenant les onglets */\n"
"    background-color: #0f3460;  /* Fond de la zone des onglets */\n"
"}\n"
"\n"
"/* Style des boutons de navigation (s'ils existent, par exemple pour un onglet ferm\303\251) */\n"
"QTabBar::close-button {\n"
"    image: url(close.png); /* Image pour le bouton de fermeture */\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"\n"
"/* Survol du bouton de fermeture */\n"
"QTabBar::close-button:hover {\n"
"    image: url(close_hover.png); /* Image de survol */\n"
"}\n"
""));
        ajout = new QWidget();
        ajout->setObjectName("ajout");
        groupBox_3 = new QGroupBox(ajout);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(90, 50, 601, 391));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Nom = new QLineEdit(groupBox_3);
        Nom->setObjectName("Nom");
        Nom->setGeometry(QRect(170, 40, 113, 28));
        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(60, 40, 61, 20));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Segoe Print")});
        label_21->setFont(font5);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);\n"
"border-bottom-color: rgb(0, 0, 0);"));
        Ville = new QLineEdit(groupBox_3);
        Ville->setObjectName("Ville");
        Ville->setGeometry(QRect(470, 210, 113, 28));
        Adresse = new QLineEdit(groupBox_3);
        Adresse->setObjectName("Adresse");
        Adresse->setGeometry(QRect(170, 210, 113, 28));
        ContactPrincipal = new QLineEdit(groupBox_3);
        ContactPrincipal->setObjectName("ContactPrincipal");
        ContactPrincipal->setGeometry(QRect(470, 40, 113, 28));
        Email = new QLineEdit(groupBox_3);
        Email->setObjectName("Email");
        Email->setGeometry(QRect(470, 120, 113, 28));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(60, 40, 81, 31));
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        btnAjouter = new QPushButton(groupBox_3);
        btnAjouter->setObjectName("btnAjouter");
        btnAjouter->setGeometry(QRect(140, 330, 141, 41));
        btnAjouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        annuler_ajout = new QPushButton(groupBox_3);
        annuler_ajout->setObjectName("annuler_ajout");
        annuler_ajout->setGeometry(QRect(380, 330, 141, 41));
        annuler_ajout->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
"border-radius:10px;"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 120, 141, 31));
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(330, 40, 141, 31));
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(370, 210, 91, 31));
        label_18->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(30, 200, 111, 31));
        label_19->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(360, 120, 101, 31));
        label_22->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        TypePartenaire = new QComboBox(groupBox_3);
        TypePartenaire->setObjectName("TypePartenaire");
        TypePartenaire->setGeometry(QRect(170, 120, 121, 28));
        TypePartenaire->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(40, 270, 111, 31));
        label_20->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(340, 270, 111, 31));
        label_23->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        dateEdit = new QDateEdit(groupBox_3);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(170, 280, 110, 29));
        dateEdit->setDate(QDate(2025, 1, 1));
        dateEdit_2 = new QDateEdit(groupBox_3);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setGeometry(QRect(470, 270, 110, 29));
        dateEdit_2->setDate(QDate(2026, 1, 1));
        tabWidget->addTab(ajout, QString());
        affichage = new QWidget();
        affichage->setObjectName("affichage");
        lineEditRechercheNom = new QLineEdit(affichage);
        lineEditRechercheNom->setObjectName("lineEditRechercheNom");
        lineEditRechercheNom->setGeometry(QRect(190, 220, 113, 28));
        lineEditRechercheNom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff;\n"
"    color: #333333;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 14px;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 10px;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0078d7;\n"
"}\n"
""));
        recherche = new QPushButton(affichage);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(330, 220, 101, 29));
        recherche->setFont(font5);
        recherche->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        recherche->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: #4A90E2\n"
";\n"
"border-radius:10px;"));
        pushButtonExporter = new QPushButton(affichage);
        pushButtonExporter->setObjectName("pushButtonExporter");
        pushButtonExporter->setGeometry(QRect(60, 560, 101, 29));
        pushButtonExporter->setFont(font5);
        pushButtonExporter->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        pushButtonExporter->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: #4A90E2\n"
";\n"
"border-radius:10px;"));
        tableView1 = new QTableView(affichage);
        tableView1->setObjectName("tableView1");
        tableView1->setGeometry(QRect(40, 260, 631, 291));
        tableView1->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    border: 1px solid #dddddd;             /* Bordure l\303\251g\303\250re */\n"
"    border-radius: 5px;                    /* Coins arrondis */\n"
"    background-color: #0f3460;             /* Couleur de fond personnalis\303\251e en bleu fonc\303\251 */\n"
"    font-size: 12px;                       /* Taille de police */\n"
"    padding: 5px;                          /* Espacement interne */\n"
"    color: white;                          /* Couleur du texte blanc pour contraste */\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 5px;\n"
"    color: white;                          /* Assurer que le texte dans les items est visible */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #3d8eb9;             /* Couleur de fond de la s\303\251lection */\n"
"    color: white;                          /* Couleur du texte s\303\251lectionn\303\251 en blanc */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #1e2a47;             /* Couleur de fond l\303\251g\303\250"
                        "rement plus claire pour les en-t\303\252tes */\n"
"    padding: 5px;\n"
"    font-weight: bold;                     /* Police en gras pour les en-t\303\252tes */\n"
"    border: 1px solid #cccccc;             /* Bordure autour des en-t\303\252tes */\n"
"    color: white;                          /* Couleur du texte dans les en-t\303\252tes */\n"
"}\n"
"\n"
"QTableView QTableCornerButton::section {\n"
"    background-color: #1e2a47;             /* Couleur du coin en haut \303\240 gauche pour correspondre aux en-t\303\252tes */\n"
"    color: white;                          /* Texte blanc pour le coin */\n"
"}\n"
""));
        label_16 = new QLabel(affichage);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(30, 220, 141, 31));
        label_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        annuler_recherche = new QPushButton(affichage);
        annuler_recherche->setObjectName("annuler_recherche");
        annuler_recherche->setGeometry(QRect(460, 220, 101, 29));
        annuler_recherche->setFont(font5);
        annuler_recherche->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        annuler_recherche->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: #f44336;\n"
";\n"
"border-radius:10px;"));
        chartContainer = new QWidget(affichage);
        chartContainer->setObjectName("chartContainer");
        chartContainer->setGeometry(QRect(520, 10, 431, 201));
        chartContainerContrats = new QWidget(affichage);
        chartContainerContrats->setObjectName("chartContainerContrats");
        chartContainerContrats->setGeometry(QRect(70, 10, 421, 201));
        conversationTextEdit = new QTextEdit(affichage);
        conversationTextEdit->setObjectName("conversationTextEdit");
        conversationTextEdit->setGeometry(QRect(700, 260, 331, 291));
        conversationTextEdit->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    background-color: #1e1e1e;   /* Fond noir/gris fonc\303\251 */\n"
"    color: #f0f0f0;              /* Texte clair */\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 14px;\n"
"    border: 1px solid #444444;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"}\n"
""));
        inputLineEdit = new QLineEdit(affichage);
        inputLineEdit->setObjectName("inputLineEdit");
        inputLineEdit->setGeometry(QRect(700, 570, 211, 28));
        inputLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff;\n"
"    color: #333333;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 14px;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 10px;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0078d7;\n"
"}\n"
""));
        sendButton = new QPushButton(affichage);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(920, 570, 83, 29));
        sendButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0078d7;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #005fa1;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #004d80;\n"
"}\n"
""));
        nouvelle_disccusion = new QPushButton(affichage);
        nouvelle_disccusion->setObjectName("nouvelle_disccusion");
        nouvelle_disccusion->setGeometry(QRect(760, 220, 181, 29));
        nouvelle_disccusion->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #0078d7;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 10px;\n"
"    padding: 8px 16px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #005fa1;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #004d80;\n"
"}\n"
""));
        statusBar = new QLineEdit(affichage);
        statusBar->setObjectName("statusBar");
        statusBar->setGeometry(QRect(490, 570, 113, 28));
        statusBar->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #ffffff;\n"
"    color: #333333;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 14px;\n"
"    border: 1px solid #cccccc;\n"
"    border-radius: 10px;\n"
"    padding: 6px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #0078d7;\n"
"}\n"
""));
        tabWidget->addTab(affichage, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(90, 80, 601, 391));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        nomInput = new QLineEdit(groupBox_4);
        nomInput->setObjectName("nomInput");
        nomInput->setGeometry(QRect(170, 50, 113, 28));
        villeInput = new QLineEdit(groupBox_4);
        villeInput->setObjectName("villeInput");
        villeInput->setGeometry(QRect(470, 210, 113, 28));
        adresseInput = new QLineEdit(groupBox_4);
        adresseInput->setObjectName("adresseInput");
        adresseInput->setGeometry(QRect(170, 210, 113, 28));
        contactPrincipalInput = new QLineEdit(groupBox_4);
        contactPrincipalInput->setObjectName("contactPrincipalInput");
        contactPrincipalInput->setGeometry(QRect(470, 50, 113, 28));
        emailInput = new QLineEdit(groupBox_4);
        emailInput->setObjectName("emailInput");
        emailInput->setGeometry(QRect(470, 130, 113, 28));
        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(60, 50, 81, 31));
        label_25->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        modifier = new QPushButton(groupBox_4);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(140, 330, 141, 41));
        modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        annuler_modification = new QPushButton(groupBox_4);
        annuler_modification->setObjectName("annuler_modification");
        annuler_modification->setGeometry(QRect(380, 330, 141, 41));
        annuler_modification->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"}\n"
"border-radius:10px;"));
        label_26 = new QLabel(groupBox_4);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(10, 130, 141, 31));
        label_26->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_28 = new QLabel(groupBox_4);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(320, 50, 141, 31));
        label_28->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_36 = new QLabel(groupBox_4);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(350, 210, 91, 31));
        label_36->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_37 = new QLabel(groupBox_4);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(50, 210, 111, 31));
        label_37->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_39 = new QLabel(groupBox_4);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(350, 130, 101, 31));
        label_39->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        typePartenaireInput = new QComboBox(groupBox_4);
        typePartenaireInput->setObjectName("typePartenaireInput");
        typePartenaireInput->setGeometry(QRect(170, 130, 121, 28));
        typePartenaireInput->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        DD = new QDateEdit(groupBox_4);
        DD->setObjectName("DD");
        DD->setGeometry(QRect(170, 270, 110, 29));
        DD->setDate(QDate(2025, 1, 1));
        FF = new QDateEdit(groupBox_4);
        FF->setObjectName("FF");
        FF->setGeometry(QRect(470, 270, 110, 29));
        FF->setDate(QDate(2025, 1, 1));
        label_24 = new QLabel(groupBox_4);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(40, 270, 111, 31));
        label_24->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_27 = new QLabel(groupBox_4);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(340, 270, 111, 31));
        label_27->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        tabWidget->addTab(tab, QString());
        stackedWidget_2->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        stackedWidget_2->addWidget(page_6);
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1387, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        stackedWidget_2->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);


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
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "exporter en PDF", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "voir ", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "10", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "25", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "50", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("MainWindow", "100", nullptr));

        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "cout", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "etat", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "date achat", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "garantie", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "action", nullptr));

        const bool __sortingEnabled = tableWidget_2->isSortingEnabled();
        tableWidget_2->setSortingEnabled(false);
        tableWidget_2->setSortingEnabled(__sortingEnabled);

        pushButton_5->setText(QCoreApplication::translate("MainWindow", "statistique", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Liste des mat\303\251riels", nullptr));
        ajmateriel_3->setText(QCoreApplication::translate("MainWindow", "ajouter mat\303\251riel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "quantit\303\251", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "cout", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "etat", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "date d'achat", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Garantie", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_4->setText(QString());
        lineEdit_5->setText(QString());
        lineEdit_6->setText(QString());
        lineEdit_7->setText(QString());
        lineEdit_8->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "remplir ce formulaire", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "exporter en PDF", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "voir ", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "10", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "25", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("MainWindow", "50", nullptr));
        comboBox_4->setItemText(3, QCoreApplication::translate("MainWindow", "100", nullptr));

        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "cout", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "etat", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "date achat", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_3->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "garantie", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_3->horizontalHeaderItem(6);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "action", nullptr));

        const bool __sortingEnabled1 = tableWidget_3->isSortingEnabled();
        tableWidget_3->setSortingEnabled(false);
        tableWidget_3->setSortingEnabled(__sortingEnabled1);

        pushButton_7->setText(QCoreApplication::translate("MainWindow", "statistique", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Liste des mat\303\251riels", nullptr));
        ajmateriel_4->setText(QCoreApplication::translate("MainWindow", "ajouter mat\303\251riel", nullptr));
#if QT_CONFIG(whatsthis)
        tabWidget->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        groupBox_3->setTitle(QString());
        Nom->setInputMask(QString());
        label_21->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        Email->setInputMask(QString());
        Email->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        annuler_ajout->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "type de partenaire", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "contrat principal", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "ville", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "adresse", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "date debut", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "date fin", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy/M/d", nullptr));
        dateEdit_2->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy/M/d", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ajout), QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        lineEditRechercheNom->setInputMask(QString());
        recherche->setText(QCoreApplication::translate("MainWindow", "rechercher", nullptr));
        pushButtonExporter->setText(QCoreApplication::translate("MainWindow", "exportation", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "recherche par nom", nullptr));
        annuler_recherche->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        conversationTextEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI','sans-serif'; font-size:14px; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        inputLineEdit->setInputMask(QString());
        sendButton->setText(QCoreApplication::translate("MainWindow", "envoyer", nullptr));
        nouvelle_disccusion->setText(QCoreApplication::translate("MainWindow", "nouvelle discussion", nullptr));
        statusBar->setInputMask(QString());
        tabWidget->setTabText(tabWidget->indexOf(affichage), QCoreApplication::translate("MainWindow", "affichage", nullptr));
        groupBox_4->setTitle(QString());
        nomInput->setInputMask(QString());
        emailInput->setInputMask(QString());
        emailInput->setText(QString());
        label_25->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        annuler_modification->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "type de partenaire", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "contrat principal", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "ville", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "adresse", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        DD->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy/M/d", nullptr));
        FF->setDisplayFormat(QCoreApplication::translate("MainWindow", "yyyy/M/d", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "date debut", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "date fin", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "modifier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
