#ifndef ADDRESERVATIONDIALOG_H
#define ADDRESERVATIONDIALOG_H

#include <QDialog>

namespace Ui {
class AddReservationDialog;
}

class AddReservationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddReservationDialog(QWidget *parent = nullptr);
    ~AddReservationDialog();

private:
    Ui::AddReservationDialog *ui;
};

#endif // ADDRESERVATIONDIALOG_H
