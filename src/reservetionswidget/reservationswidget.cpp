#include "reservationswidget.h"
#include "ui_reservationswidget.h"

ReservationsWidget::ReservationsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReservationsWidget)
{
    ui->setupUi(this);

    ui->pushButton_addReservation->setProperty("style", "primaryButton");
    connect(ui->pushButton_addReservation, &QPushButton::clicked, this, &ReservationsWidget::slot_addreservationsButtonClicked);
    ui->label_pageName->setText(tr("Брони"));
    ui->label_pageName->setProperty("style", "pageNameLabel");
    m_addReservationsDialog = new AddReservationDialog(this);
    m_addReservationsDialog->hide();


}

ReservationsWidget::~ReservationsWidget()
{
    delete ui;
}

void ReservationsWidget::slot_addreservationsButtonClicked()
{
    m_addReservationsDialog->show();
}
