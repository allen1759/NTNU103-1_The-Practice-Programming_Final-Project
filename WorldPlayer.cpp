#include <iostream>
#include "WorldPlayer.h"
#include "Player.h"

using namespace std;

void CWorldPlayer::AddPlayer(const size_t id,string name_)
{
    player[id].AddPlayer(id,name_);
    num_of_player_++;
}

void CWorldPlayer::PrintPlayers()
{
    for(size_t i=0; i<num_of_player_; i++)
    {
        if(player[i].GetDead() == false)
        {
            player[i].PrintPlayer();
        }
    }
}
