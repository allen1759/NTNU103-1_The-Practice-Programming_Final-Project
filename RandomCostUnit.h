#ifndef RANDOMCOSTUNIT_H_INCLUDED
#define RANDOMCOSTUNIT_H_INCLUDED

#include "MapUnit.h"

class CRandomCostUnit: public CMapUnit
{
public:
    CRandomCostUnit(const std::string &name, size_t id, size_t numPlayer,size_t price,size_t fine)
        : CMapUnit(name, true, id, numPlayer), price_(price), travel_fine_(fine)
    { }

    virtual size_t getPrice() const override;
    virtual size_t getFine(size_t dice) const override;
    virtual void display(size_t index) const override;

private:
    const size_t price_= 0;
    const size_t travel_fine_ = 0;
};

#endif // RANDOMCOSTUNIT_H_INCLUDED
