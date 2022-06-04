#include <menu.h>

Menu::Menu(QWidget *parent): QWidget(parent)
{
//    this->setFixedSize(400,400);
    QGridLayout * gridLayout = new QGridLayout();
    this->setLayout(gridLayout);
    this->setWindowTitle("Меню");

    // Блок объявления кнопок
    QPushButton * add = new QPushButton("Добавить мотоцикл в базу");
    QPushButton * year = new QPushButton("Поиск по году выпуска");
    QPushButton * surname = new QPushButton("Поиск по фамилии владельца");
    QPushButton * model = new QPushButton("Поиск по модели мотоцикла");
    QPushButton * graph = new QPushButton("Инфографика");
    QPushButton * del = new QPushButton("Удаление информации");

    // Блок связи кнопок и нажатий на них
    connect(add, SIGNAL(clicked()), this, SLOT(SAdd()));
    connect(year, SIGNAL(clicked()), this, SLOT(SYear()));
    connect(surname, SIGNAL(clicked()), this, SLOT(SSur()));
    connect(model, SIGNAL(clicked()), this, SLOT(SMod()));
    connect(graph, SIGNAL(clicked()), this, SLOT(SGraph()));
    connect(del, SIGNAL(clicked()), this, SLOT(SDel()));

    // Блок добавления кнопок в LayOut
    gridLayout->addWidget(add);
    gridLayout->addWidget(del);
    gridLayout->addWidget(year);
    gridLayout->addWidget(surname);
    gridLayout->addWidget(model);
    gridLayout->addWidget(graph);



};

void Menu::SYear(){
    yr = new Year();
    yr->show();
}

void Menu::SAdd(){
    add = new Add();
    add->show();
}

void Menu::SSur(){
    srn = new Surname();
    srn->show();
}

void Menu::SMod(){
    mod = new Models();
    mod->show();
}

void Menu::SGraph(){
    gr = new Graph();
    gr->show();
}

void Menu::SDel(){
    dlt =  new Del();
    dlt->show();
}
