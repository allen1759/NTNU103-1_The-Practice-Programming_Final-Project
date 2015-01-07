#ifndef UPGRADABLEUNIT_H_INCLUDED
#define UPGRADABLEUNIT_H_INCLUDED

#include <string>
#include <vector>
#include "MapUnit.h"

class CUpgradableUnit: public CMapUnit
{
public:
    CUpgradableUnit(const std::string & name, size_t id, size_t numPlayer,size_t price,size_t upgrade,const std::vector<size_t> & f1);

    virtual bool isUpgradable() const override;
    virtual size_t getPrice() const override;
    virtual size_t getFine(const size_t dice) const override;
    virtual size_t getUpgradeMoney() const override;
    virtual size_t getLevel() const override;

    virtual void display(const size_t index) const override;
    virtual void upgrade() override;

private:
    static constexpr size_t MaxLevel = 5;
    const size_t price_=0, upgrade_price=0;
    std::vector <size_t> travel_fine_;
    size_t level_ = 1;
    // initialize level to 1 at first
};

#endif // UPGRADABLEUNIT_H_INCLUDED
