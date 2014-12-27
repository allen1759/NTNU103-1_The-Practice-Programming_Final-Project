#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>



class CPlayer
{
public:
    CPlayer () {}
    CPlayer (size_t id) :id_(id) {}
    void AddPlayer(size_t id);
    void PrintPlayer();
    void Move(size_t dice);
    int ModifyMoney(int m);
    void AddUnit(); //call this in game
    void AddCollUnit();
    void Continue();
    void Stop();
    bool GetDead() { return dead_; }

    size_t coll_unit_() const {
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
