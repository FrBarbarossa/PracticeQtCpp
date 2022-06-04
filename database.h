#ifndef DATABASE_H
#define DATABASE_H
#include <QFile>
#include <QString>
#include <QVector>


struct Info{
    QString surname{};
    QString model{};
    int year{};
    QString serial{};
};

void addzap(Info info);
Info get();
QVector<Info> getall();
void dl();

#endif // DATABASE_H
