QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/extraserviceswidget/extraserviceswidget.cpp \
    src/menuwidget/menuwidget.cpp \
    src/extraserviceswidget/addextraservicedialog.cpp \
    src/utility/extraservicemodel.cpp

HEADERS += \
    src/mainwindow.h \
    src/extraserviceswidget/extraserviceswidget.h \
    src/menuwidget/menuwidget.h \
    src/extraserviceswidget/addextraservicedialog.h \
    src/utility/extraService.h \
    src/utility/extraservicemodel.h

FORMS += \
    src/mainwindow.ui \
    src/extraserviceswidget/extraserviceswidget.ui \
    src/menuwidget/menuwidget.ui \
    src/extraserviceswidget/addextraservicedialog.ui

TRANSLATIONS += \
    Place_43_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
