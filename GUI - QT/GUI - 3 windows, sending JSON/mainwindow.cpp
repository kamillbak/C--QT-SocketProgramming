#include "mainwindow.h"
#include "ui_mainwindow.h"

using json = nlohmann::json;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this); // new socket
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    // (UP IF SINGAL "readyRead()" it means data are ready to read.. and
    // SLOT readyRead is active

    data_ = Data::getInstance();// using singleton to get data object
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Open FD window
void MainWindow::on_fdButton_clicked()
{
    fdWin = new FDwindow(this);
    fdWin->show();
}

// Open path window
void MainWindow::on_pathButton_clicked()
{
    pathWin = new pathWindow(this);
    pathWin->show();
}

// Open calc window
void MainWindow::on_calcButton_clicked()
{
    chartsWin = new chartsWindow(this);
    chartsWin->show();
}


void MainWindow::on_connectButton_clicked() // connecting
{
    ui->logsPTE->clear();
    QString textConnecting = "Connecting...";
    ui->logsPTE->appendPlainText(textConnecting);

    socket->connectToHost("127.0.0.1",8080);

    if(socket->waitForConnected(1000))
    {
        ui->logsPTE->appendPlainText("Connected to server 127.0.0.1, port 8080\n");
    }
    else
    {
        ui->logsPTE->appendPlainText("An attempt to connect to server failed.\n");
    }
}


void MainWindow::on_disconnectButton_clicked() //disconnecting
{
    if(socket->isOpen())
    {
        socket->close();
        ui->logsPTE->appendPlainText("Connection closed.\n");
    }
    else
    {
       ui->logsPTE->appendPlainText("No connection to close.\n");
    }
}

void MainWindow::readyRead() //if data ready to read
{
    socket->waitForReadyRead(200);

    QByteArray arrFromSocket = ""; // clear array

    arrFromSocket = socket->readAll();
    json obj = json::parse(arrFromSocket); // parse to JSON

    // BIG IF, whoch check what type of data are in JSON/////////////////////

    if(obj["flag"] == "NotOK")
    {
        ui->errorLabel->setText("Can't make operation");
    }
    else
    {
        ui->errorLabel->setText(" ");
        if(obj["type"] == "log")
        {
            //QString logMessage = (QString)obj["message"];
            QString logMessage =  QString::fromStdString(obj["message"]);
            ui->logsPTE->appendPlainText(logMessage);

           // socket->write("OK");
        }

        if(obj["type"] == "TwoArrays")
        {
            qDebug() << "Two arrays are here.";

            // Extract first array
            std::vector<double> vec1; //create vector
            obj["array1"].get_to(vec1); // array from JSOn -> vector
            double * pointer1 = &vec1[0]; // pointer to first element of vector

            double *arr1 = new double[vec1.size()];
            std::memcpy(arr1, pointer1, vec1.size()*sizeof(double));

            data_->setArr1Pointer(arr1);

            // Extract second array
            std::vector<double> vec2; //create vector
            obj["array2"].get_to(vec2); // array from JSOn -> vector
            double * pointer2 = &vec2[0]; // vector -> array

            double *arr2 = new double[vec2.size()];
            std::memcpy(arr2, pointer2, vec2.size()*sizeof(double));

            data_->setArr2Pointer(arr2);

            // sizes of Arrays
            int sizeArr1 = obj["size1"];
            int sizeArr2 = obj["size2"];

            // arr -> string
            std::string s1;
            std::string s2;

            // data ->
            double *arrT1 = data_->getArray1Pointer();

            double *arrT2 = data_->getArray2Pointer();


            for (int i = 0; i < sizeArr1; i++){
                s1 += std::to_string(arrT1[i]);
                s1 +=" " ;
            }

            for (int i = 0; i < sizeArr2; i++){
                s2 += std::to_string(arrT2[i]);
                s2 +=" " ;
            }

            // str -> Qstr
            QString s1_Q =  QString::fromStdString(s1);
            QString s2_Q =  QString::fromStdString(s2);


            // show str on label
            ui->vector1_label->setText(s1_Q);
            ui->vector2_label->setText(s2_Q);
        }

        // END OF BIG IF//////////////////////////////////////////////
    }
}




void MainWindow::on_sendV1_clicked()
{
    double arrDouble1[] = {1.1, 1.2, 1.3, 1.4, 2.7, 2.8};

    // Create JSON
    json j = {
    {"type", "arrayDouble1"},
    {"value", ""},
    {"size", 6 },
    };

    // add array to JSON
    j["value"] = arrDouble1;

    // JSON to string
    std::string stringFromJson = j.dump();
    //qDebug() << sizeof (stringFromJson);

    //from string to QByteArray
    QByteArray byteArrayFromJson = QByteArray::fromStdString(stringFromJson);

    // send json
    socket->write(byteArrayFromJson);
   // socket->waitForBytesWritten(500);
}



void MainWindow::on_sendV2_clicked()
{
    double arrDouble2[] = {10.1, 10.2, 10.3, 10.4};

    // Create JSON
    json j2 = {
    {"type", "arrayDouble2"},
    {"value", "" },
    {"size", 4 },
    };

    // add array to JSON
    j2["value"] = arrDouble2;

    // Parse JSON  string
    std::string stringFromJson = j2.dump();

    qDebug() << sizeof (stringFromJson);

    //from string to QByteArray
    QByteArray byteArrayFromJson = QByteArray::fromStdString(stringFromJson);

    // send json
    socket->write(byteArrayFromJson);
    socket->waitForBytesWritten(500);
}


void MainWindow::on_spinBox_v1_editingFinished()
{
    // Create JSON
    json j = {
    {"type", "addToV1"},
    {"vDouble",0 }
    };

    // value from spinBox to int
    double tmp = ui->spinBox_v1->value();

    //set value in JASON
    j["vDouble"] = tmp;

    // Parse JSON  string
    std::string stringFromJson = j.dump();

    //from string to QByteArray
    QByteArray byteArrayFromJson = QByteArray::fromStdString(stringFromJson);

    // write
    socket->write(byteArrayFromJson);
    socket->waitForBytesWritten(100);

    // reset value
    ui->spinBox_v1->setValue(0);
}

void MainWindow::on_spinBox_v2_editingFinished()
{
    // Create JSON
    json j = {
      {"type", "addToV2"},
      {"vDouble",0 }
    };

    // value from spinBox to int
    double tmp = ui->spinBox_v2->value();

    //set value in JASON
    j["vDouble"] = tmp;

    // Parse JSON  string
    std::string stringFromJson = j.dump();

    //from string to QByteArray
    QByteArray byteArrayFromJson = QByteArray::fromStdString(stringFromJson);

    // write
    socket->write(byteArrayFromJson);
    socket->waitForBytesWritten(100);

    // reset value
    ui->spinBox_v2->setValue(0);
}

