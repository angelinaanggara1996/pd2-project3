#include "Horizontal.h"

Horizontal::Horizontal()
{

}

Horizontal::~Horizontal()
{

}

int Horizontal::condition(Block *a[10][10], Block *focus)
{

}

int Horizontal::spam(Block *a[10][10], Block *focus, int mode)
{
    int R=focus->row;
    focus->number=0;
    int TenNum[10]={0};

}

void Horizontal::eliminate(Block *a[10][10], Block *focus)
{
    int R=focus->row;
    focus->number=0;
    int TenNum[10]={0};
    Destroy *d;
    for(int i=0;i<10;i++)
        if(a[R][i]->number/10!=0)
            TenNum[i]=a[R][i]->number%10;
    for(int i=0;i<10;i++)
        switch(TenNum[i])
        {
        case 0:
            a[R][i]->number=0;
            break;
        case 1:
            d=new Vertical;
            d->eliminate(a,a[R][i]);
            delete d;
            break;
                case 2:
                    d = new Horizontal;
                    d->eliminate(a,a[R][i]);
                    delete d;
                    break;
                case 3:
                    d = new NineBlock;
                    d->eliminate(a,a[R][i]);
                    delete d;
                    break;
                case 5:
                    break;
                }
}

