#ifndef STAR_H
#define STAR_H
#include "Destroy.h"
#include "Horizontal.h"
#include "Vertical.h"
#include "NineBlock.h"
class Star:public Destroy
{
public:
    Star();
    virtual ~Star();
    virtual int condition(Block* a[10][10],Block *focus);
    virtual int spam(Block* a[10][10],Block *focus,int mode);
    virtual void eliminate(Block *a[10][10],Block *focus);
};

#endif // STAR_H
