#ifndef UPGRADABLEUNIT_H_INCLUDED
#define UPGRADABLEUNIT_H_INCLUDED

#include "MapUnit.h"

class CUpgradableUnit: public CMapUnit
{
public:
    CUpgradableUnit()
private:
    size_t price_=0, upgrade_price=0, level_=0, host_=0;
};

#endif // UPGRADABLEUNIT_H_INCLUDED
