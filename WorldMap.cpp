#include "WorldMap.h"
#include <iostream>

void CWorldMap::AddMap(CMapUnit * mapPtr)
{
    units_.push_back( mapPtr );
}

void CWorldMap::display() const
{
    for(size_t i=0,L1 = size(); i<L1; i+=1) {
        units_[i]->display();
        std::cout << "       ";
        units_[ size()-1-i ]->display();
        std::cout << std::endl;
    }
}
