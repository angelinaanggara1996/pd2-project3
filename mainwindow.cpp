#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLCDNumber>
#include <QObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    score=0;
    L[0]=ui->label_2;
    //0]=ui->lcdNumber;
    time->start(100);
   //s[0]=ui->lcdNumber_2;
    //srand(time(null));
    for(int i=0; i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            b[i][j]=new Block(this,i,j);
            connect(b[i][j],SIGNAL(Click(int,int)),this,SLOT(button_clicked(int,int)));
        }
    }
    isClicked=false;
    GameStart();
    //L[0]->setText(score);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GameStart()
{
    isClicked=false;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            b[i][j]->setRandomNumber();
            b[i][j]->setButtonPicture();
            if(j>=2&&b[i][j]->number==b[i][j-1]->number && b[i][j]->number==b[i][j-2]->number)
            {
                j--;
            }
            if(i>=2&&b[i][j]->number==b[i-1][j]->number && b[i][j]->number==b[i-2][j]->number)
            {
                j--;
            }
        }
    }
}

void MainWindow::setClickedPicture(Block *a)
{
    if(!isClicked)
    {
        switch(a->number)
        {
        case 1:
            a->button->setIcon(QIcon(QPixmap(":/bg/red_clicked.png")));
            break;
        case 11:
            a->button->setIcon(QIcon(QPixmap(":/bg/red_vertical_bomb_clicked.png")));
            break;
        case 12:
            a->button->setIcon(QIcon(QPixmap(":/bg/red_horizontal_bomb_clicked.png")));
            break;
        case 13:
            a->button->setIcon(QIcon(QPixmap(":/bg/red_bomb_clicked.png")));
            break;
        case 2:
            a->button->setIcon(QIcon(QPixmap(":/bg/yellow_clicked.png")));
            break;
        case 21:
            a->button->setIcon(QIcon(QPixmap(":/bg/yellow_vertical_clicked.png")));
            break;
        case 22:
            a->button->setIcon(QIcon(QPixmap(":/bg/yellow_horizontal_bomb_clicked.png")));
            break;
        case 23:
            a->button->setIcon(QIcon(QPixmap(":/bg/yellow_bomb_clicked.png")));
            break;
        case 3:
            a->button->setIcon(QIcon(QPixmap(":/bg/green_clicked.png")));
            break;
        case 31:
            a->button->setIcon(QIcon(QPixmap(":/bg/green_vertical_bomb_clicked.png")));
            break;
        case 32:
            a->button->setIcon(QIcon(QPixmap(":/bg/green_horizontal_bomb_clicked.png")));
            break;
        case 33:
            a->button->setIcon(QIcon(QPixmap(":/bg/green_bomb_clicked.png")));
            break;
        case 4:
            a->button->setIcon(QIcon(QPixmap(":/bg/blue_clicked.png")));
            break;
        case 41:
            a->button->setIcon(QIcon(QPixmap(":/bg/blue_vertical_bomb_clicked.png")));
            break;
        case 42:
            a->button->setIcon(QIcon(QPixmap(":/bg/blue_horizontal_bomb_clicked.png")));
            break;
        case 43:
            a->button->setIcon(QIcon(QPixmap(":/bg/blue_bomb_clicked.png")));
            break;
        case 5:
            a->button->setIcon(QIcon(QPixmap(":/bg/power_bomb_clicked.png")));
            break;
        }
    }
    else{
        a->setButtonPicture();
    }
}

