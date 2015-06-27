#ifndef NINEBLOCK_H
#define NINEBLOCK_H
#include "Destroy.h"
#include "Vertical.h"
#include "Horizontal.h"

class NineBlock:public Destroy
{
public:
    NineBlock();
    virtual ~NineBlock();
    virtual int condition(Block* a[10][10],Block *focus);
    virtual int spam(Block* a[10][10],Block *focus,int mode);
    virtual void eliminate(Block *a[10][10],Block *focus);
};

#endif // NINEBLOCK_H
