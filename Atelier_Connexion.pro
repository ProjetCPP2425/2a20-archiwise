QT += core gui sql printsupport charts
QT += core gui widgets sql texttospeech charts
QT += printsupport quickwidgets
QT += network
QT += serialport

QT += core gui sql network

QT += core gui sql printsupport
QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += qt6 c++17

TARGET = Atelier_Connexion
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    buttondelegate.cpp \
    chantier.cpp \
    chantierdelegate.cpp \
    client.cpp \
    main.cpp \
    mainwindow.cpp \
    connection.cpp \
    partenaire.cpp\
    barchartwidget.cpp\
    employe.cpp \
    projet.cpp \
    serialtemperaturemanager.cpp \
    sms.cpp

HEADERS += \
    buttondelegate.h \
    chantier.h \
    chantierdelegate.h \
    client.h \
    mainwindow.h \
    connection.h \
    partenaire.h\
    barchartwidget.h\
    employe.h \
    projet.h \
    serialtemperaturemanager.h \
    sms.h

FORMS += \
    mainwindow.ui

# Règles de déploiement (à ne pas toucher sauf besoin spécifique)
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    Ressources.qrc
