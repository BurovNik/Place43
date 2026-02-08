#ifndef RESERVATIONSWIDGET_H
#define RESERVATIONSWIDGET_H

#include <QWidget>
#include "addreservationdialog.h"

namespace Ui {
class ReservationsWidget;
}

class ReservationsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReservationsWidget(QWidget *parent = nullptr);
    ~ReservationsWidget();
private slots:
    void slot_addreservationsButtonClicked();

private:
    Ui::ReservationsWidget *ui;
    AddReservationDialog *m_addReservationsDialog;
};

#endif // RESERVATIONSWIDGET_H
