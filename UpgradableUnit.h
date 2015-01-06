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
    size_t getUp_price() const;

    //void NewHost(CPlayer *P1);


    virtual size_t getFine(size_t dice) const;
    virtual void display(size_t index) const override
    {
        CMapUnit::display(index);
        if(buyable_) printf("     B$%5d",price_);
        else printf(" (%d) U$%5d",host_->getID(),upgrade_price);
    }
    virtual bool isUpgradable() const override
    {
        return level_ < MaxLevel;
    }
    virtual size_t getUpgradeMoney() const override
    {
        return upgrade_price;
    }
    virtual void upgrade() override
    {
        level_ += 1;
    }

private:
    static constexpr size_t MaxLevel = 5;
    const size_t price_=0, upgrade_price=0;
    std::vector <size_t> travel_fine_;
    size_t level_ = 1;
};

#endif // UPGRADABLEUNIT_H_INCLUDED
