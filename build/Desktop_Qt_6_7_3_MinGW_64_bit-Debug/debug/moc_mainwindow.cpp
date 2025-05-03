/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_btnAjouter_clicked",
    "",
    "on_modifier_clicked",
    "on_annuler_modification_clicked",
    "on_annuler_ajout_clicked",
    "afficherStatistiquesContrats",
    "on_annuler_recherche_clicked",
    "on_pushButtonExporter_clicked",
    "rappelContratsFinissants",
    "afficherStatistiquesPartenaires",
    "on_recherche_clicked",
    "onDeleteClicked",
    "row",
    "onEditClicked",
    "setupTableView",
    "setupSerialPort",
    "on_nouvelle_disccusion_clicked",
    "initialiserCompleter",
    "on_sendButton_clicked",
    "ajouterMessageUtilisateur",
    "message",
    "ajouterMessageBot",
    "verifierPartenaire",
    "id",
    "sendToArduino",
    "readSerialData",
    "on_switch_partenaire_clicked",
    "on_switch_employe_clicked",
    "on_btn_add_clicked",
    "on_btn_delete_clicked",
    "on_btn_refresh_clicked",
    "on_pdf_clicked",
    "on_btn_stats_clicked",
    "on_btn_tri_clicked",
    "on_btn_recherche_clicked",
    "on_btn_reset_recherche_clicked",
    "showEvent",
    "QShowEvent*",
    "event",
    "button_hajjouni",
    "on_pushButton_ajout_clicked",
    "on_modifier_chantier_clicked",
    "chantier",
    "c",
    "on_delete_chantier_clicked",
    "on_pushButton_clicked",
    "on_pushButton_3_clicked",
    "on_pushButton_8_clicked",
    "on_pushButton_2_clicked",
    "on_recherche_input_textChanged",
    "arg1",
    "on_comboBox_currentTextChanged",
    "on_pushButton_4_clicked",
    "on_pushButton_13_clicked",
    "on_pushButton_5_clicked",
    "on_pushButton_ajout_2_clicked",
    "detecterChantiersEnRetard",
    "on_tableView_clicked",
    "QModelIndex",
    "index",
    "on_btnchantiers_2_clicked",
    "on_pushButton_6_clicked",
    "on_pushButton_9_clicked",
    "on_pushButton_14_clicked",
    "on_pushButton_15_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      54,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  338,    2, 0x0a,    1 /* Public */,
       3,    0,  339,    2, 0x0a,    2 /* Public */,
       4,    0,  340,    2, 0x0a,    3 /* Public */,
       5,    0,  341,    2, 0x0a,    4 /* Public */,
       6,    0,  342,    2, 0x0a,    5 /* Public */,
       7,    0,  343,    2, 0x0a,    6 /* Public */,
       8,    0,  344,    2, 0x0a,    7 /* Public */,
       9,    0,  345,    2, 0x0a,    8 /* Public */,
      10,    0,  346,    2, 0x0a,    9 /* Public */,
      11,    0,  347,    2, 0x0a,   10 /* Public */,
      12,    1,  348,    2, 0x0a,   11 /* Public */,
      14,    1,  351,    2, 0x0a,   13 /* Public */,
      15,    0,  354,    2, 0x0a,   15 /* Public */,
      16,    0,  355,    2, 0x0a,   16 /* Public */,
      17,    0,  356,    2, 0x08,   17 /* Private */,
      18,    0,  357,    2, 0x08,   18 /* Private */,
      19,    0,  358,    2, 0x08,   19 /* Private */,
      20,    1,  359,    2, 0x08,   20 /* Private */,
      22,    1,  362,    2, 0x08,   22 /* Private */,
      23,    1,  365,    2, 0x08,   24 /* Private */,
      25,    1,  368,    2, 0x08,   26 /* Private */,
      26,    0,  371,    2, 0x08,   28 /* Private */,
      27,    0,  372,    2, 0x08,   29 /* Private */,
      28,    0,  373,    2, 0x08,   30 /* Private */,
      29,    0,  374,    2, 0x08,   31 /* Private */,
      30,    0,  375,    2, 0x08,   32 /* Private */,
      31,    0,  376,    2, 0x08,   33 /* Private */,
      32,    0,  377,    2, 0x08,   34 /* Private */,
      33,    0,  378,    2, 0x08,   35 /* Private */,
      34,    0,  379,    2, 0x08,   36 /* Private */,
      35,    0,  380,    2, 0x08,   37 /* Private */,
      36,    0,  381,    2, 0x08,   38 /* Private */,
      37,    1,  382,    2, 0x08,   39 /* Private */,
      40,    0,  385,    2, 0x08,   41 /* Private */,
      41,    0,  386,    2, 0x08,   42 /* Private */,
      42,    1,  387,    2, 0x08,   43 /* Private */,
      45,    1,  390,    2, 0x08,   45 /* Private */,
      46,    0,  393,    2, 0x08,   47 /* Private */,
      47,    0,  394,    2, 0x08,   48 /* Private */,
      48,    0,  395,    2, 0x08,   49 /* Private */,
      49,    0,  396,    2, 0x08,   50 /* Private */,
      50,    1,  397,    2, 0x08,   51 /* Private */,
      52,    1,  400,    2, 0x08,   53 /* Private */,
      53,    0,  403,    2, 0x08,   55 /* Private */,
      54,    0,  404,    2, 0x08,   56 /* Private */,
      55,    0,  405,    2, 0x08,   57 /* Private */,
      56,    0,  406,    2, 0x08,   58 /* Private */,
      57,    0,  407,    2, 0x08,   59 /* Private */,
      58,    1,  408,    2, 0x08,   60 /* Private */,
      61,    0,  411,    2, 0x08,   62 /* Private */,
      62,    0,  412,    2, 0x08,   63 /* Private */,
      63,    0,  413,    2, 0x08,   64 /* Private */,
      64,    0,  414,    2, 0x08,   65 /* Private */,
      65,    0,  415,    2, 0x08,   66 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 43,   44,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   51,
    QMetaType::Void, QMetaType::QString,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 59,   60,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_btnAjouter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_modifier_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_annuler_modification_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_annuler_ajout_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherStatistiquesContrats'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_annuler_recherche_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButtonExporter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rappelContratsFinissants'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherStatistiquesPartenaires'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_recherche_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onEditClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setupTableView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setupSerialPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_nouvelle_disccusion_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initialiserCompleter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sendButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ajouterMessageUtilisateur'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'ajouterMessageBot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'verifierPartenaire'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'sendToArduino'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'readSerialData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_switch_partenaire_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_switch_employe_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_add_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_delete_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_refresh_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pdf_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_stats_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_tri_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_recherche_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_reset_recherche_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QShowEvent *, std::false_type>,
        // method 'button_hajjouni'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_ajout_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_modifier_chantier_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<chantier, std::false_type>,
        // method 'on_delete_chantier_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_8_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_recherche_input_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_comboBox_currentTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_13_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_ajout_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'detecterChantiersEnRetard'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableView_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_btnchantiers_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_6_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_9_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_14_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_15_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btnAjouter_clicked(); break;
        case 1: _t->on_modifier_clicked(); break;
        case 2: _t->on_annuler_modification_clicked(); break;
        case 3: _t->on_annuler_ajout_clicked(); break;
        case 4: _t->afficherStatistiquesContrats(); break;
        case 5: _t->on_annuler_recherche_clicked(); break;
        case 6: _t->on_pushButtonExporter_clicked(); break;
        case 7: _t->rappelContratsFinissants(); break;
        case 8: _t->afficherStatistiquesPartenaires(); break;
        case 9: _t->on_recherche_clicked(); break;
        case 10: _t->onDeleteClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->onEditClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->setupTableView(); break;
        case 13: _t->setupSerialPort(); break;
        case 14: _t->on_nouvelle_disccusion_clicked(); break;
        case 15: _t->initialiserCompleter(); break;
        case 16: _t->on_sendButton_clicked(); break;
        case 17: _t->ajouterMessageUtilisateur((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->ajouterMessageBot((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->verifierPartenaire((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->sendToArduino((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: _t->readSerialData(); break;
        case 22: _t->on_switch_partenaire_clicked(); break;
        case 23: _t->on_switch_employe_clicked(); break;
        case 24: _t->on_btn_add_clicked(); break;
        case 25: _t->on_btn_delete_clicked(); break;
        case 26: _t->on_btn_refresh_clicked(); break;
        case 27: _t->on_pdf_clicked(); break;
        case 28: _t->on_btn_stats_clicked(); break;
        case 29: _t->on_btn_tri_clicked(); break;
        case 30: _t->on_btn_recherche_clicked(); break;
        case 31: _t->on_btn_reset_recherche_clicked(); break;
        case 32: _t->showEvent((*reinterpret_cast< std::add_pointer_t<QShowEvent*>>(_a[1]))); break;
        case 33: _t->button_hajjouni(); break;
        case 34: _t->on_pushButton_ajout_clicked(); break;
        case 35: _t->on_modifier_chantier_clicked((*reinterpret_cast< std::add_pointer_t<chantier>>(_a[1]))); break;
        case 36: _t->on_delete_chantier_clicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 37: _t->on_pushButton_clicked(); break;
        case 38: _t->on_pushButton_3_clicked(); break;
        case 39: _t->on_pushButton_8_clicked(); break;
        case 40: _t->on_pushButton_2_clicked(); break;
        case 41: _t->on_recherche_input_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 42: _t->on_comboBox_currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 44: _t->on_pushButton_13_clicked(); break;
        case 45: _t->on_pushButton_5_clicked(); break;
        case 46: _t->on_pushButton_ajout_2_clicked(); break;
        case 47: _t->detecterChantiersEnRetard(); break;
        case 48: _t->on_tableView_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 49: _t->on_btnchantiers_2_clicked(); break;
        case 50: _t->on_pushButton_6_clicked(); break;
        case 51: _t->on_pushButton_9_clicked(); break;
        case 52: _t->on_pushButton_14_clicked(); break;
        case 53: _t->on_pushButton_15_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 54)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 54;
    }
    return _id;
}
QT_WARNING_POP
