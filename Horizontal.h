#ifndef HORIZONTAL_H
#define HORIZONTAL_H
#include "Destroy.h"
#include "Vertical.h"
#include "NineBlock.h"
class Horizontal:public Destroy
{
public:
    Horizontal();
    virtual ~Horizontal();
    virtual int condition(Block* a[10][10],Block *focus);
    virtual int spam(Block* a[10][10],Block *focus,int mode);
    virtual void eliminate(Block *a[10][10],Block *focus);
};

#endif // HORIZONTAL_H
