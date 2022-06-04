#ifndef MODELS_H
#define MODELS_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include "database.h"

class Models: public QWidget
{
public:
    Models(QWidget *parent = nullptr);
    QLineEdit * target;
    QTextEdit * list;
    QLabel *strip1;
private slots:
    void Search();
};


#endif // MODELS_H
