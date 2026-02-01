#ifndef CARDMODEL_H
#define CARDMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include "Cards.h"

class CardModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit CardModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    void populate(const QList<Card> &cards);
    Card getCard(const QModelIndex &index) const;
    Card getCard(int row) const;
    void updateCard(int row, const Card &card);
    void addCard(const Card &card);
    void removeCard(int row);
    const QList<Card>& getCards() const { return m_cards; }

private:
    QString statusToString(E_cardStatus status) const;
    QString discountToString(E_discount discount) const;

    QList<Card> m_cards;
};

#endif // CARDMODEL_H
