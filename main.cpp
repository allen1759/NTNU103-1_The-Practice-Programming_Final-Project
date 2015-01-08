#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
using namespace std;

int main()
{
    srand( time(NULL) );

    // default number of player : max number
    size_t numberOfPlayer = CWorldPlayer::max_num_player;
    string garbage;
    cout << "How many players?(Maximum:" << CWorldPlayer::max_num_player <<")...>";
    cin >> numberOfPlayer; getline(cin,garbage);
    if( numberOfPlayer <= 0) numberOfPlayer = 1;
    else if( numberOfPlayer > CWorldPlayer::max_num_player ) numberOfPlayer = CWorldPlayer::max_num_player;

    // create a new game
    CGame newGame("map.dat", numberOfPlayer);
    newGame.startGame();
    return 0;
}
