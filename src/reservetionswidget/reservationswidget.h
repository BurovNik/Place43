#ifndef RESERVATIONSWIDGET_H
#define RESERVATIONSWIDGET_H

#include <QWidget>

namespace Ui {
class ReservationsWidget;
}

class ReservationsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReservationsWidget(QWidget *parent = nullptr);
    ~ReservationsWidget();

private:
    Ui::ReservationsWidget *ui;
};

#endif // RESERVATIONSWIDGET_H
