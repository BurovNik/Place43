#ifndef EXTRASERVICESWIDGET_H
#define EXTRASERVICESWIDGET_H

#include <QWidget>
#include "src/utility/extraservicemodel.h"
#include "src/utility/buttontabledelegate.h"
#include "addextraservicedialog.h"
#include "reductservicewidget.h"

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

    void slot_onUpdateButtonClicked(int row, int column);
    void slot_onDeleteButtonClicked(int row, int column);
    void slot_onTableButtonClicked(int row, int column);

signals:
    void signal_updateCard(const ExtraService &service);
    void signal_deleteCard(const ExtraService &service);

private:
    void setupInitialData();

    Ui::ExtraServicesWidget *ui;
    ExtraServiceModel *m_model; // Добавлен указатель на модель
    ButtonTableDelegate *m_buttonDelegate;

};

#endif // EXTRASERVICESWIDGET_H
