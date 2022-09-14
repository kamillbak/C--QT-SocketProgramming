#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fdwindow.h"
#include "pathwindow.h"
#include "chartswindow.h"

#include "data.h"

#include <QTcpSocket>
#include <QDebug>
#include <QAbstractSocket>

#include "json.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void readyRead(); // Read data from socket

    // Open new windows
    void on_fdButton_clicked();

    void on_pathButton_clicked();

    void on_calcButton_clicked();

    // Slots from main Window
    void on_connectButton_clicked();

    void on_disconnectButton_clicked();

    void on_sendV1_clicked();

    void on_sendV2_clicked();

    void on_spinBox_v1_editingFinished();

    void on_spinBox_v2_editingFinished();

private:
    Ui::MainWindow *ui;

    FDwindow *fdWin;

    pathWindow *pathWin;

    chartsWindow * chartsWin;

    QTcpSocket *socket; //socket

    Data *data_; //Data object
};
#endif // MAINWINDOW_H
