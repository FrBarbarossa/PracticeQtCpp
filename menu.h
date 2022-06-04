#ifndef MENU_H
#define MENU_H
#include "data.h"
#include "add.h"
#include "del.h"
#include "year.h"
#include "surname.h"
#include "models.h"
#include "graph.h"
//#include "database.h"
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class Menu: public QWidget{
    Q_OBJECT
public:
    Menu(QWidget *parent = nullptr);
    Data *data;
    Add *add;
    Del *dlt;
    Year *yr;
    Surname *srn;
    Models *mod;
    Graph *gr;
//    Surname *year;
private slots:
    void SYear();
    void SSur();
    void SMod();
    void SAdd();
    void SDel();
    void SGraph();
};

#endif // MENU_H
