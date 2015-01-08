#ifndef COLLECTABLEUNIT_H_INCLUDED
#define COLLECTABLEUNIT_H_INCLUDED

#include "MapUnit.h"

class CCollectableUnit: public CMapUnit
{
public:
    CCollectableUnit(const std::string &name, size_t id,size_t numPlayer, size_t price, size_t fine);

    virtual bool isCollectable() const override {return true;}
    virtual size_t getPrice() const override;
    virtual size_t getFine (const size_t dice) const override;
    virtual void display(const size_t index) const override;

private:
    const size_t price_ = 0;
    const size_t travel_fine_ = 0;
};

#endif // COLLECTABLEUNIT_H_INCLUDED
