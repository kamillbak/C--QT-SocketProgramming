#ifndef PATHWINDOW_H
#define PATHWINDOW_H

#include <QDialog>

namespace Ui {
class pathWindow;
}

class pathWindow : public QDialog
{
    Q_OBJECT

public:
    explicit pathWindow(QWidget *parent = nullptr);
    ~pathWindow();

private:
    Ui::pathWindow *ui;
};

#endif // PATHWINDOW_H
