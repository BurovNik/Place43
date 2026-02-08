#include "reservationswidget.h"
#include "ui_reservationswidget.h"

ReservationsWidget::ReservationsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReservationsWidget)
{
    ui->setupUi(this);

    ui->pushButton_addReservation->setProperty("style", "primaryButton");
    ui->label_pageName->setText(tr("Брони"));
    ui->label_pageName->setProperty("style", "pageNameLabel");
}

ReservationsWidget::~ReservationsWidget()
{
    delete ui;
}
