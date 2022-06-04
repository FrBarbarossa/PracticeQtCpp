#ifndef YEAR_H
#define YEAR_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include "database.h"

class Year: public QWidget
{
public:
    Year(QWidget *parent = nullptr);
    QLineEdit * target;
    QTextEdit * list;
    QLabel *strip1;
private slots:
    void Search();
};
#endif // YEAR_H
