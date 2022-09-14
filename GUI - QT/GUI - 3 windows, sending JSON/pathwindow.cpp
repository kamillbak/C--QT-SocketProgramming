#include "pathwindow.h"
#include "ui_pathwindow.h"

pathWindow::pathWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pathWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Path");
}

pathWindow::~pathWindow()
{
    delete ui;
}
