#ifndef MAPUNIT_H_INCLUDED
#define MAPUNIT_H_INCLUDED

#include <string>
#include <vector>

enum MapType
{
    UPGRA, COLLE, RANDOM, JAIL
};

class CMapUnit
{
public:
    CMapUnit(std::string name, MapType type, bool buy, size_t id, size_t numPlayer);
    MapType getType() const;
    bool isBuyable() const;
    bool isHere(size_t player_id) const;
    void arriveHere(size_t player_id);
    void leaveHere(size_t player_id);

protected:
    std::string name_;
    MapType type_;
    bool buyable_;
    size_t id_; //, travel_fine_;
    // fine 放這裡不太好 因為jail不用罰金
    // 給繼承的map多一個 travel_fine_ 好了
    std::vector<bool> who_is_here_;
    // 有在這裡就是 true , 否則就是 false

private:
};

#endif // MAPUNIT_H_INCLUDED
