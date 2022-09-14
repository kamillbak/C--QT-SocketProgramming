#ifndef CHARTSWINDOW_H
#define CHARTSWINDOW_H

#include <QDialog>

#include "data.h"
#include <QChart>
#include <QtCharts>
#include <QChartView>

namespace Ui {
class chartsWindow;
}

class chartsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit chartsWindow(QWidget *parent = nullptr);
    ~chartsWindow();

private slots:
    void on_showArr_clicked();

    void on_showChart_clicked();

private:
    Ui::chartsWindow *ui;

    Data * data_; // data object
};

#endif // CHARTSWINDOW_H