bool MainWindow::Judge(int row1, int col1, int row2, int col2)
{
    bool Done[12]={0};

    // check destroy 55
    if((b[row1][col1]->number==5)&&(b[row2][col2]->number==5)){
        destroy=new StarPlusStar;
        destroy->eliminate(b,b[row1][col1]);
        delete destroy;
        return true;
    }
    // end check destroy 55

    // check destroy star with candy
    if((b[row1][col1]->number==5)||(b[row2][col2]->number==5)){
        if(b[row1][col1]->number==5){
            destroy=new StarWithOthers;
            destroy->eliminate(b,b[row2][col2]);
            delete destroy;
            return true;
        }
        if(b[row2][col2]->number==5){
            destroy=new StarWithOthers;
            destroy->eliminate(b,b[row1][col1]);
            delete destroy;
            return true;
        }
    }// end check

    Done[0]=JudgeStar(row1,col1);
    Done[1]=JudgeStar(row2,col2);
    Done[2]=Judge9(row1,col1);
    Done[3]=Judge9(row2,col2);
    Done[4]=JudgeHor(row1,col1);
    Done[5]=JudgeHor(row2,col2);
    Done[6]=JudgeVer(row1,col1);
    Done[7]=JudgeVer(row2,col2);
    Done[8]=Judge3H(row1,col1);
    Done[9]=Judge3H(row2,col2);
    Done[10]=Judge3V(row1,col1);
    Done[11]=Judge3V(row2,col2);
    Check();
    RenewPicture();
    for(int i=0;i<12;i++){
        if(Done[i]==true)
            return true;
    }
    return false;
}

bool MainWindow::JudgeStar(int R, int C)
{
    int return_value;
    bool anySpam= false;
    destroy=new Star;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1:
            destroy->spam(b,b[R][C],1);
            anySpam=true;
            break;
        case 2:
            destroy->spam(b,b[R][C],2);
            anySpam=true;
            break;
        case 3:
            destroy->spam(b,b[R][C],3);
            anySpam=true;
            break;
        case 4:
            destroy->spam(b,b[R][C],4);
            anySpam=true;
            break;
        }
        delete destroy;
        if(anySpam==true)
        {
            score+=40000;
        }
        return anySpam;
    }
}

bool MainWindow::Judge9(int R, int C)
{
    int return_value;
    int anySpam=false;
    destroy=new NineBlock;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1:
            destroy->spam(b,b[R][C],1);
            anySpam=true;
            break;
        case 2:
            destroy->spam(b,b[R][C],2);
            anySpam=true;
            break;
        case 3:
            destroy->spam(b,b[R][C],3);
            anySpam=true;
            break;
        case 4:
            destroy->spam(b,b[R][C],4);
            anySpam=true;
            break;
        case 5:
            destroy->spam(b,b[R][C],5);
            anySpam=true;
            break;
        case 6:
            destroy->spam(b,b[R][C],6);
            anySpam=true;
            break;
        case 7:
            destroy->spam(b,b[R][C],7);
            anySpam=true;
            break;
        case 8:
            destroy->spam(b,b[R][C],8);
            anySpam=true;
            break;
        case 9:
            destroy->spam(b,b[R][C],9);
            anySpam=true;
            break;
        case 10:
            destroy->spam(b,b[R][C],10);
            anySpam=true;
            break;
        case 11:
            destroy->spam(b,b[R][C],11);
            anySpam=true;
            break;
        case 12:
            destroy->spam(b,b[R][C],12);
            anySpam=true;
            break;
        case 13:
            destroy->spam(b,b[R][C],13);
            anySpam=true;
            break;
        case 14:
            destroy->spam(b,b[R][C],14);
            anySpam=true;
            break;
        case 15:
            destroy->spam(b,b[R][C],15);
            anySpam=true;
            break;
        case 16:
            destroy->spam(b,b[R][C],16);
            anySpam=true;
            break;
        }
        delete destroy;
        if(anySpam==true)
        {
            score+=30000;
        }
        return anySpam;
    }
}

bool MainWindow::JudgeHor(int R, int C)
{
    int return_value;
    bool anySpam= false;
    destroy=new Horizontal;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1:
            destroy->spam(b,b[R][C],1);
            anySpam=true;
            break;
        case 2:
            destroy->spam(b,b[R][C],2);
            anySpam=true;
            break;
        case 3:
            destroy->spam(b,b[R][C],3);
            anySpam=true;
            break;
        case 4:
            destroy->spam(b,b[R][C],4);
            anySpam=true;
            break;
        }
        delete destroy;
        if(anySpam==true)
        {
            score+=20000;
        }
        return anySpam;
    }
}

