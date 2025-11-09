#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_allCards, &QPushButton::clicked, this, &MainWindow::slot_allCardsButtonClicked);
    connect(ui->pushButton_activeCards, &QPushButton::clicked, this, &MainWindow::slot_activeCardsButtonClicked);
    connect(ui->pushButton_extraServices, &QPushButton::clicked, this, &MainWindow::slot_extraServicesButtonCLicked);
    connect(ui->pushButton_history, &QPushButton::clicked, this, &MainWindow::slot_historyButtonClicked);

    m_extraServicesWidget = new ExtraServicesWidget(this);
    int extraServicesIndex = ui->stackedWidget->addWidget(m_extraServicesWidget);
    ui->stackedWidget->setCurrentIndex(extraServicesIndex);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_allCardsButtonClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_allCards);
}

void MainWindow::slot_activeCardsButtonClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_activeCards);
}

void MainWindow::slot_historyButtonClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_history);
}

void MainWindow::slot_extraServicesButtonCLicked()
{
    ui->stackedWidget->setCurrentWidget(m_extraServicesWidget);
}

