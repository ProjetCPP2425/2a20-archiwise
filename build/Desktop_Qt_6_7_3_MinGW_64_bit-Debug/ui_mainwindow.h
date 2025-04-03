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
    QStackedWidget *stackedWidget_3;
    QWidget *page_7;
    QWidget *maincontent_2;
    QPushButton *pushButton_4;
    QLabel *label_5;
    QLineEdit *lineEdit_recherche;
    QTableView *tableView;
    QPushButton *pushButton_5;
    QLabel *label;
    QPushButton *lineEdit_id;
    QLabel *label_10;
    QLabel *label_21;
    QTableWidget *tableWidget_4;
    QWidget *page_8;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QLabel *label_6;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QWidget *page_9;
    QStackedWidget *stackedWidget_4;
    QWidget *page_10;
    QWidget *maincontent_4;
    QPushButton *pushButton_13;
    QLabel *label_19;
    QLineEdit *lineEdit_24;
    QLabel *label_20;
    QComboBox *comboBox_5;
    QTableWidget *tableWidget_5;
    QPushButton *pushButton_14;
    QLabel *label_30;
    QPushButton *ajmateriel_5;
    QWidget *page_11;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLineEdit *lineEdit_25;
    QLineEdit *lineEdit_26;
    QLineEdit *lineEdit_27;
    QLineEdit *lineEdit_28;
    QLineEdit *lineEdit_29;
    QLineEdit *lineEdit_30;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QLabel *label_37;
    QWidget *page_12;
    QWidget *page_2;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_prix;
    QLineEdit *lineEdit_tel;
    QLineEdit *lineEdit_adresse;
    QLineEdit *lineEdit_type;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *ajouterClient;
    QPushButton *pushButton_2;
    QLabel *label_22;
    QDateEdit *dateEdit_inscription;
    QWidget *page_3;
    QGroupBox *groupBox_2;
    QLineEdit *n;
    QLineEdit *p;
    QLineEdit *pr;
    QLineEdit *t;
    QLineEdit *a;
    QLineEdit *ty;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QPushButton *modifierClient;
    QPushButton *pushButton_12;
    QLabel *label_29;
    QDateEdit *di;
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
        MainWindow->resize(1673, 954);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(230, 0, 1351, 801));
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
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget_3 = new QStackedWidget(page);
        stackedWidget_3->setObjectName("stackedWidget_3");
        stackedWidget_3->setGeometry(QRect(10, 0, 1521, 791));
        stackedWidget_3->setStyleSheet(QString::fromUtf8("QWidget {\n"
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
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        maincontent_2 = new QWidget(page_7);
        maincontent_2->setObjectName("maincontent_2");
        maincontent_2->setGeometry(QRect(-10, 0, 1591, 1151));
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
        pushButton_4->setGeometry(QRect(810, 490, 201, 41));
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
        label_5->setGeometry(QRect(790, 140, 81, 31));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    color: #0f3460;\n"
"    padding-left: 8px;\n"
"}\n"
""));
        lineEdit_recherche = new QLineEdit(maincontent_2);
        lineEdit_recherche->setObjectName("lineEdit_recherche");
        lineEdit_recherche->setGeometry(QRect(860, 130, 181, 41));
        lineEdit_recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        tableView->setGeometry(QRect(20, 190, 1291, 281));
        tableView->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        pushButton_5->setGeometry(QRect(1050, 490, 201, 41));
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
        label->setGeometry(QRect(550, 50, 271, 71));
        label->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
