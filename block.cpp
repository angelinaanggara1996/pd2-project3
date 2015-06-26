#include "block.h"

Block::Block(QWidget *parent, int R,int C):QObject(parent),row(R),column(C)
{
    button=new QPushButton(parent);
    button->setGeometry(column *50,row *50,50,50);
    connect(button,SIGNAL(clicked()),parent,SLOT(click()));
}

Block::~Block()
{

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
        button->setIcon(QIcon(QPixmap(":/bg/.png")));
         break;
    }
}

void Block::setRandomNumber()
{
    number=rand()%4+1;
    return;
}

void Block::click()
{
    emit Click(row,column);
}

