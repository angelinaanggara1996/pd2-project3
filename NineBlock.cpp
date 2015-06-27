#include "NineBlock.h"

NineBlock::NineBlock()
{

}

NineBlock::~NineBlock()
{

}

int NineBlock::condition(Block *a[10][10], Block *focus)
{
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    if(num!=0 && num!=5){
        if(num/10==0){
            //left up
            if(R>=2 && C>=2 && (num==a[R-2][C]->number||num==a[R-2][C]->number/10)
                            && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                            && (num==a[R][C-2]->number||num==a[R][C-2]->number/10)
                            && (num==a[R][C-1]->number||num==a[R][C-1]->number/10))
            {
                return 1;
            }
            //left down
            if(R>=2 && C<=7 && (num==a[R-2][C]->number||num==a[R-2][C]->number/10)
                            && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                            && (num==a[R][C+2]->number||num==a[R][C+2]->number/10)
                            && (num==a[R][C+1]->number||num==a[R][C+1]->number/10))
            {
                return 2;
            }
            //right up
            if(R<=7 && C>=2 && (num==a[R+2][C]->number||num==a[R+2][C]->number/10)
                            && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                            && (num==a[R][C-2]->number||num==a[R][C-2]->number/10)
                            && (num==a[R][C-1]->number||num==a[R][C-1]->number/10))
            {
                return 3;
            }
            //right down
            if(R<=7 && C<=7 && (num==a[R+2][C]->number||num==a[R+2][C]->number/10)
                            && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                            && (num==a[R][C+2]->number||num==a[R][C+2]->number/10)
                            && (num==a[R][C+1]->number||num==a[R][C+1]->number/10))
            {
                return 4;
            }
            //left T
            if(R>=1 && R<=8 && C>=2
                    &&(num==a[R][C-2]->number||a[R][C-2]->number/10)
                    &&(num==a[R][C-1]->number||a[R][C-1]->number/10)
                    &&(num==a[R-1][C]->number||a[R-1][C]->number/10)
                    &&(num==a[R+1][C]->number||a[R+1][C]->number/10))
                return 5;
            //right T
            if(C<=7 && R>=1 && R<=8
                    &&(num==a[R][C+1]->number||a[R][C+1]->number/10)
                    &&(num==a[R][C+2]->number||a[R][C+2]->number/10)
                    &&(num==a[R-1][C]->number||a[R-1][C]->number/10)
                    &&(num==a[R+1][C]->number||a[R+1][C]->number/10))
                return 6;
            //up T
            if(R>=2 && C<=8 && C>=1
                    &&(num==a[R][C+1]->number||a[R][C+1]->number/10)
                    &&(num==a[R][C-1]->number||a[R][C-1]->number/10)
                    &&(num==a[R-1][C]->number||a[R-1][C]->number/10)
                    &&(num==a[R-2][C]->number||a[R-2][C]->number/10))
                return 7;
            //down T
            if(R<=7 && C<=8 && C>=1
                    &&(num==a[R][C+1]->number||a[R][C+1]->number/10)
                    &&(num==a[R][C-1]->number||a[R][C-1]->number/10)
                    &&(num==a[R+1][C]->number||a[R+1][C]->number/10)
                    &&(num==a[R+2][C]->number||a[R+2][C]->number/10))
                return 8;
        }
        else if(num/10!=0)
        {
            num/=10;
            //left up
            if(R>=2 && C>=2 && (num==a[R-2][C]->number||num==a[R-2][C]->number/10)
                            && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                            && (num==a[R][C-2]->number||num==a[R][C-2]->number/10)
                            && (num==a[R][C-1]->number||num==a[R][C-1]->number/10))
            {
                return 9;
            }
            //left down
            if(R>=2 && C<=7 && (num==a[R-2][C]->number||num==a[R-2][C]->number/10)
                            && (num==a[R-1][C]->number||num==a[R-1][C]->number/10)
                            && (num==a[R][C+2]->number||num==a[R][C+2]->number/10)
                            && (num==a[R][C+1]->number||num==a[R][C+1]->number/10))
            {
                return 10;
            }
            //right up
            if(R<=7 && C>=2 && (num==a[R+2][C]->number||num==a[R+2][C]->number/10)
                            && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                            && (num==a[R][C-2]->number||num==a[R][C-2]->number/10)
                            && (num==a[R][C-1]->number||num==a[R][C-1]->number/10))
            {
                return 11;
            }
            //right down
            if(R<=7 && C<=7 && (num==a[R+2][C]->number||num==a[R+2][C]->number/10)
                            && (num==a[R+1][C]->number||num==a[R+1][C]->number/10)
                            && (num==a[R][C+2]->number||num==a[R][C+2]->number/10)
                            && (num==a[R][C+1]->number||num==a[R][C+1]->number/10))
            {
                return 12;
            }
            //left T
            if(R>=1 && R<=8 && C>=2
                    &&(num==a[R][C-2]->number||a[R][C-2]->number/10)
                    &&(num==a[R][C-1]->number||a[R][C-1]->number/10)
                    &&(num==a[R-1][C]->number||a[R-1][C]->number/10)
                    &&(num==a[R+1][C]->number||a[R+1][C]->number/10))
                return 13;
            //right T
            if(C<=7 && R>=1 && R<=8
                    &&(num==a[R][C+1]->number||a[R][C+1]->number/10)
                    &&(num==a[R][C+2]->number||a[R][C+2]->number/10)
                    &&(num==a[R-1][C]->number||a[R-1][C]->number/10)
                    &&(num==a[R+1][C]->number||a[R+1][C]->number/10))
                return 14;
            //up T
            if(R>=2 && C<=8 && C>=1
                    &&(num==a[R][C+1]->number||a[R][C+1]->number/10)
                    &&(num==a[R][C-1]->number||a[R][C-1]->number/10)
                    &&(num==a[R-1][C]->number||a[R-1][C]->number/10)
                    &&(num==a[R-2][C]->number||a[R-2][C]->number/10))
                return 15;
            //down T
            if(R<=7 && C<=8 && C>=1
                    &&(num==a[R][C+1]->number||a[R][C+1]->number/10)
                    &&(num==a[R][C-1]->number||a[R][C-1]->number/10)
                    &&(num==a[R+1][C]->number||a[R+1][C]->number/10)
                    &&(num==a[R+2][C]->number||a[R+2][C]->number/10))
                return 16;
        }
    }
    return 0;
}

