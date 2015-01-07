#include "MapUnit.h"
#include <iostream>
#include <iomanip>

CMapUnit::CMapUnit (std::string name, bool buy, size_t id,size_t numPlayer)
    :   name_(name), buyable_(buy), id_(id)
{
    for(size_t i=0; i<numPlayer; i+=1) {
        who_is_here_.push_back( false );
    }
}

void CMapUnit::arriveHere(const size_t player_id)
{
    who_is_here_[player_id] = true;
}

void CMapUnit::leaveHere(size_t player_id)
{
    who_is_here_[player_id] = false;
}

void CMapUnit::display(const size_t index) const
{
    std::cout << "=";
    for(size_t i=0; i<who_is_here_.size(); i+=1)
    {
        if(who_is_here_[i]) std::cout << i;
        else std::cout << " ";
    }
    std::cout << "=  [" << std::setw(2) << id_ << "]";
    std::cout << std::setw(10) << name_;

}

void CMapUnit::releaseMap()
{
    host_ = nullptr;
    buyable_ = true;
}
