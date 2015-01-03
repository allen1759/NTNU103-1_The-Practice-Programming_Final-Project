#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Player.h"
#include "MapUnit.h"
#include "JailUnit.h"
#include "CollectableUnit.h"
#include "RandomCostUnit.h"
#include "UpgradableUnit.h"
#include "Game.h"
using namespace std;

string S1[4] = { "A-Tu","Little-Mei","King-Baby","Mrs.Money" };

int main()
{   // create a new game
    CWorldPlayer Players;

    int num_Players;
    cout << "How many players?(Maximum:4)...>";
    cin >> num_Players;
    if(num_Players>4) num_Players = 4;
    else if(num_Players<=0) num_Players = 1;

    // player's name
    getchar();
    for( int i=0; i<num_Players; i++ ) {
        printf("Please input player %d's name (Default: %s)...>",i+1,S1[i].c_str());
        string name_;
        getline(cin,name_);
        if(name_=="") name_ = S1[i];

        Players.AddPlayer(i,name_);
    }



    return 0;
}