int NineBlock::spam(Block *a[10][10], Block *focus, int mode)
{
    int R=focus->row;
    int C=focus->column;
    int num=focus->number;
    int FiveNum[5]={0};
    switch(mode)
    {
    //case 1to4 for Lstyle
    case 1:
        //left up
        focus->number=focus->number*10+3;
        //if(C<=8 && num==a[R][C+1]->number||num==a[R][C+1]->number/10) a[R][C+1]->number=0;
        //if(R<=8 && num==a[R+1][C]->number||num==a[R+1][C]->number/10) a[R+1][C]->number=0;
        if(C>=2 && num==a[R][C-1]->number||num==a[R][C-1]->number/10) a[R][C-1]->number=0;
        if(R>=2 && num==a[R-1][C]->number||num==a[R-1][C]->number/10) a[R-1][C]->number=0;
        if(a[R][C-2]->number/10!=0) FiveNum[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0) FiveNum[1]=a[R][C-1]->number%10;
        FiveNum[2]=a[R][C]->number;
        if(a[R-2][C]->number/10!=0) FiveNum[3]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0) FiveNum[4]=a[R-1][C]->number%10;
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:
                a[R][C-2+i]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R][C-2+i]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            }
        }
        //3&4 set the row
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i+3])
            {
            case 0:
                a[R-2+i][C]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R-2+i][C]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }
        break;
    case 2://??
        //left down
        focus->number=focus->number*10+3;
        if(C>=2 && num==a[R][C-1]->number||num==a[R][C-1]->number/10) a[R][C-1]->number=0;
        if(R<=8 && num==a[R+1][C]->number||num==a[R+1][C]->number/10) a[R+1][C]->number=0;
        if(a[R][C-2]->number/10!=0) FiveNum[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0) FiveNum[1]=a[R][C-1]->number%10;
        FiveNum[2]=a[R][C]->number;
        if(a[R-2][C]->number/10!=0) FiveNum[3]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0) FiveNum[4]=a[R-1][C]->number%10;
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:
                a[R][C-2+i]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R][C-2+i]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            }
        }
        //3&4 set the row
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i+3])
            {
            case 0:
                a[R-2+i][C]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R-2+i][C]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }
        break;
    case 3://??
        //right up
        focus->number=focus->number*10+3;
        if(C<=8 && num==a[R][C+1]->number||num==a[R][C+1]->number/10) a[R][C+1]->number=0;
        if(R>=2 && num==a[R-1][C]->number||num==a[R-1][C]->number/10) a[R-1][C]->number=0;
        if(a[R][C-2]->number/10!=0) FiveNum[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0) FiveNum[1]=a[R][C-1]->number%10;
        FiveNum[2]=a[R][C]->number;
        if(a[R-2][C]->number/10!=0) FiveNum[3]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0) FiveNum[4]=a[R-1][C]->number%10;
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:
                a[R][C-2+i]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R][C-2+i]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            }
        }
        //3&4 set the row
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i+3])
            {
            case 0:
                a[R-2+i][C]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R-2+i][C]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }
        break;
    case 4://??
        //right down
        focus->number=focus->number*10+3;
        if(C<=8 && num==a[R][C+1]->number||num==a[R][C+1]->number/10) a[R][C+1]->number=0;
        if(R<=8 && num==a[R+1][C]->number||num==a[R+1][C]->number/10) a[R+1][C]->number=0;
        if(a[R][C-2]->number/10!=0) FiveNum[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0) FiveNum[1]=a[R][C-1]->number%10;
        FiveNum[2]=a[R][C]->number;
        if(a[R-2][C]->number/10!=0) FiveNum[3]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0) FiveNum[4]=a[R-1][C]->number%10;
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:
                a[R][C-2+i]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R][C-2+i]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            }
        }
        //3&4 set the row
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i+3])
            {
            case 0:
                a[R-2+i][C]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R-2+i][C]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }
        //case5to8 for Tstyle
    case 5:
        //left T
        focus->number=focus->number*10+3;
        if(a[R][C-2]->number/10!=0) FiveNum[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0) FiveNum[1]=a[R][C-1]->number%10;
        FiveNum[2]=a[R][C]->number;
        if(a[R-2][C]->number/10!=0) FiveNum[3]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0) FiveNum[4]=a[R-1][C]->number%10;
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:
                a[R][C-2+i]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R][C-2+i]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            }
        }
        //3&4 set the row
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i+3])
            {
            case 0:
                a[R-2+i][C]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R-2+i][C]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }
        break;
    case 6:
        //right T
        focus->number=focus->number*10+3;
        if(a[R][C-2]->number/10!=0) FiveNum[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0) FiveNum[1]=a[R][C-1]->number%10;
        FiveNum[2]=a[R][C]->number;
        if(a[R-2][C]->number/10!=0) FiveNum[3]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0) FiveNum[4]=a[R-1][C]->number%10;
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:
                a[R][C-2+i]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R][C-2+i]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            }
        }
        //3&4 set the row
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i+3])
            {
            case 0:
                a[R-2+i][C]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R-2+i][C]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }
        break;
    case 7:
        //up T
        focus->number=focus->number*10+3;
        if(a[R][C-2]->number/10!=0) FiveNum[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0) FiveNum[1]=a[R][C-1]->number%10;
        FiveNum[2]=a[R][C]->number;
        if(a[R-2][C]->number/10!=0) FiveNum[3]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0) FiveNum[4]=a[R-1][C]->number%10;
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:
                a[R][C-2+i]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R][C-2+i]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            }
        }
        //3&4 set the row
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i+3])
            {
            case 0:
                a[R-2+i][C]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R-2+i][C]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }
        break;
    case 8:
        //down T
        focus->number=focus->number*10+3;
        if(a[R][C-2]->number/10!=0) FiveNum[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0) FiveNum[1]=a[R][C-1]->number%10;
        FiveNum[2]=a[R][C]->number;
        if(a[R-2][C]->number/10!=0) FiveNum[3]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0) FiveNum[4]=a[R-1][C]->number%10;
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:
                a[R][C-2+i]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R][C-2+i]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            }
        }
        //3&4 set the row
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i+3])
            {
            case 0:
                a[R-2+i][C]->number=0;
                break;
            case 1:
                 d = new Vertical;
                 d->eliminate(a,a[R-2+i][C]);
                 delete d;
                 break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }
    case 9:
        num/=10;
        if(a[R][C-2]->number/10!=0) FiveNum[0]=a[R][C-2]->number%10;
        if(a[R][C-1]->number/10!=0) FiveNum[1]=a[R][C-1]->number%10;
        FiveNum[2]=a[R][C]->number%10;
        if(a[R-2][C]->number/10!=0) FiveNum[3]=a[R-2][C]->number%10;
        if(a[R-1][C]->number/10!=0) FiveNum[4]=a[R-1][C]->number%10;
        break;
    }
}

