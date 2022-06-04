#ifndef DEL_H
#define DEL_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include "database.h"

class Del: public QWidget
{
public:
    Del(QWidget *parent = nullptr);
    QLineEdit * target;
    QTextEdit * list;
    QLabel *strip1;
    void refresh();
private slots:
    void Dlt();
};


#endif // DEL_H
