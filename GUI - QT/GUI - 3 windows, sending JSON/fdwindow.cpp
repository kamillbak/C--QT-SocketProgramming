#include "fdwindow.h"
#include "ui_fdwindow.h"

//using json = nlohmann::json;

FDwindow::FDwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FDwindow)
{
    ui->setupUi(this);
    this->setWindowTitle("FD");
}

FDwindow::~FDwindow()
{
    delete ui;
}



void FDwindow::on_sendV1_clicked()
{

//    // array to send
//    double arrDouble[] = {1.1, 1.2, 1.3, 1.4};

//    // Create JSON
//    json j = {
//    {"type", "arrayDouble"},
//    {"value", }
//    };

//    // add array to JSON
//    j["value"] = arrDouble;

//    // Parse JSON  string
//    std::string stringFromJson = j.dump();



////    int arrSize = sizeof(arrInt);

////    for( int i =0; i< arrSize; i++)
////    {

////    }

}

