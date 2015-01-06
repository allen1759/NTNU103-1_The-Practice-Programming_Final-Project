#ifndef COLLECTABLEUNIT_H_INCLUDED
#define COLLECTABLEUNIT_H_INCLUDED

#include <stdio.h>
#include "MapUnit.h"

class CCollectableUnit: public CMapUnit
{
public:
    CCollectableUnit(const std::string &name, size_t id,size_t numPlayer,const size_t price)
        : CMapUnit(name, true, id, numPlayer), price_(price)
    { }

    virtual bool isCollectable() const override {return true;}
    virtual size_t getPrice() const override;
    virtual size_t getFine (size_t dice) const override;
    virtual void display(size_t index) const override;

private:
    const size_t price_ = 0;
    const size_t travel_fine_ = 0;
};

#endif // COLLECTABLEUNIT_H_INCLUDED
