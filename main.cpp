#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "MapUnit.h"
#include "JailUnit.h"
#include "CollectableUnit.h"
#include "RandomCostUnit.h"
#include "UpgradableUnit.h"
#include "Game.h"
using namespace std;

int main()
{
    srand( time(NULL) );
    // create a new game

    size_t num_Players;
    cout << "How many players?(Maximum:4)...>";
    cin >> num_Players;
    if(num_Players>4) num_Players = 4;
    else if(num_Players<=0) num_Players = 1;

    CGame newGame("map.dat", num_Players);
    newGame.startGame();

    return 0;
}
