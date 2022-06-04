#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QChartView>
#include <QLineSeries>
#include <QChart>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QBarSeries>
#include <QBarset>
#include <QMap>

#include "database.h"

class Graph: public QWidget
{
public:
    Graph(QWidget *parent = nullptr);
    QChart *chart;
    QChartView *chartView;
    QBarCategoryAxis *ax;
    QValueAxis *ay;
    QBarSeries *series;
    QBarSet *barset;
private slots:
    void Search();
};

#endif // GRAPH_H
