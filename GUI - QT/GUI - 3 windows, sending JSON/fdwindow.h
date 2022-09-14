#ifndef FDWINDOW_H
#define FDWINDOW_H

#include <QDialog>

// #include "json.hpp"

namespace Ui {
class FDwindow;
}

class FDwindow : public QDialog
{
    Q_OBJECT

public:
    explicit FDwindow(QWidget *parent = nullptr);
    ~FDwindow();

private slots:
    void on_sendV1_clicked();

private:
    Ui::FDwindow *ui;
};

#endif // FDWINDOW_H