bool MainWindow::JudgeVer(int R, int C)
{
    int return_value;
    bool anySpam= false;
    destroy=new Vertical;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1:
            destroy->spam(b,b[R][C],1);
            anySpam=true;
            break;
        case 2:
            destroy->spam(b,b[R][C],2);
            anySpam=true;
            break;
        case 3:
            destroy->spam(b,b[R][C],3);
            anySpam=true;
            break;
        case 4:
            destroy->spam(b,b[R][C],4);
            anySpam=true;
            break;
        }
        delete destroy;
        if(anySpam==true)
        {
            score+=20000;
        }
        return anySpam;
    }
}

bool MainWindow::Judge3H(int R, int C)
{
    int return_value;
    bool anySpam= false;
    destroy=new HorThreecandy;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1:
            destroy->spam(b,b[R][C],1);
            anySpam=true;
            break;
        case 2:
            destroy->spam(b,b[R][C],2);
            anySpam=true;
            break;
        case 3:
            destroy->spam(b,b[R][C],3);
            anySpam=true;
            break;
        case 4:
            destroy->spam(b,b[R][C],4);
            anySpam=true;
            break;
        case 5:
            destroy->spam(b,b[R][C],5);
            anySpam=true;
            break;
        case 6:
            destroy->spam(b,b[R][C],6);
            anySpam=true;
            break;
        }
        delete destroy;
        if(anySpam==true)
        {
            score+=10000;
        }
        return anySpam;
    }
}

bool MainWindow::Judge3V(int R, int C)
{
    int return_value;
    bool anySpam= false;
    destroy=new VerThreecandy;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1:
            destroy->spam(b,b[R][C],1);
            anySpam=true;
            break;
        case 2:
            destroy->spam(b,b[R][C],2);
            anySpam=true;
            break;
        case 3:
            destroy->spam(b,b[R][C],3);
            anySpam=true;
            break;
        case 4:
            destroy->spam(b,b[R][C],4);
            anySpam=true;
            break;
        case 5:
            destroy->spam(b,b[R][C],5);
            anySpam=true;
            break;
        case 6:
            destroy->spam(b,b[R][C],6);
            anySpam=true;
            break;
        }
        delete destroy;
        if(anySpam==true)
        {
            score+=10000;
        }
        return anySpam;
    }
}

void MainWindow::Check()
{
    for(int k=0;k<10;k++)
    {
        for(int i=0;i<10;i++)
        {
            if(b[k][i]->number==0)
            {
                for(int j=0;j<=k;j++)
                {
                    if((k-j-1)!=-1)
                        b[k-j][i]->number=b[k-j-1][i]->number;
                    else
                    {
                        b[k-j][i]->setRandomNumber();
                    }
                 }
            }
        }
    }
}

void MainWindow::RenewPicture()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            b[i][j]->setButtonPicture();
}

bool MainWindow::ClearPoss()
{
    bool HaveToClear=false;

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(HaveToClear=JudgeStar(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(HaveToClear=Judge9(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(HaveToClear=JudgeVer(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(HaveToClear=JudgeHor(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(HaveToClear=Judge3V(i,j))return true;
        }
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(HaveToClear=Judge3H(i,j))return true;
        }
    }

    return HaveToClear;
}

void MainWindow::button_clicked(int R, int C)
{
    if(!isClicked)//just clicked
    {
        setClickedPicture(b[R][C]);
        record_R=R;
        record_C=C;
        isClicked=true;
    }
    else{
        if(record_R==R && record_C==C-1)//change the icon to the left
        {
            *b[record_R][record_C]-b[R][C];
            if(!Judge(record_R,record_C,R,C))
            {

            }
        }
        else if(record_R==R && record_C==C+1)//to the right
        {
            *b[R][C]-b[record_R][record_C];
            if(!Judge(record_R,record_C,R,C))
            {

            }
        }
        else if(record_C==C && record_R==R-1)
        {
            *b[record_R][record_C]|b[R][C];
            if(!Judge(record_R,record_C,R,C))
            {

            }
        }
        else if(record_C==C && record_R==R+1)
        {
            *b[R][C]|b[record_R][record_C];
            if(!Judge(record_R,record_C,R,C))
            {

            }
        }
        else{
            setClickedPicture(b[record_R][record_C]);
        }
        isClicked=false;
    }
}

