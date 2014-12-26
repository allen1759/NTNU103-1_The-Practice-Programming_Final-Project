#include <iostream>
#include "WorldPlayer.h"
#include "Player.h"

using namespace std;

void CWorldPlayer::AddPlayer()
{
    cout << "How many players?(Maximum:" << max_num_player << ")";
    cin >> num_of_player_;
    if(num_of_player_ > max_num_player ) num_of_player_ = max_num_player;

    for(int i=0; i < num_of_player_; i++)
    {
        player[num_of_player_].AddPlayer(num_of_player_);
        num_of_player_++;
    }
}

void CWorldPlayer::PrintPlayers()
{
    for(int i=0; i<num_of_player_; i++)
    {
        if(player[i].GetDead() == false)
        {
            player[i].PrintPlayer();
        }
    }
}
