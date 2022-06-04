#include "database.h"

void addzap(Info info){
    QFile file("data.txt");
    file.open(QIODevice::Append);
    file.seek(file.size());
    QDataStream input(&file);
    input << info.surname << info.model<<info.year<<info.serial;
    file.close();
}

Info get(){
    Info info;
    QFile file("data.txt");
    file.open(QIODevice::ReadOnly);
    file.seek(0);
    QDataStream out(&file);
    out >> info.surname >> info.model >> info.year >> info.serial;
    file.close();
    return info;
}

QVector<Info> getall(){
    QVector<Info> out;
    QFile file("data.txt");
    file.open(QIODevice::ReadOnly);
    file.seek(0);
    QDataStream inp(&file);
    while (!inp.atEnd()){
        Info info;
        inp >> info.surname >> info.model >> info.year >> info.serial;
        out.push_back(info);
    }
    return out;
}

void dl(){
    QFile file("data.txt");
    file.resize(0);
    file.close();
}