"font-size: 18px; /* Taille de la police */\n"
"font-weight: bold; /* Texte en gras */"));
        lineEdit_id = new QPushButton(maincontent_2);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(60, 130, 201, 41));
        lineEdit_id->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_10 = new QLabel(maincontent_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 30, 291, 51));
        label_10->setStyleSheet(QString::fromUtf8("QLabel#titre {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color: #007bff;\n"
"    margin-bottom: 10px;\n"
"    border-bottom: 2px solid #007bff;\n"
"    padding-bottom: 5px;\n"
"}\n"
""));
        label_21 = new QLabel(maincontent_2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(30, 530, 291, 51));
        label_21->setStyleSheet(QString::fromUtf8("QLabel#titre {\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    color: #007bff;\n"
"    margin-bottom: 10px;\n"
"    border-bottom: 2px solid #007bff;\n"
"    padding-bottom: 5px;\n"
"}\n"
""));
        tableWidget_4 = new QTableWidget(maincontent_2);
        if (tableWidget_4->columnCount() < 4)
            tableWidget_4->setColumnCount(4);
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
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font1;
        font1.setBold(true);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        __qtablewidgetitem1->setBackground(QColor(152, 152, 152));
        tableWidget_4->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidget_4->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        tableWidget_4->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget_4->rowCount() < 1)
            tableWidget_4->setRowCount(1);
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::WeatherShowers));
        QBrush brush1(QColor(155, 144, 155, 255));
        brush1.setStyle(Qt::Dense1Pattern);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setForeground(brush1);
        __qtablewidgetitem4->setIcon(icon);
        tableWidget_4->setItem(0, 0, __qtablewidgetitem4);
        QFont font2;
        font2.setStrikeOut(false);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font2);
        tableWidget_4->setItem(0, 1, __qtablewidgetitem5);
        tableWidget_4->setObjectName("tableWidget_4");
        tableWidget_4->setGeometry(QRect(30, 580, 1291, 151));
        tableWidget_4->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        tableWidget_4->setRowCount(1);
        tableWidget_4->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget_4->horizontalHeader()->setDefaultSectionSize(125);
        tableWidget_4->horizontalHeader()->setStretchLastSection(true);
        tableWidget_4->verticalHeader()->setDefaultSectionSize(56);
        stackedWidget_3->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        groupBox_3 = new QGroupBox(page_8);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(180, 0, 691, 671));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #007bff;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #007bff;\n"
"}\n"
""));
        lineEdit_10 = new QLineEdit(groupBox_3);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(190, 60, 301, 51));
        lineEdit_10->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_11 = new QLineEdit(groupBox_3);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(190, 130, 301, 51));
        lineEdit_11->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_12 = new QLineEdit(groupBox_3);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(190, 340, 301, 51));
        lineEdit_12->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_13 = new QLineEdit(groupBox_3);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setGeometry(QRect(190, 270, 301, 51));
        lineEdit_13->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_14 = new QLineEdit(groupBox_3);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setGeometry(QRect(190, 200, 301, 51));
        lineEdit_14->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_15 = new QLineEdit(groupBox_3);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setGeometry(QRect(190, 410, 301, 51));
        lineEdit_15->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(70, 60, 111, 51));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(60, 140, 111, 41));
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(60, 210, 121, 31));
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(70, 280, 111, 31));
        label_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(70, 340, 101, 41));
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(60, 410, 111, 51));
        label_18->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        pushButton_3 = new QPushButton(groupBox_3);
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
        pushButton_8 = new QPushButton(groupBox_3);
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
        stackedWidget_3->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        stackedWidget_4 = new QStackedWidget(page_9);
        stackedWidget_4->setObjectName("stackedWidget_4");
        stackedWidget_4->setGeometry(QRect(0, 0, 1021, 691));
        stackedWidget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        maincontent_4 = new QWidget(page_10);
        maincontent_4->setObjectName("maincontent_4");
        maincontent_4->setGeometry(QRect(-20, 10, 1061, 711));
        sizePolicy.setHeightForWidth(maincontent_4->sizePolicy().hasHeightForWidth());
        maincontent_4->setSizePolicy(sizePolicy);
        maincontent_4->setStyleSheet(QString::fromUtf8("QWidget#maincontent\n"
" {\n"
"    background-color: white;\n"
"}\n"
""));
        pushButton_13 = new QPushButton(maincontent_4);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(570, 600, 201, 41));
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        comboBox_5 = new QComboBox(maincontent_4);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(550, 140, 76, 26));
        comboBox_5->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        tableWidget_5 = new QTableWidget(maincontent_4);
        if (tableWidget_5->columnCount() < 7)
            tableWidget_5->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        __qtablewidgetitem6->setForeground(brush);
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font1);
        __qtablewidgetitem7->setBackground(QColor(152, 152, 152));
        tableWidget_5->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font1);
        tableWidget_5->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font1);
        tableWidget_5->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font1);
        tableWidget_5->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font1);
        tableWidget_5->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        QFont font3;
        font3.setBold(true);
        font3.setItalic(false);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font3);
        tableWidget_5->setHorizontalHeaderItem(6, __qtablewidgetitem12);
        if (tableWidget_5->rowCount() < 5)
            tableWidget_5->setRowCount(5);
        QBrush brush2(QColor(155, 144, 155, 255));
        brush2.setStyle(Qt::Dense1Pattern);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setForeground(brush2);
        __qtablewidgetitem13->setIcon(icon);
        tableWidget_5->setItem(0, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font2);
        tableWidget_5->setItem(0, 1, __qtablewidgetitem14);
        QBrush brush3(QColor(0, 0, 0, 255));
        brush3.setStyle(Qt::NoBrush);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::NoBrush);
        QFont font4;
        font4.setItalic(false);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font4);
        __qtablewidgetitem15->setBackground(brush4);
        __qtablewidgetitem15->setForeground(brush3);
        tableWidget_5->setItem(1, 0, __qtablewidgetitem15);
        tableWidget_5->setObjectName("tableWidget_5");
        tableWidget_5->setGeometry(QRect(50, 190, 931, 381));
        tableWidget_5->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        pushButton_14 = new QPushButton(maincontent_4);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(800, 600, 201, 41));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_30 = new QLabel(maincontent_4);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(430, 50, 191, 31));
        label_30->setStyleSheet(QString::fromUtf8("color: #2E86C1; /* Couleur du texte */\n"
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
        stackedWidget_4->addWidget(page_10);
        page_11 = new QWidget();
        page_11->setObjectName("page_11");
        label_31 = new QLabel(page_11);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(102, 109, 131, 31));
        label_31->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_32 = new QLabel(page_11);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(102, 170, 131, 41));
        label_32->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_33 = new QLabel(page_11);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(112, 239, 121, 31));
        label_33->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_34 = new QLabel(page_11);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(110, 300, 111, 31));
        label_34->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_35 = new QLabel(page_11);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(100, 360, 121, 41));
        label_35->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_36 = new QLabel(page_11);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(112, 420, 131, 51));
        label_36->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        lineEdit_25 = new QLineEdit(page_11);
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
        lineEdit_26 = new QLineEdit(page_11);
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
        lineEdit_27 = new QLineEdit(page_11);
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
        lineEdit_28 = new QLineEdit(page_11);
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
        lineEdit_29 = new QLineEdit(page_11);
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
        lineEdit_30 = new QLineEdit(page_11);
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
        pushButton_15 = new QPushButton(page_11);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(240, 530, 141, 41));
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_16 = new QPushButton(page_11);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(390, 530, 141, 41));
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_37 = new QLabel(page_11);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(320, 30, 231, 51));
        label_37->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        stackedWidget_4->addWidget(page_11);
        page_12 = new QWidget();
        page_12->setObjectName("page_12");
        stackedWidget_4->addWidget(page_12);
        stackedWidget_3->addWidget(page_9);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        groupBox = new QGroupBox(page_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(230, 0, 691, 671));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #007bff;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #007bff;\n"
