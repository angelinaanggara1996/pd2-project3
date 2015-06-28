#include "starplusstar.h"
#include <QDebug>
StarPlusStar::StarPlusStar()
{

}

int StarPlusStar::spam(Block *a[10][10], Block *focus, int mode)
{

}

void StarPlusStar::eliminate(Block *a[10][10], Block *focus)
{
    for(int i=0;i<10;i++){
        qDebug()<<"in";
        for(int j=0;j<10;j++){
           a[i][j]->number=0;
        }
    }
}

int StarPlusStar::condition(Block *a[10][10], Block *focus)
{

}

StarPlusStar::~StarPlusStar()
{

}

