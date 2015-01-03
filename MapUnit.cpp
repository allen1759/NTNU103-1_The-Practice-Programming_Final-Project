#include "MapUnit.h"
#include <iostream>

CMapUnit::CMapUnit (std::string name, bool buy, size_t id,size_t numPlayer)
:name_(name),buyable_(buy),id_(id)
{
    for(size_t i=0; i<numPlayer; i+=1) {
        who_is_here_.push_back( false );
    }
}

inline size_t CMapUnit::getID() const
{
    return id_;
}

inline bool CMapUnit::isHostRight(const CPlayer *host)const
{
    return (host == host_);
}

inline bool CMapUnit::isHere(size_t player_id) const
{
    return who_is_here_[player_id];
}

inline void CMapUnit::arriveHere(size_t player_id)
{
    who_is_here_[player_id] = true;
}

inline void CMapUnit::leaveHere(size_t player_id)
{
    who_is_here_[player_id] = false;
}


void CMapUnit::display() const
{
    std::cout << "=";
    for(size_t i=0; i<who_is_here_.size(); i+=1)
    {
        if(who_is_here_[i]) std::cout << i;
        else std::cout << " ";
    }
    std::cout << "=  [" << id_ << "]";
}
