#ifndef MAPUNIT_H_INCLUDED
#define MAPUNIT_H_INCLUDED

#include <string>
#include <vector>
#include "Player.h"

class CMapUnit
{
public:
    CMapUnit(std::string name, bool buy, size_t id,size_t numPlayer);
    ~CMapUnit() {}

    inline size_t getID() const { return id_; };
    inline CPlayer * const & getHost() const { return host_; }
    inline const std::string & getName() const { return name_; }

    bool isBuyable() const {return buyable_;}
    void arriveHere(const size_t player_id);
    void leaveHere(size_t player_id);
    void setBuyable() { buyable_ = !buyable_; }
    void setHost(CPlayer * playerPtr) { host_ = playerPtr; }

    virtual bool isCollectable() const {return false;}
    virtual bool isUpgradable() const {return false;}
    virtual bool stopPlayer() const {return false;}
    virtual size_t getPrice() const {return 0;}
    virtual size_t getFine (const size_t dice) const {return 0;}
    virtual size_t getUpgradeMoney() const {return 0;}
    virtual size_t getLevel() const {return 0;}

    virtual void display(const size_t index) const;
    virtual void upgrade() {}
    virtual void releaseMap();

protected:
    std::string name_;
    bool buyable_;
    size_t id_;
    CPlayer * host_ = nullptr;

    std::vector<bool> who_is_here_;
    // 有在這裡就是 true , 否則就是 false
private:
};



#endif // MAPUNIT_H_INCLUDED