"}\n"
""));
        lineEdit_nom = new QLineEdit(groupBox);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(190, 60, 301, 51));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_prenom = new QLineEdit(groupBox);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(190, 130, 301, 51));
        lineEdit_prenom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_prix = new QLineEdit(groupBox);
        lineEdit_prix->setObjectName("lineEdit_prix");
        lineEdit_prix->setGeometry(QRect(190, 340, 301, 51));
        lineEdit_prix->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_tel = new QLineEdit(groupBox);
        lineEdit_tel->setObjectName("lineEdit_tel");
        lineEdit_tel->setGeometry(QRect(190, 270, 301, 51));
        lineEdit_tel->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_adresse = new QLineEdit(groupBox);
        lineEdit_adresse->setObjectName("lineEdit_adresse");
        lineEdit_adresse->setGeometry(QRect(190, 200, 301, 51));
        lineEdit_adresse->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_type = new QLineEdit(groupBox);
        lineEdit_type->setObjectName("lineEdit_type");
        lineEdit_type->setGeometry(QRect(190, 410, 301, 51));
        lineEdit_type->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 140, 111, 41));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 210, 121, 31));
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
        label_9->setGeometry(QRect(70, 410, 111, 51));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        ajouterClient = new QPushButton(groupBox);
        ajouterClient->setObjectName("ajouterClient");
        ajouterClient->setGeometry(QRect(180, 560, 141, 41));
        ajouterClient->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_2->setGeometry(QRect(350, 560, 141, 41));
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
        label_22 = new QLabel(groupBox);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(40, 480, 141, 51));
        label_22->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        dateEdit_inscription = new QDateEdit(groupBox);
        dateEdit_inscription->setObjectName("dateEdit_inscription");
        dateEdit_inscription->setGeometry(QRect(190, 470, 301, 41));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        groupBox_2 = new QGroupBox(page_3);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(240, 0, 691, 671));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #007bff;\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    color: #007bff;\n"
