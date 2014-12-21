#ifndef MAPUNIT_H_INCLUDED
#define MAPUNIT_H_INCLUDED

#include <string>
#include <vector>
#include "Player.h"

class CMapUnit
{
public:
protected:
    std::string name_;
    size_t id_, travel_fine_;
    std::vector<CPlayer *> who_is_here_;
private:
};

#endif // MAPUNIT_H_INCLUDED
