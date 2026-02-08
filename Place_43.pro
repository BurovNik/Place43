QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Place43

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/activecardswidget/activecardswidget.cpp \
    src/activecardswidget/addcarddialog.cpp \
    src/extraserviceswidget/reductservicewidget.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/extraserviceswidget/extraserviceswidget.cpp \
    src/menuwidget/menuwidget.cpp \
    src/extraserviceswidget/addextraservicedialog.cpp \
    src/reservetionswidget/reservationswidget.cpp \
    src/utility/buttontabledelegate.cpp \
    src/utility/cardmodel.cpp \
    # src/utility/databasemanager.cpp \
    src/utility/extraservicemodel.cpp

HEADERS += \
    src/activecardswidget/activecardswidget.h \
    src/activecardswidget/addcarddialog.h \
    src/extraserviceswidget/reductservicewidget.h \
    src/mainwindow.h \
    src/extraserviceswidget/extraserviceswidget.h \
    src/menuwidget/menuwidget.h \
    src/extraserviceswidget/addextraservicedialog.h \
    src/reservetionswidget/reservationswidget.h \
    src/utility/Cards.h \
    src/utility/buttontabledelegate.h \
    src/utility/cardmodel.h \
    # src/utility/databasemanager.h \
    src/utility/extraService.h \
    src/utility/extraservicemodel.h

FORMS += \
    src/activecardswidget/activecardswidget.ui \
    src/activecardswidget/addcarddialog.ui \
    src/extraserviceswidget/reductservicewidget.ui \
    src/mainwindow.ui \
    src/extraserviceswidget/extraserviceswidget.ui \
    src/menuwidget/menuwidget.ui \
    src/extraserviceswidget/addextraservicedialog.ui \
    src/reservetionswidget/reservationswidget.ui

# TRANSLATIONS += \
    # Place_43_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    config.json

RESOURCES += \
    res/res.qrc
