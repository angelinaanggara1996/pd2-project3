#include "horthreecandy.h"
#include <QDebug>
HorThreecandy::HorThreecandy()
{

}

HorThreecandy::~HorThreecandy()
{

}

int HorThreecandy::spam(Block *a[10][10], Block *focus, int mode)
{
    int R=focus->row;
    int C=focus->column;
    Destroy * d;
    int ThreeNum[3]={0};

    switch(mode)
    {
    case 1: // left
        focus->number=0;

        ThreeNum[0]=a[R][C]->number;
        if(a[R][C+1]->number/10!=0)ThreeNum[1]=a[R][C+1]->number%10;
        if(a[R][C+2]->number/10!=0)ThreeNum[2]=a[R][C+2]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                a[R][C+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R][C+i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C+i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C+i]);
                delete d;
                break;
            }
        }
        break;
    case 2: // middle normal component
        focus->number=0;

        if(a[R][C-1]->number/10!=0)ThreeNum[0]=a[R][C-1]->number%10;
        ThreeNum[1]=a[R][C]->number;
        if(a[R][C+1]->number/10!=0)ThreeNum[2]=a[R][C+1]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    case 3: // right normal component
        focus->number=0;

        if(a[R][C-2]->number/10!=0)ThreeNum[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0)ThreeNum[1]=a[R][C-1]->number%10;
        ThreeNum[2]=a[R][C]->number;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    case 4: // left normal component

        ThreeNum[0]=a[R][C]->number%10;
        if(a[R][C+1]->number/10!=0)ThreeNum[1]=a[R][C+1]->number%10;
        if(a[R][C+2]->number/10!=0)ThreeNum[2]=a[R][C+2]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                a[R][C+i]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R][C+i]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R][C+i]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R][C+i]);
                delete d;
                break;
            }
        }
        break;
    case 5: // middle normal component

        if(a[R][C-1]->number/10!=0)ThreeNum[0]=a[R][C-1]->number%10;
        ThreeNum[1]=a[R][C]->number%10;
        if(a[R][C+1]->number/10!=0)ThreeNum[2]=a[R][C+1]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    case 6: // right normal component

        if(a[R][C-2]->number/10!=0)ThreeNum[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0)ThreeNum[1]=a[R][C-1]->number%10;
        ThreeNum[2]=a[R][C]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    }
}

void HorThreecandy::eliminate(Block *a[10][10], Block *focus)
{
    int R=focus->row;
    focus->number=0;
    int ThreeNum[3]={0};
    Destroy *d;
    for(int i=0;i<10;i++)
        if(a[R][i]->number/10!=0)
            ThreeNum[i]=a[R][i]->number%10;
    for(int i=0;i<10;i++)
    {
        switch(ThreeNum[i])
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

int HorThreecandy::condition(Block *a[10][10], Block *focus)
{
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    if(num!=0&&num!=5)
    {
        if(num/10==0)
        { // control normal component
            // left
            if(C<=7&&((num==a[R][C+1]->number)||(num==a[R][C+1]->number/10))
                   &&((num==a[R][C+2]->number)||(num==a[R][C+2]->number/10))){
                return 1;
            }

            // middle
            if(C>=1&&C<=8&&((num==a[R][C-1]->number)||(num==a[R][C-1]->number/10))
                   &&((num==a[R][C+1]->number)||(num==a[R][C+1]->number/10))){
                return 2;
            }

            // right
            if(C>=2&&((num==a[R][C-2]->number)||(num==a[R][C-2]->number/10))
                   &&((num==a[R][C-1]->number)||(num==a[R][C-1]->number/10))){
                return 3;
            }
        }
        else if(num/10!=0)
        { // control special component
            num/=10;
            // left
            if(C<=7&&((num==a[R][C+1]->number)||(num==a[R][C+1]->number/10))
                   &&((num==a[R][C+2]->number)||(num==a[R][C+2]->number/10))){
                return 4;
            }

            // middle
            if(C>=1&&C<=8&&((num==a[R][C-1]->number)||(num==a[R][C-1]->number/10))
                   &&((num==a[R][C+1]->number)||(num==a[R][C+1]->number/10))){
                return 5;
            }

            // right
            if(C>=2&&((num==a[R][C-2]->number)||(num==a[R][C-2]->number/10))
                   &&((num==a[R][C-1]->number)||(num==a[R][C-1]->number/10))){
                return 6;
            }
        }
    }
    return 0;
}
