#include "surname.h"

Surname::Surname(QWidget *parent): QWidget(parent)
{
//    this->setFixedSize(400,400);
    QGridLayout * gridLayout = new QGridLayout();
    this->setLayout(gridLayout);
    this->setWindowTitle("Поиск по фамилии владельца");

    // Блок объявления кнопок
    QPushButton * dl = new QPushButton("Найти м/т данного человека");
    QLabel *strip1 = new QLabel("Введите фамилию");
    list = new QTextEdit();
    target = new QLineEdit();

    // Блок связи кнопок и нажатий на них
    connect(dl, &QPushButton::clicked, this, &Surname::Search);
    list->setReadOnly(true);

    // Блок добавления кнопок в LayOut
    gridLayout->addWidget(strip1);
    gridLayout->addWidget(target);
    gridLayout->addWidget(dl);
    gridLayout->addWidget(list);

};


void Surname::Search(){
    QVector<Info> out;
    QString trg = target->text();
    for (Info i: getall()){
        if (i.surname == trg){
            out.push_back(i);
        }
    }
    list->clear();
    {
        int counter = 0;
        for (Info i: out){
            counter += 1;
            list->append(QVariant(counter).toString() + ") " + i.model + " " + QVariant(i.year).toString() + "  " + i.serial);
        }
        if (out.size() == 0){
            list->append("Нет данных");
        }
    }
}

