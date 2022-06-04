#include "year.h"

Year::Year(QWidget *parent): QWidget(parent)
{
//    this->setFixedSize(400,400);
    QGridLayout * gridLayout = new QGridLayout();
    this->setLayout(gridLayout);
    this->setWindowTitle("Поиск по году выпуска");

    // Блок объявления кнопок
    QPushButton * dl = new QPushButton("Найти м/т не страше указанного года");
    QLabel *strip1 = new QLabel("Введите год выпуска");
    list = new QTextEdit();
    target = new QLineEdit();

    // Блок связи кнопок и нажатий на них
    connect(dl, &QPushButton::clicked, this, &Year::Search);
    list->setReadOnly(true);

    // Блок добавления кнопок в LayOut
    gridLayout->addWidget(strip1);
    gridLayout->addWidget(target);
    gridLayout->addWidget(dl);
    gridLayout->addWidget(list);

};


void Year::Search(){
    QVector<Info> out;
    int trg = QVariant(target->text()).toInt();
    for (Info i: getall()){
        if (i.year >= trg){
            out.push_back(i);
        }
    }
    list->clear();
    {
        int counter = 0;
        for (Info i: out){
            counter += 1;
            list->append(QVariant(counter).toString() + ") "+i.surname + "  " + i.model + " " + QVariant(i.year).toString() + "  " + i.serial);
        }
        if (out.size() == 0){
            list->append("Нет данных");
        }
    }
}
