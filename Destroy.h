#ifndef DESTROY_H
#define DESTROY_H
#include "block.h"

class Destroy
{
public:
    Destroy();
    virtual ~Destroy();
    virtual int condition(Block* a[10][10],Block *focus)=0;
    virtual int spam(Block* a[10][10],Block *focus,int mode)=0;
    virtual void eliminate(Block *a[10][10],Block *focus)=0;
};

#endif // DESTROY_H
