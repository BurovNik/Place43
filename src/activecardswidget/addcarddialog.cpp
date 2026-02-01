#include "addcarddialog.h"
#include "ui_addcarddialog.h"

#include <QMessageBox>
#include <QRegExpValidator>

AddCardDialog::AddCardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCardDialog)
{
    ui->setupUi(this);
    setupUI();
    setupConnections();
}

AddCardDialog::~AddCardDialog()
{
    delete ui;
}

void AddCardDialog::setupUI()
{
    // Устанавливаем заголовок окна
    setWindowTitle("Добавление новой карты");

    // Настраиваем валидатор для номера карты (только цифры, максимум 12 цифр)
    QRegExp regExp("[0-9]{0,12}");
    QRegExpValidator *validator = new QRegExpValidator(regExp, this);
    ui->lineEdit_CardNumber->setValidator(validator);
    ui->lineEdit_CardNumber->setDisabled(true);

    // Заполняем комбо-бокс скидками
    ui->comboBox_cardDicount->clear();
    ui->comboBox_cardDicount->addItem("0%", e_0);
    ui->comboBox_cardDicount->addItem("10%", e_10);
    ui->comboBox_cardDicount->addItem("25%", e_25);
    ui->comboBox_cardDicount->addItem("50%", e_50);

    // Устанавливаем скидку по умолчанию
    ui->comboBox_cardDicount->setCurrentIndex(0);

    // Устанавливаем плейсхолдеры
    ui->lineEdit_CardNumber->setPlaceholderText("Введите 12-значный номер карты");
    ui->lineEdit_cardName->setPlaceholderText("Введите название карты");
}

void AddCardDialog::setupConnections()
{
    // Подключаем кнопки OK и Cancel
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &AddCardDialog::onAccept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

void AddCardDialog::onAccept()
{
    // Проверяем валидность данных
    QString cardNumber = ui->lineEdit_CardNumber->text().trimmed();
    QString cardName = ui->lineEdit_cardName->text().trimmed();

    if (cardNumber.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите номер карты");
        ui->lineEdit_CardNumber->setFocus();
        return;
    }

    if (cardNumber.length() != 12) {
        QMessageBox::warning(this, "Ошибка", "Номер карты должен содержать 12 цифр");
        ui->lineEdit_CardNumber->setFocus();
        return;
    }

    if (cardName.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите название карты");
        ui->lineEdit_cardName->setFocus();
        return;
    }

    // Если все данные валидны, принимаем диалог
    accept();
}

qlonglong AddCardDialog::cardNumber() const
{
    return ui->lineEdit_CardNumber->text().toLongLong();
}

QString AddCardDialog::cardName() const
{
    return ui->lineEdit_cardName->text().trimmed();
}

E_discount AddCardDialog::discount() const
{
    // Получаем выбранную скидку из комбо-бокса
    return static_cast<E_discount>(ui->comboBox_cardDicount->currentData().toInt());
}
