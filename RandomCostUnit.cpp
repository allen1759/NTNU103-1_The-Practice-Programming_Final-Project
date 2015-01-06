#include "RandomCostUnit.h"
#include <iostream>
#include <iomanip>
using namespace std;

size_t CRandomCostUnit::getPrice() const
{
    return price_;
}

size_t CRandomCostUnit::getFine(size_t dice) const
{
    return dice * ( travel_fine_ );
}

void CRandomCostUnit::display(size_t index) const
{
    CMapUnit::display(index);
    if(buyable_) cout << "     B$" << setw(5) << price_ <<"   ";
    else cout << " (" << host_->getID() << ") ?        ";
}
