#include "addreservationdialog.h"
#include "ui_addreservationdialog.h"

AddReservationDialog::AddReservationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddReservationDialog)
{
    ui->setupUi(this);
}

AddReservationDialog::~AddReservationDialog()
{
    delete ui;
}
