#include "Horizontal.h"
#include <QDebug>
Horizontal::Horizontal()
{

}

Horizontal::~Horizontal()
{

}

int Horizontal::condition(Block *a[10][10], Block *focus)
{
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    if(num!=0&&num!=5){
        if(num/10==0){ // control normal component
            // OXOO condition
            if(C>=1&&C<=7&&((num==a[R][C-1]->number)||(num==a[R][C-1]->number/10))
                   &&((num==a[R][C+1]->number)||(num==a[R][C+1]->number/10))
                   &&((num==a[R][C+2]->number)||(num==a[R][C+2]->number/10))){
            return 1;
            }

            // OOXO condition
            if(C>=2&&C<=8&&((num==a[R][C-2]->number)||(num==a[R][C-2]->number/10))
                   &&((num==a[R][C-1]->number)||(num==a[R][C-1]->number/10))
                   &&((num==a[R][C+1]->number)||(num==a[R][C+1]->number/10))){
                return 2;
            }
        }
        else if(num/10!=0){ // control special component
            num/=10;//take the last digit
            // OXOO condition
            if(C>=1&&C<=7&&((num==a[R][C-1]->number)||(num==a[R][C-1]->number/10))
                   &&((num==a[R][C+1]->number)||(num==a[R][C+1]->number/10))
                   &&((num==a[R][C+2]->number)||(num==a[R][C+2]->number/10))){
                return 3;
            }

            // OOXO condition
            if(C>=2&&C<=8&&((num==a[R][C-2]->number)||(num==a[R][C-2]->number/10))
                   &&((num==a[R][C-1]->number)||(num==a[R][C-1]->number/10))
                   &&((num==a[R][C+1]->number)||(num==a[R][C+1]->number/10))){
                return 4;
            }
        }
    }
    return 0;
}

int Horizontal::spam(Block *a[10][10], Block *focus, int mode)
{
    int R=focus->row;
    int C=focus->column;
    int FourNum[4]={0};
    Destroy * d;

    switch(mode){
    case 1:// OXOO
        focus->number=focus->number*10+2;

        if(a[R][C-1]->number/10!=0)FourNum[0]=a[R][C-1]->number%10;
        FourNum[1]=a[R][C]->number;
        if(a[R][C+1]->number/10!=0)FourNum[2]=a[R][C+1]->number%10;
        if(a[R][C+2]->number/10!=0)FourNum[3]=a[R][C+2]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                a[R][C-1+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R][C-1+i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C-1+i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C-1+i]);
                delete d;
                break;
            }
        }

        break;
    case 2:// OOXO
        focus->number=focus->number*10+2;

        if(a[R][C-2]->number/10!=0)FourNum[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0)FourNum[1]=a[R][C-1]->number%10;
        FourNum[2]=a[R][C]->number;
        if(a[R][C+1]->number/10!=0)FourNum[3]=a[R][C+1]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                a[R][C-2+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            }
        }

        break;
    case 3:// OXOO diff

        if(a[R][C-1]->number/10!=0)FourNum[0]=a[R][C-1]->number%10;
        FourNum[1]=a[R][C]->number%10;
        if(a[R][C+1]->number/10!=0)FourNum[2]=a[R][C+1]->number%10;
        if(a[R][C+2]->number/10!=0)FourNum[3]=a[R][C+2]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                a[R][C-1+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R][C-1+i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C-1+i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C-1+i]);
                delete d;
                break;
            }
        }

        break;
    case 4:// OOXO

        if(a[R][C-2]->number/10!=0)FourNum[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0)FourNum[1]=a[R][C-1]->number%10;
        FourNum[2]=a[R][C]->number%10;
        if(a[R][C+1]->number/10!=0)FourNum[3]=a[R][C+1]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                a[R][C-2+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            }
        }

        break;
    default:
        qDebug()<<"Spawn error";
    }
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
    {
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
        default:
            qDebug()<<"failed";
        }
    }
}
