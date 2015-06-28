#ifndef VERTHREECANDY_H
#define VERTHREECANDY_H

#include "destroy.h"
#include "block.h"
#include "Star.h"
#include "Horizontal.h"
#include "Vertical.h"
#include "NineBlock.h"

class VerThreecandy:public Destroy
{
public:
    VerThreecandy();
    virtual int spam(Block * a[10][10],Block * focus,int mode);
    virtual void eliminate(Block * a[10][10],Block * focus);
    virtual int condition(Block *a[10][10], Block *focus);
    virtual ~VerThreecandy();
};

#endif // VERTHREECANDY_H
