#ifndef UPGRADABLEUNIT_H_INCLUDED
#define UPGRADABLEUNIT_H_INCLUDED

#include <stdio.h>
#include <string>
#include <vector>
#include "MapUnit.h"

class CUpgradableUnit: public CMapUnit
{
public:
    CUpgradableUnit(const std::string & name, size_t id, size_t numPlayer,size_t price,size_t upgrade,const std::vector<size_t> & f1);
    size_t getPrice() const;
    virtual size_t getFine(size_t dice) const;
    size_t getUp_price() const;

    void NewHost(CPlayer *P1);
    void bankrupt();
    virtual void display(size_t index) const override {
        CMapUnit::display(index);
        if(buyable_) printf("   B");
        else printf("(%d)U",host_->getID());
    }

private:
    const size_t price_=0,upgrade_price=0;
    std::vector <size_t> travel_fine_;
    size_t level_ = 1;
};

#endif // UPGRADABLEUNIT_H_INCLUDED
