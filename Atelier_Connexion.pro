QT += core gui widgets sql texttospeech charts
QT += printsupport
QT += network

CONFIG += c++11

TARGET = Atelier_Connexion
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    buttondelegate.cpp \
    main.cpp \
    mainwindow.cpp \
    connection.cpp \
    partenaire.cpp

HEADERS += \
    buttondelegate.h \
    mainwindow.h \
    connection.h \
    partenaire.h

FORMS += \
    mainwindow.ui

# Règles de déploiement (à ne pas toucher sauf besoin spécifique)
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
