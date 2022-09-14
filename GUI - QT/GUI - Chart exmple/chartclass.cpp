#include "chartclass.h"
#include "ui_chartclass.h"

#include <QChart>



ChartClass::ChartClass(QWidget *parent) //window class Constructor
    : QMainWindow(parent)
    , ui(new Ui::ChartClass)
{
    ui->setupUi(this);

    //create data series
    QScatterSeries *series0 = new QScatterSeries();
    series0->setName("Scatter 0");
    // series0->setColor("EC0B0B"); //red

    QScatterSeries *series1 = new QScatterSeries();
    series1->setName("Scatter 1");
    //series1->setColor("028904"); //dark green

    //Add data to series, method I
    series0->append(0,0);
    series0->append(1,1);
    series0->append(2,2);
    series0->append(3,3);
    series0->append(4,4);

    //Add data to series, method II
    *series1 << QPointF(0, 2) << QPointF(1, 1) << QPointF(2, 0) << QPointF(3, 1)
             << QPointF(4, 2);

    // Create chart object
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series0);
    chart->addSeries(series1);
    chart->setTitle("Scatter Chart");

    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).back()->setRange(-1, 5);
    chart->axes(Qt::Vertical).back()->setRange(-1, 5);
    chart->axes(Qt::Horizontal).back()->setTitleText("axis x ");
    chart->axes(Qt::Vertical).back()->setTitleText("axis y ");

    chart->setDropShadowEnabled(false);

    //Create chartView object
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame);
    chartView->resize(400,300);
}

ChartClass::~ChartClass()
{
    delete ui;
}


void ChartClass::on_pushButton_clicked()
{
    ;
}

