#ifndef JAILUNIT_H_INCLUDED
#define JAILUNIT_H_INCLUDED

#include "MapUnit.h"

class CJailUnit: public CMapUnit
{
public:
    CJailUnit(std::string name,size_t id):CMapUnit(name,id){}

    //void StopPlayer(CPlayer &player)const {player.Frozen();}
private:
};

#endif // JAILUNIT_H_INCLUDED
