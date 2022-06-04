#include "add.h"

Add::Add(QWidget *parent)
{
//    this->setFixedSize(400,400);
    QGridLayout * gridLayout = new QGridLayout();
    this->setLayout(gridLayout);
    this->setWindowTitle("Добавление мотоцикла");

    // Блок объявления кнопок
    QPushButton * add = new QPushButton("Добавить мотоцикл в базу");
    QLabel *strip1 = new QLabel("Введите фамилию владельца:");
    QLabel *strip2 = new QLabel("Введите модель мотоцикла:");
    QLabel *strip3 = new QLabel("Введите год выпуска мотоцикла:");
    QLabel *strip4 = new QLabel("Введите гос.номер мотоцикла:");
    sur = new QLineEdit();
    model = new QLineEdit();
    year = new QLineEdit();
    serial = new QLineEdit();


    // Блок связи кнопок и нажатий на них
    connect(add, SIGNAL(clicked()), this, SLOT(Append()));

    // Блок добавления кнопок в LayOut
    gridLayout->addWidget(strip1);
    gridLayout->addWidget(sur);
    gridLayout->addWidget(strip2);
    gridLayout->addWidget(model);
    gridLayout->addWidget(strip3);
    gridLayout->addWidget(year);
    gridLayout->addWidget(strip4);
    gridLayout->addWidget(serial);
    gridLayout->addWidget(add);

};

void Add::Append(){
    Info data;
    if (sur->text() != "" and model->text() != "" and year->text().toInt() and serial->text() != ""){
        data.surname = sur->text();
        data.model = model->text();
        data.year = year->text().toInt();
        data.serial = serial->text();
        addzap(data);
    }
    sur->clear();
    model->clear();
    year->clear();
    serial->clear();

//    QVector<Info> test = getall();
//    sur->setText(test[1].surname);
}
