#include "WorldMap.h"
#include <iostream>

void CWorldMap::AddMap(CMapUnit * mapPtr)
{
    units_.push_back( mapPtr );
}

