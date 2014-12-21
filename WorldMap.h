#ifndef WORLDMAP_H_INCLUDED
#define WORLDMAP_H_INCLUDED

#include "MapUnit.h"

class CWorldMap
{
public:
private:
    static constexpr size_t NumUnit = 20;
    CMapUnit *units_[NumUnit];
};
#endif // WORLDMAP_H_INCLUDED
