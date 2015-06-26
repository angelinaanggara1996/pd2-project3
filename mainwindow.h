#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "block.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void button_clicked(int R, int C);

private:
    Block *b[10][10];
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
