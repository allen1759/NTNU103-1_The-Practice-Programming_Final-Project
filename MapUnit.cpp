#include "MapUnit.h"

CMapUnit::CMapUnit(std::string name, size_t id, size_t fine, size_t numPlayer)
        : name_(name), id_(id), travel_fine_(id)
{
    for(size_t i=0; i<numPlayer; i+=1) {
        who_is_here_.push_back( false );
    }
}

void CMapUnit::arriveHere(size_t player_id)
{
    who_is_here_[player_id] = true;
}

void CMapUnit::leaveHere(size_t player_id)
{
    who_is_here_[player_id] = false;
}
