#ifndef MAPUNIT_H_INCLUDED
#define MAPUNIT_H_INCLUDED

#include <string>
#include <vector>
#include "Player.h"

class CMapUnit
{
public:
    CMapUnit(std::string name, bool buy, size_t id,size_t numPlayer);

    inline size_t getID() const { return id_; };
    inline CPlayer * const & getHost() const { return host_; }
    inline const std::string & getName() const { return name_; }

    //bool isMyMap(const CPlayer *host) const;
    //bool isHere(size_t player_id) const;
    bool isBuyable() const {return buyable_;}
    void arriveHere(size_t player_id);
    void leaveHere(size_t player_id);
    void setHost(CPlayer * playerPtr) { host_ = playerPtr; }
    void setBuyable() { buyable_ = !buyable_; }

    virtual bool isCollectable() const {return false;}
    virtual bool isUpgradable() const {return false;}
    virtual bool stopPlayer() const {return false;}
    virtual size_t getPrice() const {return 0;}
    virtual size_t getFine (size_t dice) const {return 0;}
    virtual size_t getUpgradeMoney() const {return 0;}

    virtual void display(size_t index) const;
    virtual void upgrade() {}
    virtual void releaseMap()
    {
        host_ = nullptr;
        buyable_ = true;
    }

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
