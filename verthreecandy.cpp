#include "verthreecandy.h"

VerThreecandy::VerThreecandy()
{

}

int VerThreecandy::spam(Block *a[10][10], Block *focus, int mode)
{
    int R=focus->row;
    int C=focus->column;
    Destroy * d;
    int ThreeNum[3]={0};

    switch(mode){
    case 1: // top normal component
        focus->number=0;

        ThreeNum[0]=a[R][C]->number;
        if(a[R+1][C]->number/10!=0)ThreeNum[1]=a[R+1][C]->number%10;
        if(a[R+2][C]->number/10!=0)ThreeNum[2]=a[R+2][C]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                a[R+i][C]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R+i][C]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R+i][C]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R+i][C]);
                delete d;
                break;
            }
        }

        break;
    case 2: // middle normal component
        focus->number=0;

        if(a[R-1][C]->number/10!=0)ThreeNum[0]=a[R-1][C]->number%10;
        ThreeNum[1]=a[R][C]->number;
        if(a[R+1][C]->number/10!=0)ThreeNum[2]=a[R+1][C]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    case 3: // down normal component
        focus->number=0;

        if(a[R-2][C]->number/10!=0)ThreeNum[0]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0)ThreeNum[1]=a[R-1][C]->number%10;
        ThreeNum[2]=a[R][C]->number;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    case 4: // top special component

        ThreeNum[0]=a[R][C]->number%10;
        if(a[R+1][C]->number/10!=0)ThreeNum[1]=a[R+1][C]->number%10;
        if(a[R+2][C]->number/10!=0)ThreeNum[2]=a[R+2][C]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
            case 0:
                a[R+i][C]->number=0;
                break;
            case 1:
                d=new Vertical;
                d->eliminate(a,a[R+i][C]);
                delete d;
                break;
            case 2:
                d=new Horizontal;
                d->eliminate(a,a[R+i][C]);
                delete d;
                break;
            case 3:
                d=new NineBlock;
                d->eliminate(a,a[R+i][C]);
                delete d;
                break;
            }
        }
        break;
    case 5: // middle special component
        if(a[R-1][C]->number/10!=0)ThreeNum[0]=a[R-1][C]->number%10;
        ThreeNum[1]=a[R][C]->number%10;
        if(a[R+1][C]->number/10!=0)ThreeNum[2]=a[R+1][C]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    case 6: // downest special component
        if(a[R-2][C]->number/10!=0)ThreeNum[0]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0)ThreeNum[1]=a[R-1][C]->number%10;
        ThreeNum[2]=a[R][C]->number%10;

        for(int i=0;i<=2;i++){
            switch(ThreeNum[i]){
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
    }
}

void VerThreecandy::eliminate(Block *a[10][10], Block *focus)
{

}

int VerThreecandy::condition(Block *a[10][10], Block *focus)
{
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    if(num!=0&&num!=5){
        if(num/10==0){ // control normal component
            // top condition
            if(R<=7&&((num==a[R+1][C]->number)||(num==a[R+1][C]->number/10))
                   &&((num==a[R+2][C]->number)||(num==a[R+2][C]->number/10))){
                return 1;
            }

            // middle condition
            if(R>=1&&R<=8&&((num==a[R-1][C]->number)||(num==a[R-1][C]->number/10))
                   &&((num==a[R+1][C]->number)||(num==a[R+1][C]->number/10))){
                return 2;
            }

            // down condition
            if(R>=2&&((num==a[R-2][C]->number)||(num==a[R-2][C]->number/10))
                   &&((num==a[R-1][C]->number)||(num==a[R-1][C]->number/10))){
                return 3;
            }
        }
        else if(num/10!=0){ // control special component
            num/=10;
            // top condition
            if(R<=7&&((num==a[R+1][C]->number)||(num==a[R+1][C]->number/10))
                   &&((num==a[R+2][C]->number)||(num==a[R+2][C]->number/10))){
                return 4;
            }

            // middle condition
            if(R>=1&&R<=8&&((num==a[R-1][C]->number)||(num==a[R-1][C]->number/10))
                   &&((num==a[R+1][C]->number)||(num==a[R+1][C]->number/10))){
                return 5;
            }

            // down condition
            if(R>=2&&((num==a[R-2][C]->number)||(num==a[R-2][C]->number/10))
                   &&((num==a[R-1][C]->number)||(num==a[R-1][C]->number/10))){
                return 6;
            }
        }
    }
    return 0;
}

VerThreecandy::~VerThreecandy()
{

}

