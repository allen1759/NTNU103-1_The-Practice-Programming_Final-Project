#include "MapUnit.h"

CMapUnit::CMapUnit(std::string name, size_t id, size_t numPlayer)
        : name_(name), id_(id)
{
    for(size_t i=0; i<numPlayer; i+=1) {
        who_is_here_.push_back( false );
    }
}

inline void CMapUnit::arriveHere(size_t player_id)
{
    who_is_here_[player_id] = true;
}

inline void CMapUnit::leaveHere(size_t player_id)
{
    who_is_here_[player_id] = false;
}
