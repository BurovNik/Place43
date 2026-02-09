#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_menuWidget = new MenuWidget(this);
//    connect(ui->pushButton_allCards, &QPushButton::clicked, this, &MainWindow::slot_allCardsButtonClicked);
//    connect(ui->pushButton_activeCards, &QPushButton::clicked, this, &MainWindow::slot_activeCardsButtonClicked);
//    connect(ui->pushButton_extraServices, &QPushButton::clicked, this, &MainWindow::slot_extraServicesButtonCLicked);
//    connect(ui->pushButton_history, &QPushButton::clicked, this, &MainWindow::slot_historyButtonClicked);
//    connect(ui->pushButton_reservations, &QPushButton::clicked, this, &MainWindow::slot_reservationsButtonClicked);

    m_extraServicesWidget = new ExtraServicesWidget(this);
    int extraServicesIndex = ui->stackedWidget->addWidget(m_extraServicesWidget);
    ui->stackedWidget->setCurrentIndex(extraServicesIndex);

    m_activeCardsWidget = new ActiveCardsWidget(this);
    int activeCardsIndex = ui->stackedWidget->addWidget(m_activeCardsWidget);
    ui->stackedWidget->setCurrentIndex(activeCardsIndex);

    m_reservationsWidget = new ReservationsWidget(this);
    int reservationsIndex = ui->stackedWidget->addWidget(m_reservationsWidget);


    ui->label_programName->setText(tr("Place43"));
    ui->label_activeCards->setText(tr("Посетителей в кафе:"));
    ui->label_activeCardsNumber->setText(tr("1"));
    slot_setDarkTheme(false);
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
    ui->stackedWidget->setCurrentWidget(m_activeCardsWidget);
}

void MainWindow::slot_historyButtonClicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_history);
}

void MainWindow::slot_extraServicesButtonCLicked()
{
    ui->stackedWidget->setCurrentWidget(m_extraServicesWidget);
}

void MainWindow::slot_reservationsButtonClicked()
{
    ui->stackedWidget->setCurrentWidget(m_reservationsWidget);
}

void MainWindow::slot_setDarkTheme(bool isDark)
{
    QString filePath;
    if (!isDark)
        filePath = ":/LightThemeStyles.qss";
    QFile file(filePath);
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    qApp->setStyleSheet(styleSheet);
}

