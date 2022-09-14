#include "chartswindow.h"
#include "ui_chartswindow.h"

chartsWindow::chartsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chartsWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Charts");


    data_ = Data::getInstance();// using singleton data object

    // Chart creation -----------------------------------------------------------------------------------------

      // create series from data object
      double *arrT1 = data_->getArray1Pointer();
      double *arrT2 = data_->getArray2Pointer();

      QScatterSeries *series_1 = new QScatterSeries();
      QScatterSeries *series_2 = new QScatterSeries();

      double tmpMax = 0;

      for(int i=0; i<4; i++)
      {
          series_1->append(i,arrT1[i]); //add data to series
          if(arrT1[i] > tmpMax )
          {
              tmpMax = arrT1[i]; //looking for max value
          }
      }

      for(int i=0; i<4; i++)
      {
          series_2->append(i*2,arrT2[i]);//add data to series
          if(arrT2[i] > tmpMax )
          {
              tmpMax = arrT2[i]; //looking for max value
          }
      }

      QChart *chart = new QChart(); //
      chart->legend()->hide();
      chart->addSeries(series_1);
      chart->addSeries(series_2);
      chart->setTitle("Scatter Chart");

      chart->createDefaultAxes();
      chart->axes(Qt::Horizontal).back()->setRange(-1, 15);    
      // set range should be better, smth like next 5 value
      chart->axes(Qt::Vertical).back()->setRange(-1, tmpMax +5); // set range Y max value +5
      chart->axes(Qt::Horizontal).back()->setTitleText("axis x ");
      chart->axes(Qt::Vertical).back()->setTitleText("axis y ");


      chart->setDropShadowEnabled(false);

      QChartView *chartView = new QChartView(chart);
      chartView->setRenderHint(QPainter::Antialiasing);
      chartView->setParent(ui->horizontalFrame);      

}

chartsWindow::~chartsWindow()
{

    delete ui;
}

void chartsWindow::on_showArr_clicked() // display arrays in labels
{
    //ARRAYS

    double *arrT1 = data_->getArray1Pointer();

    double *arrT2 = data_->getArray2Pointer();

    std::string s1;
    std::string s2;

    for (int i = 0; i < 4; i++){
        s1 += std::to_string(arrT1[i]);
        s1 +=" " ;
    }

    for (int i = 0; i < 4; i++){
        s2 += std::to_string(arrT2[i]);
        s2 +=" " ;
    }

    //str -> Qstr
    QString s1_Q =  QString::fromStdString(s1);
    QString s2_Q =  QString::fromStdString(s2);

    // show str on label
    ui->arr1->setText(s1_Q);
    ui->arr2->setText(s2_Q);

    // free memory
    delete[] arrT1;
    delete[] arrT2;
}


void chartsWindow::on_showChart_clicked()
{
    ;
}

