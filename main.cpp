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

    // create a new game
    CGame newGame("map.dat", numberOfPlayer);
    newGame.startGame();
    return 0;
}
