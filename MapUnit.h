#ifndef MAPUNIT_H_INCLUDED
#define MAPUNIT_H_INCLUDED

#include <string>
#include <vector>
#include "Player.h"

class CMapUnit
{
public:
    static constexpr size_t nullHost = -1;

    CMapUnit() = default;
    CMapUnit(std::string name, bool buy, size_t id, size_t numPlayer);
    size_t getID() const;
    bool isHostRight(size_t) const;
    bool isBuyable() const;
    bool isHere(size_t player_id) const;
    void arriveHere(size_t player_id);
    void leaveHere(size_t player_id);

    virtual void display() const;

protected:
    std::string name_;
    bool buyable_;
    size_t id_;
    //size_t travel_fine_;
    // fine 放這裡不太好 因為jail不用罰金
    // 給繼承的map多一個 travel_fine_ 好了
    size_t host_ = nullHost;
    std::vector<bool> who_is_here_;
    // 有在這裡就是 true , 否則就是 false

private:
};

#endif // MAPUNIT_H_INCLUDED
