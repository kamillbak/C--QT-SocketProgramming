#ifndef CHARTCLASS_H
#define CHARTCLASS_H

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>

QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class ChartClass; }
QT_END_NAMESPACE

class ChartClass : public QMainWindow
{
    Q_OBJECT

public:
    ChartClass(QWidget *parent = nullptr);
    ~ChartClass();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChartClass *ui;
};
#endif // CHARTCLASS_H
