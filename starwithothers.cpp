#include "starwithothers.h"
#include <QDebug>
StarWithOthers::StarWithOthers()
{

}

int StarWithOthers::spam(Block *a[10][10], Block *focus, int mode)
{

}

void StarWithOthers::eliminate(Block *a[10][10], Block *focus)
{
    int Breakcolor;
    int acpy[10][10];
    Destroy * d;

    if(focus->number!=0){

        if(focus->number/10==0)Breakcolor=focus->number;
        else{Breakcolor=focus->number/10;}

        // copy
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                acpy[i][j]=a[i][j]->number;
            }
        } // end copy

        // use copy to destroy
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(acpy[i][j]==Breakcolor){
                    a[i][j]->number=0;
                }
                else if((acpy[i][j]/10!=0)&&(acpy[i][j]/10==Breakcolor)){
                    switch (acpy[i][j]%10) {
                    case 1: // vertical bomb
                        d=new Vertical;
                        d->eliminate(a,a[i][j]);
                        delete d;
                        break;
                    case 2: // horizontal bomb
                        d=new Horizontal;
                        d->eliminate(a,a[i][j]);
                        delete d;
                        break;
                    case 3: // bomb
                        d=new NineBlock;
                        d->eliminate(a,a[i][j]);
                        delete d;
                        break;
                    default:
                        qDebug()<<"failed";
                    }
                }
            }
        } // end use copy
    }
}

int StarWithOthers::condition(Block *a[10][10], Block *focus)
{

}

StarWithOthers::~StarWithOthers()
{

}

