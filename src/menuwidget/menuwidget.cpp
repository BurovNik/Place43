//#include "menuwidget.h"
//#include "ui_menuwidget.h"

//MenuWidget::MenuWidget(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::MenuWidget)
//{
//    ui->setupUi(this);

//    ui->verticalLayout;
//}



//MenuWidget::~MenuWidget()
//{
//    delete ui;
//}

//QPushButton *MenuWidget::addButton(QString buttonText, QString iconPath)
//{
//    // Создаем кнопку
//        QPushButton *button = new QPushButton(buttonText);
//        button->setCursor(Qt::PointingHandCursor);

//        // Добавляем кнопку в layout (перед растягивающимся элементом)
//        ui->verticalLayout->addWidget(button);

//        // Сохраняем информацию о кнопке
//        MenuButton menuButton;
//        menuButton.button = button;
//        menuButton.id = buttonId.isEmpty() ? buttonText : buttonId;
//        menuButton.text = buttonText;
//        buttons.append(menuButton);

//        // Подключаем сигнал
//        connect(button, &QPushButton::clicked, this, &MenuWidget::onButtonClicked);
//}
