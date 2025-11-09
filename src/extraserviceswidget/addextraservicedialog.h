#ifndef ADDEXTRASERVICEDIALOG_H
#define ADDEXTRASERVICEDIALOG_H

#include <QDialog>

namespace Ui {
class AddExtraServiceDialog;
}

class AddExtraServiceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddExtraServiceDialog(QWidget *parent = nullptr);
    ~AddExtraServiceDialog();

// Геттеры для получения данных
    QString serviceName() const;
    double serviceCost() const;

private slots:
    void validateInputs();

private:
    Ui::AddExtraServiceDialog *ui;
    bool m_isValid;
};

#endif // ADDEXTRASERVICEDIALOG_H
