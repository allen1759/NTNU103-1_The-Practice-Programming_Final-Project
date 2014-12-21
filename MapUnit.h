#ifndef MAPUNIT_H_INCLUDED
#define MAPUNIT_H_INCLUDED

#include <string>
#include <vector>
#include "Player.h"

class CMapUnit
{
public:
    CMapUnit(std::string name, size_t id, size_t fine, size_t numPlayer);

protected:
    std::string name_;
    size_t id_, travel_fine_;
    std::vector<bool> who_is_here_;
    // 有在這裡就是 true , 否則就是 false
private:
};

#endif // MAPUNIT_H_INCLUDED
