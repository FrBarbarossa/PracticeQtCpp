#include "del.h"

Del::Del(QWidget *parent): QWidget(parent)
{
//    this->setFixedSize(400,400);
    QGridLayout * gridLayout = new QGridLayout();
    this->setLayout(gridLayout);
    this->setWindowTitle("Удаление информации");

    // Блок объявления кнопок
    QPushButton * dl = new QPushButton("Удалить данные о м/т по данному номеру");
    QLabel *strip1 = new QLabel("Введите номер для удаления:");
    list = new QTextEdit();
    target = new QLineEdit();

    // Блок связи кнопок и нажатий на них
    connect(dl, &QPushButton::clicked, this, &Del::Dlt);
    list->setReadOnly(true);

    // Блок добавления кнопок в LayOut
    gridLayout->addWidget(strip1);
    gridLayout->addWidget(target);
    gridLayout->addWidget(dl);
    gridLayout->addWidget(list);
    refresh();

};


void Del::Dlt(){
    if (target->text() != ""){
        int trg = target->text().toInt();
        QVector<Info> out = getall();
        out.erase(out.begin()+trg-1);
        dl();
        for (Info i: out){
            addzap(i);
        }
    }
    refresh();

}

void Del::refresh(){
    list->clear();
    {
        int counter = 0;
        for (Info i: getall()){
            counter += 1;
            list->append(QVariant(counter).toString() + ") "+i.surname + "  " + i.model + " " + QVariant(i.year).toString() + "  " + i.serial);
        }
        if (getall().size() == 0){
            list->append("Нет данных в БД");
        }
    }
}
