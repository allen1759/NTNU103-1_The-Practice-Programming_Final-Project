#ifndef COLLECTABLEUNIT_H_INCLUDED
#define COLLECTABLEUNIT_H_INCLUDED

#include <stdio.h>
#include "MapUnit.h"

class CCollectableUnit: public CMapUnit
{
public:
    CCollectableUnit(const std::string &name, size_t id,size_t numPlayer,const size_t price)
    :CMapUnit(name,true,id,numPlayer),price_(price)
    { }
    virtual size_t getPrice() const override {return price_;}
    virtual size_t getFine(size_t dice) const override;

    //void NewHost(CPlayer *P1);

    virtual void display(size_t index) const override {
        CMapUnit::display(index);
        if(buyable_) printf("     B$%5d",price_);
        else printf(" (%d) x%d",host_->getID(),host_->getcoll_unit_());
    }

private:
    const size_t price_=0, travel_fine_ =0;
};

#endif // COLLECTABLEUNIT_H_INCLUDED
