#ifndef ADD_H
#define ADD_H
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include "database.h"

class Add:public QWidget
{
    Q_OBJECT
public:
    Add(QWidget *parent = nullptr);
    QLineEdit *sur;
    QLineEdit *model;
    QLineEdit *year;
    QLineEdit *serial;
    QLabel *strip1;
    QLabel *strip2;
    QLabel *strip3;
    QLabel *strip4;
private slots:
    void Append();
};

#endif // ADD_H
