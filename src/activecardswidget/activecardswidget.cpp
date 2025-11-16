#include "activecardswidget.h"
#include "ui_activecardswidget.h"

#include <QDateTime>

ActiveCardsWidget::ActiveCardsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ActiveCardsWidget)
    , m_model(new CardModel(this))
{
    ui->setupUi(this);

    // Настраиваем таблицу
    ui->tableView->setModel(m_model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    // Опционально: настройка ширины столбцов
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    setupInitialData();

    connect(ui->pushButton_addCard, &QPushButton::clicked, this, &ActiveCardsWidget::onAddClicked);
}

ActiveCardsWidget::~ActiveCardsWidget()
{
    delete ui;
}

void ActiveCardsWidget::setupInitialData()
{
    // Тестовые данные для демонстрации
    QList<Card> cards;

    Card card1(1, 123456789012, "Карта Василия");
    card1.setDiscount(e_10);
    card1.setLastVisit(QDateTime::currentDateTime().addDays(-5));

    Card card2(2, 987654321098, "Карта Марии");
    card2.setDiscount(e_25);
    card2.setLastVisit(QDateTime::currentDateTime().addDays(-1));

    Card card3(3, 555555555555, "Карта Алексея");
    card3.setDiscount(e_50);
    card3.setLastVisit(QDateTime::currentDateTime());

    cards << card1 << card2 << card3;
    m_model->populate(cards);
}

void ActiveCardsWidget::setCards(const QList<Card> &cards)
{
    m_model->populate(cards);
}

QList<Card> ActiveCardsWidget::getCards() const
{
    return m_model->getCards();
}

void ActiveCardsWidget::onAddClicked()
{
    AddCardDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        // Получаем данные из диалога
        qlonglong cardNumber = dialog.cardNumber();
        QString cardName = dialog.cardName();
        E_dicount discount = dialog.discount();

        // Создаем новую карту
        int newId = generateNewId(); // Функция для генерации нового ID
        Card newCard(newId, cardNumber, cardName);
        newCard.setDiscount(discount);
        newCard.setLastVisit(QDateTime()); // Пустая дата для новой карты

        // Добавляем карту в модель
        m_model->addCard(newCard);

        QMessageBox::information(this, "Успех",
                               QString("Карта успешно добавлена:\nНазвание: %1\nНомер: %2")
                               .arg(cardName)
                               .arg(cardNumber));
    }
}

int ActiveCardsWidget::generateNewId() const
{
    // Простая генерация нового ID (максимальный существующий + 1)
    int maxId = 0;
    for (const Card &card : m_model->getCards()) {
        if (card.cardId() > maxId) {
            maxId = card.cardId();
        }
    }
    return maxId + 1;
}
