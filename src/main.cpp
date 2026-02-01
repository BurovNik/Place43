#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "src/utility/databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Place43");
    a.setApplicationVersion("0.0.1");
    // a.setApplicationDisplayName("Place43");
//    QTranslator translator;
//    const QStringList uiLanguages = QLocale::system().uiLanguages();
//    for (const QString &locale : uiLanguages) {
//        const QString baseName = "Place_43_" + QLocale(locale).name();
//        if (translator.load(":/i18n/" + baseName)) {
//            a.installTranslator(&translator);
//            break;
//        }
//    }

    // DatabaseManager& db = DatabaseManager::instance();

       // if (!db.connect("localhost", 5432, "place43db", "user", "pass")) {
         //   return 1;
       // }
    MainWindow w;
    w.setWindowTitle("Place 43");
    w.show();
    return a.exec();
}
