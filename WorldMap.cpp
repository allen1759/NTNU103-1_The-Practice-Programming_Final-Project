#include "WorldMap.h"
#include <iostream>

void CWorldMap::AddMap(CMapUnit * mapPtr)
{
    units_.push_back( mapPtr );
}

void CWorldMap::GoTo_StartPoint(size_t num)
{
    units_[0]->arriveHere(num);
}

void CWorldMap::display() const
{
    for(size_t i=0,L1 = size()/2; i<L1; i+=1) {
        units_[i]->display(i);

        std::cout << "       ";
        units_[ size()-1-i ]->display( size()-1-i );
        std::cout <<std::endl;
    }
}
