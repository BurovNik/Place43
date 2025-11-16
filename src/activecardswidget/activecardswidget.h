#ifndef ACTIVECARDSWIDGET_H
#define ACTIVECARDSWIDGET_H

#include <QWidget>
#include "../utility/cardmodel.h"
#include "addcarddialog.h"
#include "QMessageBox"

namespace Ui {
class ActiveCardsWidget;
}

class ActiveCardsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ActiveCardsWidget(QWidget *parent = nullptr);
    ~ActiveCardsWidget();

    // Методы для работы с данными извне
    void setCards(const QList<Card> &cards);
    QList<Card> getCards() const;

public slots:
    void onAddClicked();

private:
    // void setupUI();
    void setupInitialData();
    int generateNewId() const;

    Ui::ActiveCardsWidget *ui;
    CardModel *m_model;
};

#endif // ACTIVECARDSWIDGET_H
