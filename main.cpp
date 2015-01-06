#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
using namespace std;

int main()
{
    srand( time(NULL) );

    size_t num_Players;
    cout << "How many players?(Maximum:4)...>";
    cin >> num_Players;
    cin.get();    // eat the new line char
    if(num_Players > 4) num_Players = 4;
    else if(num_Players <= 0) num_Players = 1;

    // create a new game
    CGame newGame("map.dat", num_Players);
    newGame.startGame();

    return 0;
}
