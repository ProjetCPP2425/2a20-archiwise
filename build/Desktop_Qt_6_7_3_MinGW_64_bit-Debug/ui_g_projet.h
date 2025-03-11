/********************************************************************************
** Form generated from reading UI file 'g_projet.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_G_PROJET_H
#define UI_G_PROJET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QPushButton *pushButton_3;
    QPushButton *pushButton_8;
    QLabel *label_20;
    QWidget *page_6;
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
        MainWindow->resize(1379, 747);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(240, 0, 1141, 781));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName("page");
        maincontent_2 = new QWidget(page);
        maincontent_2->setObjectName("maincontent_2");
        maincontent_2->setGeometry(QRect(0, 40, 1061, 761));
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
        stackedWidget_2->setGeometry(QRect(0, 0, 1021, 691));
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
        label_14 = new QLabel(page_5);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(102, 109, 131, 31));
        label_14->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_15 = new QLabel(page_5);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(102, 170, 131, 41));
        label_15->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_16 = new QLabel(page_5);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(112, 239, 121, 31));
        label_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_17 = new QLabel(page_5);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(110, 300, 111, 31));
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_18 = new QLabel(page_5);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(100, 360, 121, 41));
        label_18->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        label_19 = new QLabel(page_5);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(112, 420, 131, 51));
        label_19->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        lineEdit_10 = new QLineEdit(page_5);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(240, 100, 301, 51));
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
        lineEdit_11 = new QLineEdit(page_5);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(240, 160, 301, 51));
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
        lineEdit_12 = new QLineEdit(page_5);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(240, 230, 301, 51));
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
        lineEdit_13 = new QLineEdit(page_5);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setGeometry(QRect(240, 290, 301, 51));
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
        lineEdit_14 = new QLineEdit(page_5);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setGeometry(QRect(240, 420, 301, 51));
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
        lineEdit_15 = new QLineEdit(page_5);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setGeometry(QRect(240, 360, 301, 51));
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
        pushButton_3 = new QPushButton(page_5);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(240, 530, 141, 41));
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
        pushButton_8->setGeometry(QRect(390, 530, 141, 41));
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
        label_20 = new QLabel(page_5);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(320, 30, 231, 51));
        label_20->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 14px; /* Taille de la police */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    color: #333333; /* Couleur du texte gris fonc\303\251 */\n"
"}"));
        stackedWidget_2->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        stackedWidget_2->addWidget(page_6);
        stackedWidget->addWidget(page_3);
        side = new QWidget(centralWidget);
        side->setObjectName("side");
        side->setGeometry(QRect(0, 40, 231, 701));
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
        menuBar->setGeometry(QRect(0, 0, 1379, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
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
        label->setText(QCoreApplication::translate("MainWindow", "Liste des projets", nullptr));
        ajmateriel_3->setText(QCoreApplication::translate("MainWindow", "ajouter projet", nullptr));
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
        label_14->setText(QCoreApplication::translate("MainWindow", "nom", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "quantit\303\251", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "cout", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "etat", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "date d'achat", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Garantie", nullptr));
        lineEdit_10->setText(QString());
        lineEdit_11->setText(QString());
        lineEdit_12->setText(QString());
        lineEdit_13->setText(QString());
        lineEdit_14->setText(QString());
        lineEdit_15->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "annuler", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "modifier ce formulaire", nullptr));
        titlelabel_2->setText(QCoreApplicatiprivate slots:
                              void on_ajmateriel_4_clicked();
                              on::translate("MainWindow", "<html><head/><body><p align=\"center\">Archi<span style=\" font-weight:700; color:#3282f6;\">Wise</span></p></body></html>", nullptr));
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

#endif // UI_G_PROJET_H
