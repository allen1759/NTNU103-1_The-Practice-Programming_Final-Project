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

char S1[4][15] = { "A-Tu","Little-Mei","King-Baby","Mrs.Money" };
char names_[4][15];
int main()
{   // create a new game
    int Players;
    cout << "How many players?(Maximum:4)...>";
    cin >> Players;
    if(Players>4) Players = 4;
    else if(Players<=0) Players = 1;

    // player's name
    getchar();
    for( int i=0; i<Players; i++ ) {
        printf("Please input player %d's name (Default: %s)...>",i+1,S1[i]);
        if( !gets(names_[i]) || strcmp(names_[i],"")==0 ) strcpy ( names_[i],S1[i] );
    }

//    for( int i=0; i<Players; i++ ) {
//        printf("%s\n",names_[i]);
//    }
    return 0;
}
