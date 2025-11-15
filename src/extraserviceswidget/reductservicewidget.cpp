#include "reductservicewidget.h"
#include "ui_reductservicewidget.h"

ReductServiceWidget::ReductServiceWidget( QString oldName, double oldPrice, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReductServiceWidget)
{
    ui->setupUi(this);

    ui->lineEdit_oldServiceName->setText(oldName);
    ui->lineEdit_oldServiceName->setDisabled(true);

    ui->lineEdit_oldServicePrice->setText(QString::number(oldPrice));
    ui->lineEdit_oldServicePrice->setDisabled(true);

    // Настраиваем валидаторы
    // Для названия услуги - любые символы, но не пустая строка
    QRegExp nameRegex(".+");
    QRegExpValidator *nameValidator = new QRegExpValidator(nameRegex, this);
    ui->lineEdit_newServiceName->setValidator(nameValidator);

    // Для стоимости - только числа (целые или дробные)
    QDoubleValidator *costValidator = new QDoubleValidator(0.0, 999999.99, 2, this);
    costValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_newServicePrice->setValidator(costValidator);

    // Подключаем сигналы изменения текста для валидации
    connect(ui->lineEdit_newServiceName, &QLineEdit::textChanged, this, &ReductServiceWidget::validateInputs);
    connect(ui->lineEdit_newServicePrice, &QLineEdit::textChanged, this, &ReductServiceWidget::validateInputs);

    // Настраиваем кнопку OK
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    okButton->setEnabled(false);

    // Вызываем валидацию для начального состояния
    validateInputs();
}

ReductServiceWidget::~ReductServiceWidget()
{
    delete ui;
}


QString ReductServiceWidget::serviceName() const
{
    return ui->lineEdit_newServiceName->text().trimmed();
}

double ReductServiceWidget::serviceCost() const
{
    bool ok;
    double cost = ui->lineEdit_newServicePrice->text().replace(',', '.').toDouble(&ok);
    return ok ? cost : 0.0;
}

void ReductServiceWidget::validateInputs()
{
    // Проверяем, что название не пустое
    bool nameValid = !ui->lineEdit_newServiceName->text().trimmed().isEmpty();

    // Проверяем, что стоимость - валидное число
    QString costText = ui->lineEdit_newServicePrice->text();
    bool costValid = false;
    if (!costText.isEmpty()) {
        costText.replace(',', '.');
        costText.toDouble(&costValid);
    }

    m_isValid = nameValid && costValid;

    // Активируем/деактивируем кнопку OK
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    okButton->setEnabled(m_isValid);

    // Показываем подсказки
    if (!nameValid) {
        ui->lineEdit_newServiceName->setStyleSheet("border: 1px solid red;");
    } else {
        ui->lineEdit_newServiceName->setStyleSheet("");
    }

    if (!costValid && !costText.isEmpty()) {
        ui->lineEdit_newServicePrice->setStyleSheet("border: 1px solid red;");
    } else {
        ui->lineEdit_newServicePrice->setStyleSheet("");
    }
}
