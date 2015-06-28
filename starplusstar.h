#ifndef STARPLUSSTAR_H
#define STARPLUSSTAR_H

#include "destroy.h"
#include "block.h"

class StarPlusStar:public Destroy
{
public:
    StarPlusStar();
    virtual int spam(Block * a[10][10],Block * focus,int mode);
    virtual void eliminate(Block * a[10][10],Block * focus);
    virtual int condition(Block *a[10][10], Block *focus);
    virtual ~StarPlusStar();
};

#endif // STARPLUSSTAR_H
