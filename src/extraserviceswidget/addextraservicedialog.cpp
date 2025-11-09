#include "addextraservicedialog.h"
#include "ui_addextraservicedialog.h"

#include <QDoubleValidator>
#include <QRegExpValidator>
#include <QPushButton>
#include <QMessageBox>

AddExtraServiceDialog::AddExtraServiceDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddExtraServiceDialog)
    , m_isValid(false)
{
    ui->setupUi(this);

    // Настраиваем валидаторы
    // Для названия услуги - любые символы, но не пустая строка
    QRegExp nameRegex(".+");
    QRegExpValidator *nameValidator = new QRegExpValidator(nameRegex, this);
    ui->lineEdit_serviceName->setValidator(nameValidator);

    // Для стоимости - только числа (целые или дробные)
    QDoubleValidator *costValidator = new QDoubleValidator(0.0, 999999.99, 2, this);
    costValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->lineEdit_servicePrice->setValidator(costValidator);

    // Подключаем сигналы изменения текста для валидации
    connect(ui->lineEdit_serviceName, &QLineEdit::textChanged, this, &AddExtraServiceDialog::validateInputs);
    connect(ui->lineEdit_servicePrice, &QLineEdit::textChanged, this, &AddExtraServiceDialog::validateInputs);

    // Настраиваем кнопку OK
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    okButton->setEnabled(false);

    // Вызываем валидацию для начального состояния
    validateInputs();
}

AddExtraServiceDialog::~AddExtraServiceDialog()
{
    delete ui;
}

QString AddExtraServiceDialog::serviceName() const
{
    return ui->lineEdit_serviceName->text().trimmed();
}

double AddExtraServiceDialog::serviceCost() const
{
    bool ok;
    double cost = ui->lineEdit_servicePrice->text().replace(',', '.').toDouble(&ok);
    return ok ? cost : 0.0;
}

void AddExtraServiceDialog::validateInputs()
{
    // Проверяем, что название не пустое
    bool nameValid = !ui->lineEdit_serviceName->text().trimmed().isEmpty();

    // Проверяем, что стоимость - валидное число
    QString costText = ui->lineEdit_servicePrice->text();
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
        ui->lineEdit_serviceName->setStyleSheet("border: 1px solid red;");
    } else {
        ui->lineEdit_serviceName->setStyleSheet("");
    }

    if (!costValid && !costText.isEmpty()) {
        ui->lineEdit_servicePrice->setStyleSheet("border: 1px solid red;");
    } else {
        ui->lineEdit_servicePrice->setStyleSheet("");
    }
}
