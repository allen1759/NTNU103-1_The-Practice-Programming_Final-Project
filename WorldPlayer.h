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
    void AddPlayer();
    void PrintPlayers();
private:
    size_t num_of_player_ = 0;
    static constexpr size_t max_num_player = 4;
    CPlayer player[max_num_player];
};

#endif // WORLDPLAYER_H_INCLUDED