"}\n"
""));
        n = new QLineEdit(groupBox_2);
        n->setObjectName("n");
        n->setGeometry(QRect(190, 60, 301, 51));
        n->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        p = new QLineEdit(groupBox_2);
        p->setObjectName("p");
        p->setGeometry(QRect(190, 130, 301, 51));
        p->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        pr = new QLineEdit(groupBox_2);
        pr->setObjectName("pr");
        pr->setGeometry(QRect(190, 340, 301, 51));
        pr->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        t = new QLineEdit(groupBox_2);
        t->setObjectName("t");
        t->setGeometry(QRect(190, 270, 301, 51));
        t->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        a = new QLineEdit(groupBox_2);
        a->setObjectName("a");
        a->setGeometry(QRect(190, 200, 301, 51));
        a->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        ty = new QLineEdit(groupBox_2);
        ty->setObjectName("ty");
        ty->setGeometry(QRect(190, 410, 301, 51));
        ty->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(70, 60, 111, 51));
        label_23->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_24 = new QLabel(groupBox_2);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(70, 140, 111, 41));
        label_24->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_25 = new QLabel(groupBox_2);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(70, 210, 121, 31));
        label_25->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_26 = new QLabel(groupBox_2);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(70, 280, 111, 31));
        label_26->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_27 = new QLabel(groupBox_2);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(70, 340, 101, 41));
        label_27->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_28 = new QLabel(groupBox_2);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(70, 410, 111, 51));
        label_28->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        modifierClient = new QPushButton(groupBox_2);
        modifierClient->setObjectName("modifierClient");
        modifierClient->setGeometry(QRect(180, 560, 141, 41));
        modifierClient->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_12 = new QPushButton(groupBox_2);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(350, 560, 141, 41));
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
        label_29 = new QLabel(groupBox_2);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(40, 480, 141, 51));
        label_29->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        di = new QDateEdit(groupBox_2);
        di->setObjectName("di");
        di->setGeometry(QRect(190, 480, 301, 41));
        stackedWidget->addWidget(page_3);
        side = new QWidget(centralWidget);
        side->setObjectName("side");
        side->setGeometry(QRect(0, 0, 231, 801));
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
        menuBar->setGeometry(QRect(0, 0, 1673, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        stackedWidget_3->setCurrentIndex(0);
        stackedWidget_4->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Exporter en PDF", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">Liste des clients</span></p></body></html>", nullptr));
        lineEdit_id->setText(QCoreApplication::translate("MainWindow", "Ajouter Client ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Gestion Des Clients</span></p></body></html>", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Historique des actions</span></p><p><br/></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID Client", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Action", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "D\303\251tails", nullptr));

        const bool __sortingEnabled = tableWidget_4->isSortingEnabled();
        tableWidget_4->setSortingEnabled(false);
        tableWidget_4->setSortingEnabled(__sortingEnabled);

        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "remplir ce formulaire", nullptr));
        lineEdit_10->setText(QString());
        lineEdit_11->setText(QString());
        lineEdit_12->setText(QString());
        lineEdit_13->setText(QString());
        lineEdit_14->setText(QString());
        lineEdit_15->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "quantit\303\251", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "cout", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "etat", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "date d'achat", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Garantie", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "exporter en PDF", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "voir ", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("MainWindow", "10", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("MainWindow", "25", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("MainWindow", "50", nullptr));
        comboBox_5->setItemText(3, QCoreApplication::translate("MainWindow", "100", nullptr));

        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_5->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_5->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "cout", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_5->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "etat", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_5->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "date achat", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_5->horizontalHeaderItem(5);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "garantie", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_5->horizontalHeaderItem(6);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "action", nullptr));

        const bool __sortingEnabled1 = tableWidget_5->isSortingEnabled();
        tableWidget_5->setSortingEnabled(false);
        tableWidget_5->setSortingEnabled(__sortingEnabled1);

        pushButton_14->setText(QCoreApplication::translate("MainWindow", "statistique", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Liste des mat\303\251riels", nullptr));
        ajmateriel_5->setText(QCoreApplication::translate("MainWindow", "ajouter mat\303\251riel", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "quantit\303\251", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "cout", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "etat", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "date d'achat", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "Garantie", nullptr));
        lineEdit_25->setText(QString());
        lineEdit_26->setText(QString());
        lineEdit_27->setText(QString());
        lineEdit_28->setText(QString());
        lineEdit_29->setText(QString());
        lineEdit_30->setText(QString());
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "modifier ce formulaire", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "remplir ce formulaire", nullptr));
        lineEdit_nom->setText(QString());
        lineEdit_prenom->setText(QString());
        lineEdit_prix->setText(QString());
        lineEdit_tel->setText(QString());
        lineEdit_adresse->setText(QString());
        lineEdit_type->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Prix", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        ajouterClient->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Date d'inscription", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Modifier le client ", nullptr));
        n->setText(QString());
        p->setText(QString());
        pr->setText(QString());
        t->setText(QString());
        a->setText(QString());
        ty->setText(QString());
        label_23->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Prix", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        modifierClient->setText(QCoreApplication::translate("MainWindow", "Mettre \303\240 jour", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Date d'inscription", nullptr));
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
