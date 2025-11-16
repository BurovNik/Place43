#ifndef ADDCARDDIALOG_H
#define ADDCARDDIALOG_H

#include <QDialog>
#include "../utility/Cards.h"

namespace Ui {
class AddCardDialog;
}

class AddCardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCardDialog(QWidget *parent = nullptr);
    ~AddCardDialog();

    // Методы для получения данных
    qlonglong cardNumber() const;
    QString cardName() const;
    E_dicount discount() const;

private slots:
    void onAccept();

private:
    void setupUI();
    void setupConnections();

    Ui::AddCardDialog *ui;
};

#endif // ADDCARDDIALOG_H
