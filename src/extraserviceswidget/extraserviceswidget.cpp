#include "extraserviceswidget.h"
#include "ui_extraserviceswidget.h"

#include <QMessageBox>

ExtraServicesWidget::ExtraServicesWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ExtraServicesWidget)
{
    ui->setupUi(this);

    // Создаем и настраиваем модель
    m_model = new ExtraServiceModel(this);
    ui->tableView->setModel(m_model);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    // Заполняем начальными данными
    setupInitialData();

    // Подключаем кнопки
    connect(ui->pushButton_3, &QPushButton::clicked, this, &ExtraServicesWidget::onAddClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &ExtraServicesWidget::onEditClicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &ExtraServicesWidget::onDeleteClicked);
}

ExtraServicesWidget::~ExtraServicesWidget()
{
    delete ui;
}

void ExtraServicesWidget::setupInitialData()
{
    QList<ExtraService> services = {
        {0, "услуга", 0},
        {1, "чай авторский", 500.0},
        {2, "кола", 100.0}
    };
    m_model->populate(services);
}

void ExtraServicesWidget::onAddClicked()
{
    AddExtraServiceDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.serviceName();
        double cost = dialog.serviceCost();

           // TODO: Добавить логику для добавления новой услуги в модель
           // Например:
           // int newId = generateNewId(); // Функция для генерации нового ID
           // ExtraService newService(newId, name, cost);
           // m_model->addService(newService);

        QMessageBox::information(this, "Успех",
                                   QString("Добавлена услуга:\nНазвание: %1\nСтоимость: %2 руб.")
                                   .arg(name).arg(cost));
       }
}

void ExtraServicesWidget::onEditClicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Предупреждение", "Выберите услугу для редактирования");
        return;
    }

    // TODO: Реализовать диалог редактирования
    QMessageBox::information(this, "Изменить", "Функция редактирования будет реализована позже");
}

void ExtraServicesWidget::onDeleteClicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Предупреждение", "Выберите услугу для удаления");
        return;
    }

    int row = currentIndex.row();
    // TODO: Реализовать удаление из модели
    QMessageBox::information(this, "Удалить", "Функция удаления будет реализована позже");
}
