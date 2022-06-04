#include "graph.h"

Graph::Graph(QWidget *parent): QWidget(parent)
{
    QGridLayout * gridLayout = new QGridLayout();
    this->setLayout(gridLayout);
    this->setWindowTitle("Гистограмма");
    this->setFixedSize(600,600);

    // Блок объявления кнопок


    chart  = new QChart();
    chartView = new QChartView(chart);
    barset = new QBarSet("Гистограмма: кол-во м/т от года выпуска");
    ax = new QBarCategoryAxis();
    ay = new QValueAxis();
    ax->setTitleText("Год выпуска");
    ay->setTitleText("Количество м/т");
    series = new QBarSeries();

    ax->clear();
    series->clear();

    QVector<QString> axx;
    QMap<QString, int> data;
    for (Info i: getall()){
        if (!axx.contains(QVariant(i.year).toString())){
        axx.push_back(QVariant(i.year).toString());}
        data[QVariant(i.year).toString()] += 1;
    }
    axx.sort();
    int max = 0;
    for (auto i: axx){
        ax->append(i);
        *barset << data[i];
        if (data[i] > max) {
            max = data[i];
        }
    }

    ay->setMax(max);
    ay->setLabelFormat("%d");
    ay->setTickCount(/*maxquant */max> 8 - 1 ?
                8 : (/*maxquant */max% 8) + 1);

    series->attachAxis(ax);
    series->attachAxis(ay);


    series->append(barset);

    chart->addAxis(ax,Qt::AlignBottom);
    chart->addAxis(ay,Qt::AlignLeft);
    chart->addSeries(series);

    // Блок связи кнопок и нажатий на них

    // Блок добавления кнопок в LayOut
    gridLayout->addWidget(chartView);
};


void Graph::Search(){

}
