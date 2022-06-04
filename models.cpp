#include "models.h"

Models::Models(QWidget *parent): QWidget(parent)
{
//    this->setFixedSize(400,400);
    QGridLayout * gridLayout = new QGridLayout();
    this->setLayout(gridLayout);
    this->setWindowTitle("Поиск по модели");

    // Блок объявления кнопок
    QPushButton * dl = new QPushButton("Найти м/т данной модели");
    QLabel *strip1 = new QLabel("Введите модель");
    list = new QTextEdit();
    target = new QLineEdit();

    // Блок связи кнопок и нажатий на них
    connect(dl, &QPushButton::clicked, this, &Models::Search);
    list->setReadOnly(true);

    // Блок добавления кнопок в LayOut
    gridLayout->addWidget(strip1);
    gridLayout->addWidget(target);
    gridLayout->addWidget(dl);
    gridLayout->addWidget(list);

};


void Models::Search(){
    QVector<Info> out;
    QString trg = target->text();
    for (Info i: getall()){
        if (i.model == trg){
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
