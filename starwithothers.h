#ifndef STARWITHOTHERS_H
#define STARWITHOTHERS_H
#include "Destroy.h"
#include "block.h"
#include "Vertical.h"
#include "Horizontal.h"
#include "NineBlock.h"
class StarWithOthers: public Destroy
{
public:
    StarWithOthers();
    virtual int spam(Block * a[10][10],Block * focus,int mode);
    virtual void eliminate(Block * a[10][10],Block * focus);
    virtual int condition(Block *a[10][10], Block *focus);
    virtual ~StarWithOthers();
};

#endif // STARWITHOTHERS_H
