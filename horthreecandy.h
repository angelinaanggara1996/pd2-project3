#ifndef HORTHREECANDY_H
#define HORTHREECANDY_H

#include "destroy.h"
#include "block.h"
#include "Star.h"
#include "NineBlock.h"
#include "Vertical.h"
#include "Horizontal.h"
class HorThreecandy: public Destroy
{
public:
    HorThreecandy();
    virtual int spam(Block *a[10][10],Block *focus,int mode);
    virtual void eliminate(Block * a[10][10],Block * focus);
    virtual int condition(Block *a[10][10], Block *focus);
    virtual ~HorThreecandy();
};

#endif // HORTHREECANDY_H
