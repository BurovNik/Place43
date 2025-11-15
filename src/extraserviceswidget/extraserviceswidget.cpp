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

    // НАСТРОЙКИ ВЫДЕЛЕНИЯ СТРОКИ
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    // Заполняем начальными данными
    setupInitialData();

    // Подключаем кнопки
    connect(ui->pushButton_3, &QPushButton::clicked, this, &ExtraServicesWidget::onAddClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &ExtraServicesWidget::onEditClicked);
    connect(ui->pushButton, &QPushButton::clicked, this, &ExtraServicesWidget::onDeleteClicked);

    // Подключаем двойной клик для редактирования
    connect(ui->tableView, &QTableView::doubleClicked, this, &ExtraServicesWidget::onEditClicked);

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

        // ГЕНЕРИРУЕМ НОВЫЙ ID (максимальный существующий + 1)
        int newId = 0;
        if (!m_model->getServices().isEmpty()) {
            // Находим максимальный ID
            for (const ExtraService &service : m_model->getServices()) {
                if (service.id > newId) {
                    newId = service.id;
                }
            }
            newId++;
        }

        // ДОБАВЛЯЕМ НОВУЮ УСЛУГУ
        ExtraService newService{newId, name, cost};
        m_model->addService(newService);

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

    // ПОЛУЧАЕМ ДАННЫЕ ВЫБРАННОЙ УСЛУГИ
    ExtraService service = m_model->getService(currentIndex);

    // ПЕРЕДАЕМ ДАННЫЕ В ДИАЛОГ
    ReductServiceWidget dialog(service.name, service.cost, this);
    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.serviceName();
        double cost = dialog.serviceCost();

        // ОБНОВЛЯЕМ ДАННЫЕ В МОДЕЛИ
        service.name = name;
        service.cost = cost;
        m_model->updateService(currentIndex.row(), service);

        QMessageBox::information(this, "Успех",
                               QString("Услуга изменена:\nНазвание: %1\nСтоимость: %2 руб.")
                               .arg(name).arg(cost));
    }
}

void ExtraServicesWidget::onDeleteClicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::warning(this, "Предупреждение", "Выберите услугу для удаления");
        return;
    }

    ExtraService service = m_model->getService(currentIndex);

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение удаления",
                                QString("Вы действительно хотите удалить услугу \"%1\"?")
                                .arg(service.name),
                                QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        m_model->removeService(currentIndex.row());
        QMessageBox::information(this, "Успех", "Услуга удалена");
    }
}
