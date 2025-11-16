#include "cardmodel.h"

CardModel::CardModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int CardModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : m_cards.size();
}

int CardModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 5; // ID, Номер, Имя, Статус, Скидка, Последний визит
}

QVariant CardModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    const Card &card = m_cards[index.row()];
    switch (index.column()) {
    case 0: return card.cardId();
    case 1: return QString::number(card.cardNumber());
    case 2: return card.cardName();
    case 3: return statusToString(card.status());
    case 4: return discountToString(card.discount());
    case 5: return card.lastVisit().toString("dd.MM.yyyy hh:mm");
    default: return QVariant();
    }
}

QVariant CardModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole || orientation != Qt::Horizontal)
        return QVariant();

    switch (section) {
    case 0: return "ID";
    case 1: return "Номер карты";
    case 2: return "Имя";
    case 3: return "Статус";
    case 4: return "Скидка";
    case 5: return "Последний визит";
    default: return QVariant();
    }
}

void CardModel::populate(const QList<Card> &cards)
{
    beginResetModel();
    m_cards = cards;
    endResetModel();
}

Card CardModel::getCard(const QModelIndex &index) const
{
    if (!index.isValid() || index.row() >= m_cards.size())
        return Card();

    return m_cards.at(index.row());
}

Card CardModel::getCard(int row) const
{
    if (row < 0 || row >= m_cards.size())
        return Card();

    return m_cards.at(row);
}

void CardModel::updateCard(int row, const Card &card)
{
    if (row < 0 || row >= m_cards.size())
        return;

    beginResetModel();
    m_cards[row] = card;
    endResetModel();
}

void CardModel::addCard(const Card &card)
{
    beginInsertRows(QModelIndex(), m_cards.size(), m_cards.size());
    m_cards.append(card);
    endInsertRows();
}

void CardModel::removeCard(int row)
{
    if (row < 0 || row >= m_cards.size())
        return;

    beginRemoveRows(QModelIndex(), row, row);
    m_cards.removeAt(row);
    endRemoveRows();
}

QString CardModel::statusToString(E_cardStatus status) const
{
    switch (status) {
    case Open: return "Открыта";
    case Closed: return "Закрыта";
    case Deleted: return "Удалена";
    default: return "Неизвестно";
    }
}

QString CardModel::discountToString(E_dicount discount) const
{
    switch (discount) {
    case e_10: return "10%";
    case e_25: return "25%";
    case e_50: return "50%";
    default: return "0%";
    }
}
