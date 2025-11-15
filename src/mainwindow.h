#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "extraserviceswidget/extraserviceswidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    int findPageIndexByName(QString name);
private slots:
    void slot_allCardsButtonClicked();
    void slot_activeCardsButtonClicked();
    void slot_historyButtonClicked();
    void slot_extraServicesButtonCLicked();

private:
    Ui::MainWindow *ui;
    ExtraServicesWidget *m_extraServicesWidget;
};
#endif // MAINWINDOW_H
