#ifndef EXTRASERVICESWIDGET_H
#define EXTRASERVICESWIDGET_H

#include <QWidget>
#include "utility/extraservicemodel.h"

namespace Ui {
class ExtraServicesWidget;
}

class ExtraServicesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExtraServicesWidget(QWidget *parent = nullptr);
    ~ExtraServicesWidget();

private slots:
    void onAddClicked();
    void onEditClicked();
    void onDeleteClicked();

private:
    void setupInitialData();

    Ui::ExtraServicesWidget *ui;
    ExtraServiceModel *m_model; // Добавлен указатель на модель
};

#endif // EXTRASERVICESWIDGET_H
