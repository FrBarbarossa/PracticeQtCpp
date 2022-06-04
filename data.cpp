#include "data.h"
#include <QGridLayout>
#include <QPushButton>


Queue::Queue(){first = new Node;
           cur = first;
           next = new Node;}
Queue::~Queue(){}

void Queue::add_elem(const QString &elem){
        cur->val = elem;
        cur->next = next;
        cur = next;
        next = new Node;
        next->next = nullptr;
    }

void Queue::delete_elem(){
        if (first->next != nullptr){
        tmp = first->next;
        free(first);
        first = tmp;}
    }

QString Queue::get_all(){
        tmp = first;
        QString out = "";
        while(tmp->next != nullptr){
            out = out + tmp->val + " ";
            tmp = tmp->next;
        }
        return out;
    }


Data::Data(QWidget *parent)
{
    QGridLayout * gridLayout = new QGridLayout();
    line = new QLineEdit();
    m_pSignalMapper = new QSignalMapper(this);
    QPushButton * button1 = new QPushButton("Добавить введённый элемент");
    QPushButton * button2 = new QPushButton("Удалить первый элемент очереди");
    text = new QTextEdit();
    QString strip("");
    Queue sample();

//    m_pSignalMapper = new QSignalMapper(this);

    gridLayout->addWidget(line);
    gridLayout->addWidget(button1);
    gridLayout->addWidget(button2);
    gridLayout->addWidget(text);

//    connect(button, SIGNAL(clicked()), m_pSignalMapper, SLOT(map()));
    connect(button1, SIGNAL(clicked()), m_pSignalMapper, SLOT(map()));
    m_pSignalMapper -> setMapping(button1, 1);
    connect(button2, SIGNAL(clicked()), m_pSignalMapper, SLOT(map()));
    m_pSignalMapper -> setMapping(button2, 2);

    // связываем сигнал из m_pSignalMapper о нажатии со слотом clicked
    // нашего класса
    connect(m_pSignalMapper, SIGNAL(mappedInt(int)),
           this, SLOT(clicked(int)));

//    connect(line , SIGNAL(textChanged(const QString &)), this, SLOT(edit(const QString &)));
    setLayout(gridLayout);
};


void Data::clicked(int id){
    switch (id) {
    case 1:{
        QString str = line->text();
        sample.add_elem(str);
        text->setText(sample.get_all());}
        break;
    case 2:
    {sample.delete_elem();
        text->setText(sample.get_all());}
        break;

    }
}

