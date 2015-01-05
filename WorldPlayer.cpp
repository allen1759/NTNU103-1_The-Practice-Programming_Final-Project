#include <iostream>
#include "WorldPlayer.h"
#include "Player.h"

using namespace std;

void CWorldPlayer::AddPlayer(const size_t id,string name_)
{
    CPlayer tmp(id,name_);
    players[id] = tmp;
    num_of_player_++;
}

void CWorldPlayer::PrintPlayers()
{
    for(size_t i=0; i<num_of_player_; i++)
    {
        if(players[i].isDead() == false)
        {
            players[i].PrintPlayer();
        }
    }
}
