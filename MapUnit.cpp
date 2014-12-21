#include "MapUnit.h"

CMapUnit::CMapUnit(std::string name, size_t id, size_t fine, size_t numPlayer)
        : name_(name), id_(id), travel_fine_(id)
{
    for(size_t i=0; i<numPlayer; i+=1) {
        who_is_here_.push_back( false );
    }
}
