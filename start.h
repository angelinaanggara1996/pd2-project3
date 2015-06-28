#ifndef START_H
#define START_H
#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class start;
}

class start : public QWidget
{
    Q_OBJECT

public:
    explicit start(QWidget *parent = 0);
    ~start();

private slots:
    void on_pushButton_clicked();

private:
    MainWindow *mw;
    Ui::start *ui;
};

#endif // START_H
