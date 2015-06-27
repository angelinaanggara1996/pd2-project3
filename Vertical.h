#ifndef VERTICAL_H
#define VERTICAL_H
#include "Destroy.h"
#include "Horizontal.h"
#include "NineBlock.h"

class Vertical:public Destroy
{
public:
    Vertical();
    virtual ~Vertical();
    virtual int condition(Block* a[10][10],Block *focus);
    virtual int spam(Block* a[10][10],Block *focus,int mode);
    virtual void eliminate(Block *a[10][10],Block *focus);
};

#endif // VERTICAL_H
