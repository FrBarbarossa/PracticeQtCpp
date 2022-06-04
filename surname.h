#ifndef SURNAME_H
#define SURNAME_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include "database.h"

class Surname: public QWidget
{
public:
    Surname(QWidget *parent = nullptr);
    QLineEdit * target;
    QTextEdit * list;
    QLabel *strip1;
private slots:
    void Search();
};

#endif // SURNAME_H
