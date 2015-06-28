#include "Vertical.h"
#include <QDebug>
Vertical::Vertical()
{

}

Vertical::~Vertical()
{

}

int Vertical::condition(Block *a[10][10], Block *focus)
{
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    if(num!=0&&num!=5){
        if(num/10==0){ // control normal component
            // O
            // X
            // O
            // O condition
            if(R>=1&&R<=7&&((num==a[R-1][C]->number)||(num==a[R-1][C]->number/10))
                   &&((num==a[R+1][C]->number)||(num==a[R+1][C]->number/10))
                   &&((num==a[R+2][C]->number)||(num==a[R+2][C]->number/10))){
                return 1;
            }

            // O
            // O
            // X
            // O condition
            if(R>=2&&R<=8&&((num==a[R-2][C]->number)||(num==a[R-2][C]->number/10))
                   &&((num==a[R-1][C]->number)||(num==a[R-1][C]->number/10))
                   &&((num==a[R+1][C]->number)||(num==a[R+1][C]->number/10))){
                return 2;
            }
        }
        else if(num/10!=0){ // control special component
            num/=10;
            // O
            // X
            // O
            // O condition
            if(R>=1&&R<=7&&((num==a[R-1][C]->number)||(num==a[R-1][C]->number/10))
                   &&((num==a[R+1][C]->number)||(num==a[R+1][C]->number/10))
                   &&((num==a[R+2][C]->number)||(num==a[R+2][C]->number/10))){
                return 3;
            }

            // O
            // O
            // X
            // O condition
            if(R>=2&&R<=8&&((num==a[R-2][C]->number)||(num==a[R-2][C]->number/10))
                   &&((num==a[R-1][C]->number)||(num==a[R-1][C]->number/10))
                   &&((num==a[R+1][C]->number)||(num==a[R+1][C]->number/10))){
                return 4;
            }
        }
    }
    return 0;
}

int Vertical::spam(Block *a[10][10], Block *focus, int mode)
{
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    int FourNum[4]={0};
    Destroy * d;

    switch(mode){
    case 1: // O normal component
            // X
            // O
            // O

        focus->number=focus->number*10+1;

        if(a[R-1][C]->number/10!=0)FourNum[0]=a[R-1][C]->number%10;
        FourNum[1]=a[R][C]->number;
        if(a[R+1][C]->number/10!=0)FourNum[2]=a[R+1][C]->number%10;
        if(a[R+2][C]->number/10!=0)FourNum[3]=a[R+2][C]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                a[R-1+i][C]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            }
        }

        break;
    case 2: // O normal component
            // O
            // X
            // O

        focus->number=focus->number*10+1;

        if(a[R-2][C]->number/10!=0)FourNum[0]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0)FourNum[1]=a[R-1][C]->number%10;
        FourNum[2]=a[R][C]->number;
        if(a[R+1][C]->number/10!=0)FourNum[3]=a[R+1][C]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                a[R-2+i][C]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }

        break;
    case 3: // O special component
            // X
            // O
            // O

        if(a[R-1][C]->number/10!=0)FourNum[0]=a[R-1][C]->number%10;
        FourNum[1]=a[R][C]->number%10;
        if(a[R+1][C]->number/10!=0)FourNum[2]=a[R+1][C]->number%10;
        if(a[R+2][C]->number/10!=0)FourNum[3]=a[R+2][C]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                a[R-1+i][C]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            }
        }

        break;
    case 4: // O special component
            // O
            // X
            // O

        if(a[R-2][C]->number/10!=0)FourNum[0]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0)FourNum[1]=a[R-1][C]->number%10;
        FourNum[2]=a[R][C]->number%10;
        if(a[R+1][C]->number/10!=0)FourNum[3]=a[R+1][C]->number%10;

        for(int i=0;i<4;i++){
            switch(FourNum[i]){
            case 0:
                a[R-2+i][C]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }

        break;
    default:
        qDebug()<<"Spawn error";
    }
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
        default:
            qDebug()<<"failed";
        }
}

