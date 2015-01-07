#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "Game.h"
using namespace std;

size_t Number_We_want( const string S )
{
    stringstream ss;
    int num;
    ss << S;
    ss >> num;
    if( ! (num>=1 && num<=CWorldPlayer::max_num_player) ) {
        if(num > CWorldPlayer::max_num_player) num = CWorldPlayer::max_num_player;
        else num = 1;
    }
    return static_cast<size_t>(num);
}

int main()
{
    srand( time(NULL) );

    string input_;
    cout << "How many players?(Maximum:4)...>";
    getline(cin,input_);
    size_t num_Players = Number_We_want(input_);

    // create a new game
    CGame newGame("map.dat", num_Players);
    newGame.startGame();
    return 0;
}
