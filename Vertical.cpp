#include "Vertical.h"

Vertical::Vertical()
{

}

Vertical::~Vertical()
{

}

int Vertical::condition(Block *a[10][10], Block *focus)
{

}

int Vertical::spam(Block *a[10][10], Block *focus, int mode)
{

}

void Vertical::eliminate(Block *a[10][10], Block *focus)
{
    int C=focus->column;
    focus->number=0;
    int TenNum[10]={0};
    Destroy *d;
    for(int i=0;i<10;i++)
        if(a[i][C]->number/10!=0)
            TenNum[i]=a[i][C]->number%10;
    for(int i=0;i<10;i++)
        switch(TenNum[i])
        {
        case 0:
            a[i][C]->number=0;
            break;
        case 1:
            d=new Vertical;
            d->eliminate(a,a[i][C]);
            delete d;
            break;
        case 2:
            d = new Horizontal;
            d->eliminate(a,a[i][C]);
            delete d;
            break;
        case 3:
            d = new NineBlock;
            d->eliminate(a,a[i][C]);
            delete d;
            break;
        case 5:
            break;
        }
}

