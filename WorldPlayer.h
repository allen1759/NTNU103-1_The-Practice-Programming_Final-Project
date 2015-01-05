#ifndef WORLDPLAYER_H_INCLUDED
#define WORLDPLAYER_H_INCLUDED

#include "Player.h"

class CWorldPlayer
{
public:
    size_t GetMaxNum()
    {
        return max_num_player;
    }
    void AddPlayer(const size_t id,std::string name_);
    void PrintPlayers(size_t current_id);
    CPlayer & operator [] (size_t ind) {return players[ind];}
    const CPlayer & operator [] (size_t ind) const {return players[ind];}
    size_t size() const { return num_of_player_;}

private:
    size_t num_of_player_ = 0;
    static constexpr size_t max_num_player = 4;
    CPlayer players[max_num_player];
};

#endif // WORLDPLAYER_H_INCLUDED
