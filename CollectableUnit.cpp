#include "CollectableUnit.h"
#include <iostream>
#include <iomanip>
using namespace std;

size_t CCollectableUnit::getPrice() const
{
    return price_;
}
size_t CCollectableUnit::getFine(size_t dice) const
{
    return host_->getcoll_unit_() * travel_fine_;
}

void CCollectableUnit::display(size_t index) const
{
    CMapUnit::display(index);
    if(buyable_) cout << "     B$" << setw(5) << price_;
    else cout << " (" << host_->getID() << ") x" << host_->getcoll_unit_();
}