void NineBlock::eliminate(Block *a[10][10], Block *focus)
{
    int R=focus->row;
    int C=focus->column;
    focus->number=0;
    int EightNum[8]={0};
    if(R>=1&&C>=1&&a[R-1][C-1]->number/10!=0)
        EightNum[0]=a[R-1][C-1]->number%10;
    if(R>=1 && a[R-1][C]->number/10!=0)
        EightNum[1]=a[R-1][C]->number%10;
    if(R>=1 && C<=8 && a[R-1][C+1]->number/10!=0)
        EightNum[2]=a[R-1][C+1]->number%10;
    if(C>=1&& a[R][C-1]->number/10!=0)
        EightNum[3]=a[R][C-1]->number%10;
    if(C<=8 && a[R][C+1]->number/10!=0)
        EightNum[4]=a[R][C+1]->number%10;
    if(R>=1 && C<=8 && a[R-1][C+1]->number/10!=0)
        EightNum[5]=a[R-1][C+1]->number%10;
    if(R<=8&&a[R+1][C]->number/10!=0)
        EightNum[6]=a[R+1][C]->number%10;
    if(R<=8 &&C<=8&& a[R+1][C+1]->number/10!=0)
        EightNum[7]=a[R+1][C+1]->number%10;
    if(R>=1 && C>=1)
    {
        Destroy *d;
    switch(EightNum[0]){
    case 0:
        a[R-1][C-1]->number=0;
        break;
    case 1:
        d=new Vertical;
        d->eliminate(a,a[R-1][C-1]);
        delete d;
        break;
    case 2:
        d = new Horizontal;
        d->eliminate(a,a[R-1][C-1]);
        delete d;
        break;
    case 3:
        d = new NineBlock;
        d->eliminate(a,a[R-1][C-1]);
        delete d;
        break;
    }
    }
    if(R>=1)
    {
         Destroy *d;
    switch(EightNum[1]){
    case 0:
        a[R-1][C]->number=0;
        break;
    case 1:
        d=new Vertical;
        d->eliminate(a,a[R-1][C]);
        delete d;
        break;
    case 2:
        d = new Horizontal;
        d->eliminate(a,a[R-1][C]);
        delete d;
        break;
    case 3:
        d = new NineBlock;
        d->eliminate(a,a[R-1][C]);
        delete d;
        break;
    }
    }
    if(R>=1 && C<=8)
    {
         Destroy *d;
    switch(EightNum[2]){
    case 0:
        a[R-1][C+1]->number=0;
        break;
    case 1:
        d=new Vertical;
        d->eliminate(a,a[R-1][C+1]);
        delete d;
        break;
    case 2:
        d = new Horizontal;
        d->eliminate(a,a[R-1][C+1]);
        delete d;
        break;
    case 3:
        d = new NineBlock;
        d->eliminate(a,a[R-1][C+1]);
        delete d;
        break;
    }
    }
    if(C>=1)
    {
         Destroy *d;
    switch(EightNum[3]){
    case 0:
        a[R][C-1]->number=0;
        break;
    case 1:
        d=new Vertical;
        d->eliminate(a,a[R][C-1]);
        delete d;
        break;
    case 2:
        d = new Horizontal;
        d->eliminate(a,a[R][C-1]);
        delete d;
        break;
    case 3:
        d = new NineBlock;
        d->eliminate(a,a[R][C-1]);
        delete d;
        break;
    }
    }
    if(C<=8)
    {
         Destroy *d;
    switch(EightNum[4]){
    case 0:
        a[R][C+1]->number=0;
        break;
    case 1:
        d=new Vertical;
        d->eliminate(a,a[R][C+1]);
        delete d;
        break;
    case 2:
        d = new Horizontal;
        d->eliminate(a,a[R][C+1]);
        delete d;
        break;
    case 3:
        d = new NineBlock;
        d->eliminate(a,a[R][C+1]);
        delete d;
        break;
    }
    }
    if(R>=1 && C<=8)
    {
         Destroy *d;
    switch(EightNum[5]){
    case 0:
        a[R-1][C+1]->number=0;
        break;
    case 1:
        d=new Vertical;
        d->eliminate(a,a[R-1][C+1]);
        delete d;
        break;
    case 2:
        d = new Horizontal;
        d->eliminate(a,a[R-1][C+1]);
        delete d;
        break;
    case 3:
        d = new NineBlock;
        d->eliminate(a,a[R-1][C+1]);
        delete d;
        break;
    }
    }
    if(R<=8)
    {
         Destroy *d;
    switch(EightNum[6]){
    case 0:
        a[R+1][C]->number=0;
        break;
    case 1:
        d=new Vertical;
        d->eliminate(a,a[R+1][C]);
        delete d;
        break;
    case 2:
        d = new Horizontal;
        d->eliminate(a,a[R+1][C]);
        delete d;
        break;
    case 3:
        d = new NineBlock;
        d->eliminate(a,a[R+1][C]);
        delete d;
        break;
    }
    }
    if(R<=8 && C<=8)
    {
         Destroy *d;
    switch(EightNum[7]){
    case 0:
        a[R+1][C+1]->number=0;
        break;
    case 1:
        d=new Vertical;
        d->eliminate(a,a[R+1][C+1]);
        delete d;
        break;
    case 2:
        d = new Horizontal;
        d->eliminate(a,a[R+1][C+1]);
        delete d;
        break;
    case 3:
        d = new NineBlock;
        d->eliminate(a,a[R+1][C+1]);
        delete d;
        break;
    }
    }
}

