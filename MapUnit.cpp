#include "MapUnit.h"

CMapUnit::CMapUnit(std::string name, MapType type, bool buy, size_t id, size_t numPlayer)
        : name_(name), type_(type), buyable_(buy), id_(id)
{
    for(size_t i=0; i<numPlayer; i+=1) {
        who_is_here_.push_back( false );
    }
}

inline MapType CMapUnit::getType() const
{
    return type_;
}

inline bool CMapUnit::isBuyable() const
{
    return buyable_;
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
