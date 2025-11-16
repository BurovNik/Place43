#ifndef CARDS_H
#define CARDS_H
#include <QString>
#include <QDateTime>
enum E_cardStatus {
    Open,
    Closed,
    Deleted

};

enum E_dicount {
    e_0,
    e_10,
    e_25,
    e_50
};


class Card {
public:

    Card(int id = 0, qlonglong cardNumber = 0, QString cardName = "name")
        : m_cardId(id), m_cardNumber(cardNumber), m_cardName(cardName) { m_status = Closed;}

    int cardId() const {return m_cardId;}
    qlonglong cardNumber() const {return m_cardNumber;}
    QString cardName() const {return m_cardName;}
    E_cardStatus status() const {return m_status;}
    E_dicount discount() const {return m_discount;}
    QDateTime lastVisit() const {return m_lastVisit;}

    void setCardName(QString name) {m_cardName = name;}
    void setDiscount(E_dicount discount){m_discount = discount;}
    void setLastVisit(QDateTime visitDateTime) {m_lastVisit = visitDateTime;}
private:
    int m_cardId;
    qlonglong m_cardNumber;
    QString m_cardName;
    E_cardStatus m_status;
    E_dicount m_discount;
    QDateTime m_lastVisit;
};

#endif // CARDS_H
