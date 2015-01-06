#include "UpgradableUnit.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::setw;

CUpgradableUnit::CUpgradableUnit(const std::string & name, size_t id, size_t numPlayer,size_t price,size_t upgrade,const std::vector<size_t> & f1)
    : CMapUnit(name, true, id, numPlayer), price_(price), upgrade_price(upgrade)
{
    for(int i=0,L1 = f1.size();i<L1;i++) {
        travel_fine_.push_back(f1[i]);
    }
}

bool CUpgradableUnit::isUpgradable() const
{
    return level_ < MaxLevel;
}

size_t CUpgradableUnit::getPrice() const
{
    return price_;
}
size_t CUpgradableUnit::getFine(const size_t dice) const
{
    return travel_fine_[level_-1];
}
size_t CUpgradableUnit::getUpgradeMoney() const
{
    return upgrade_price;
}
size_t CUpgradableUnit::getLevel() const
{
    return level_;
}


void CUpgradableUnit::display(size_t index) const
{
    CMapUnit::display(index);
    if(buyable_) cout << "     B$" << setw(5) << price_ << "   ";
    else cout << " (" << host_->getID() << ") U$"
              << setw(5) << upgrade_price << " L" << level_;
}

void CUpgradableUnit::upgrade()
{
    level_ += 1;
}
