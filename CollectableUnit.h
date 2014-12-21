#ifndef COLLECTABLEUNIT_H_INCLUDED
#define COLLECTABLEUNIT_H_INCLUDED

#include "MapUnit.h"

class CCollectableUnit: public CMapUnit
{
public:
private:
    size_t host_=0, num_coll_unit_=0;
};

#endif // COLLECTABLEUNIT_H_INCLUDED
