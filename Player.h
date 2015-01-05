#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>

class CPlayer
{
public:
    CPlayer () = default;
    CPlayer (size_t id,std::string name) :id_(id),name_(name) {}
    void PrintPlayer();
    void Move(size_t dice);
    bool ModifyMoney(int m);
    // if dead return false
    void Dead() {dead_ = true;}
    void AddUnit();
    void AddCollUnit();
    void Continue();
    void Stop();

    size_t getID() const { return id_; }
    size_t getLocation()const { return location_; }
    int getMoney()const { return money_; };
    bool isDead()const { return dead_; }
    bool isStop()const { return stop_; }

    size_t getcoll_unit_() const {
        return num_coll_unit_;
    }

private:
    size_t id_ = 0, location_ = 0;
    int money_ = 30000;
    size_t num_unit_ = 0, num_coll_unit_ = 0;
    std::string name_;
    bool stop_ = false;  // in the jail or not
    bool dead_ = false;  // money < 0
};



#endif // PLAYER_H_INCLUDED
