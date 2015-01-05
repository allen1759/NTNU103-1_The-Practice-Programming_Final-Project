#ifndef RANDOMCOSTUNIT_H_INCLUDED
#define RANDOMCOSTUNIT_H_INCLUDED

#include <stdio.h>
#include "MapUnit.h"
#include "Player.h"

class CRandomCostUnit: public CMapUnit
{
public:
    CRandomCostUnit(const std::string &name, size_t id, size_t numPlayer,size_t price,size_t fine)
        :CMapUnit(name,true,id,numPlayer),price_(price),travel_fine_(fine) { }

    size_t getPrice() const;

    virtual size_t getFine(size_t dice) const;

    void NewHost(CPlayer *P1);
    void bankrupt();
    virtual void display(size_t index) const override {
        CMapUnit::display(index);
        if(buyable_) printf("     B$%5d",price_);
        else printf(" (%d) ?",host_->getID());
    }

private:
    size_t price_= 0;
    size_t travel_fine_ = 0;
};

#endif // RANDOMCOSTUNIT_H_INCLUDED
