#ifndef MAPUNIT_H_INCLUDED
#define MAPUNIT_H_INCLUDED

#include <string>
#include <vector>
#include "Player.h"

class CMapUnit
{
public:
    CMapUnit(std::string name, bool buy, size_t id,size_t numPlayer);

    size_t getID() const;
    bool isHostRight(const CPlayer *host) const;
    bool isBuyable() const;
    bool isHere(size_t player_id) const;
    void arriveHere(size_t player_id);
    void leaveHere(size_t player_id);

    virtual void display() const;
    virtual size_t getFine(const size_t dice) const = 0;
    virtual bool stopPlayer() const {return false;}

protected:
    std::string name_;
    bool buyable_;
    size_t id_;
    CPlayer* host_ = nullptr;

    std::vector<bool> who_is_here_;
    // 有在這裡就是 true , 否則就是 false
private:
};

#endif // MAPUNIT_H_INCLUDED
