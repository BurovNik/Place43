#ifndef REDUCTSERVICEWIDGET_H
#define REDUCTSERVICEWIDGET_H

#include <QDialog>
#include <QRegExpValidator>
#include <QPushButton>

namespace Ui {
class ReductServiceWidget;
}

class ReductServiceWidget : public QDialog
{
    Q_OBJECT

public:
    explicit ReductServiceWidget(QString oldName, double oldPrice, QWidget *parent = nullptr);
    ~ReductServiceWidget();

    QString serviceName() const;
    double serviceCost() const;

private slots:
    void validateInputs();

private:


    Ui::ReductServiceWidget *ui;
    bool m_isValid;
};

#endif // REDUCTSERVICEWIDGET_H
