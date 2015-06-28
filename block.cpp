#include "block.h"
#include <QDebug>
#include <QTimer>
Block::Block(QWidget *parent, int R,int C):QObject(parent),row(R),column(C),shift(1)
{
    button=new QPushButton(parent);
    t=new QTimer();
    button->setGeometry(column *50,row *50,50,50);
    connect(button,SIGNAL(clicked()),this,SLOT(click()));
}

Block::~Block()
{
    delete button;
}

void Block::setButtonPicture()
{
    switch(number)
    {
    case 1:
        button->setIcon(QIcon(QPixmap(":/bg/red.png")));
        break;
    case 11:
        button->setIcon(QIcon(QPixmap(":/bg/red_vertical_bomb.png")));
        break;
    case 12:
        button->setIcon(QIcon(QPixmap(":/bg/red_horizontal_bomb.png")));
        break;
    case 13:
        button->setIcon(QIcon(QPixmap(":/bg/red_bomb.png")));
        break;
    case 2:
        button->setIcon(QIcon(QPixmap(":/bg/yellow.png")));
         break;
    case 21:
        button->setIcon(QIcon(QPixmap(":/bg/yellow_vertical_bomb.png")));
         break;
    case 22:
        button->setIcon(QIcon(QPixmap(":/bg/yellow_horizontal_bomb.png")));
         break;
    case 23:
        button->setIcon(QIcon(QPixmap(":/bg/yellow_bomb.png")));
         break;
    case 3:
        button->setIcon(QIcon(QPixmap(":/bg/green.png")));
         break;
    case 31:
        button->setIcon(QIcon(QPixmap(":/bg/green_vertical_bomb.png")));
         break;
    case 32:
        button->setIcon(QIcon(QPixmap(":/bg/green_horizontal_bomb.png")));
         break;
    case 33:
        button->setIcon(QIcon(QPixmap(":/bg/green_bomb.png")));
         break;
    case 4:
        button->setIcon(QIcon(QPixmap(":/bg/blue.png")));
         break;
    case 41:
        button->setIcon(QIcon(QPixmap(":/bg/blue_vertical_bomb.png")));
         break;
    case 42:
        button->setIcon(QIcon(QPixmap(":/bg/blue_horizontal_bomb.png")));
         break;
    case 43:
        button->setIcon(QIcon(QPixmap(":/bg/blue_bomb.png")));
         break;
    case 5:
        button->setIcon(QIcon(QPixmap(":/bg/power_bomb.png")));
         break;
    default:
        button->setIcon(QIcon(QPixmap("No Picture")));
    }
    return;
}

void Block::setRandomNumber()
{
    number=rand()%4+1;
    return;
}

void Block::operator-(Block *a)
{
    int tmp=a->number;
    a->number=number;
    number=tmp;
    setButtonPicture();
    a->setButtonPicture();
    //connect(t,SIGNAL(timeout()),this,SLOT(right()));
    //connect(a->t,SIGNAL(timeout()),a,SLOT(left()));
    t->start(100);
    a->t->start(100);
}

void Block::operator|(Block *a)
{
    int tmp=a->number;
    a->number=number;
    number=tmp;
    setButtonPicture();
    a->setButtonPicture();
    connect(t,SIGNAL(timeout()),this,SLOT(down()));
    connect(a->t,SIGNAL(timeout()),a,SLOT(up()));
    t->start(100);
    a->t->start(100);
}

void Block::click()
{
    emit Click(row,column);
}

void Block::right()
{
    button->setGeometry(column*50+shift*10,row*50,50,50);
        shift++;
        if(shift>5){
            shift=1;
            disconnect(t,SIGNAL(timeout()),this,SLOT(moveright()));
            button->setGeometry(column*50,row*50,50,50);
            setButtonPicture();
            emit Alter();
        }
        return;
}

void Block::left()
{
    button->setGeometry(column*50-shift*10,row*50,50,50);
        shift++;
        if(shift>5){
            shift=1;
            disconnect(t,SIGNAL(timeout()),this,SLOT(left()));
            button->setGeometry(column*50,row*50,50,50);
            setButtonPicture();
            emit Alter();
        }
        return;
}

void Block::down()
{
    button->setGeometry(column*50,row*50+shift*10,50,50);
        shift++;
        if(shift>5){
            shift=1;
            disconnect(t,SIGNAL(timeout()),this,SLOT(down()));
            button->setGeometry(column*50,row*50,50,50);
            setButtonPicture();
            emit Alter();
        }
        return;
}

void Block::up()
{
    button->setGeometry(column*50,row*50-shift*10,50,50);
        shift++;
        if(shift>5){
            shift=1;
            disconnect(t,SIGNAL(timeout()),this,SLOT(up()));
            button->setGeometry(column*50,row*50,50,50);
            setButtonPicture();
        }
        return;
}

