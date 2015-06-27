#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "block.h"
#include <QMainWindow>
#include "Destroy.h"
#include "Star.h"
#include "Vertical.h"
#include "Horizontal.h"
#include "NineBlock.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void GameStart();
    void setClickedPicture(Block *b);
    bool Judge(int row1,int col1,int row2,int col2);
    bool JudgeStar(int R,int C);
    bool Judge9(int R,int C);
    bool JudgeHor(int R,int C);
    bool JudgeVer(int R,int C);
    void RenewPicture();
public slots:
    void button_clicked(int R, int C);

private:
    Block *b[10][10];
    Ui::MainWindow *ui;
    int record_R;
    int record_C;
    bool isClicked;
    Destroy *destroy;
};

#endif // MAINWINDOW_H
