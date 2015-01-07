#include "Game.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

CGame::CGame(const string & fileName, size_t numPlayer)
{
    // initialize map part
    fstream inf(fileName, ios::in);
    if(!inf) return;
    string input;
    size_t currentMap = 0;
    while( getline(inf, input) ) SwichMap(input, numPlayer, currentMap++);
    inf.close();

    // initialize player part
    string playerName, default_name[4] = {"AllenYang", "HEDE0724", "CarolChen", "YuShan"};
    for(size_t i=0; i<numPlayer; i+=1) {
        cout << "Please input player " << i+1 << "'s name (Default: " << default_name[i] << " )...>";
        getline(cin, playerName);
        if(playerName == "") playerName = default_name[i];
        worldplayer.AddPlayer(i, playerName);
        worldmap.GoTo_StartPoint(i);
    }

    worldplayer.GetNumOfPlayer(numPlayer);
    alivePlayer = numPlayer;
}

void CGame::SwichMap(const string & input, size_t numPlayer, size_t currentMap)
{
    stringstream ss(input);
    char type;
    ss >> type;
    switch (type)
    {
    case 'U': {
            string mapName;
            ss >> mapName;
            size_t price, upgr;
            vector<size_t> fine(MaxLevel);
            ss >> price >> upgr;
            for( auto &ele : fine ) ss >> ele;
            CUpgradableUnit * mapPTr = new CUpgradableUnit(mapName, currentMap, numPlayer, price, upgr, fine);
            worldmap.AddMap(mapPTr);
        }
        break;

    case 'R': {
            string mapName;
            ss >> mapName;
            size_t price, fine;
            ss >> price >> fine;
            CRandomCostUnit * mapPtr = new CRandomCostUnit(mapName, currentMap, numPlayer, price, fine);
            worldmap.AddMap(mapPtr);
        }
        break;

    case 'C': {
            string mapName;
            ss >> mapName;
            size_t price, fine;
            ss >> price >> fine;
            CCollectableUnit * mapPtr = new CCollectableUnit(mapName, currentMap, numPlayer, price, fine);
            worldmap.AddMap(mapPtr);
        }
        break;

    case 'J': {
            string mapName;
            ss >> mapName;
            CJailUnit * mapPtr = new CJailUnit(mapName, currentMap, numPlayer);
            worldmap.AddMap(mapPtr);
        }
        break;

    default:
        cout << "Unknown Case!!" << endl;
    }
}

void CGame::startGame()
{
    if(worldmap.size() == 0) {
        cout << "Start game failed, check that there is a \"map.dat\" file at the right place." << endl;
        return;
    }

    while( 1 ) {
        system("cls");
        showEveryThing();

        // move to next "alive" player
        while( worldplayer[currentPlayer].isDead() ) {
            currentPlayer += 1;
            currentPlayer %= worldplayer.size();
        }
        // pause one time
        if( worldplayer[currentPlayer].isStop() ){
            worldplayer[currentPlayer].Continue();
            cout << worldplayer[currentPlayer].getName() << ", you can't move" << endl;
        }
        else {
            cout << worldplayer[currentPlayer].getName() << ", your turn! GOGOGO? (1: Dice [default] / 2: Exit)";
            string option;
            getline(cin, option);
            if(option[0] != '2') stepLoop();
            else return;
        }

        currentPlayer += 1;
        currentPlayer %= worldplayer.size();

        system("pause");

        // alivePlayer == 1 遊戲結束
        if(AlreadyWin()) {
            cout << "The winner is determined!" << endl;
            system("pause");
            return;
        }
    }
}

void CGame::stepLoop()
{
    //離開本來的位置
    size_t oldPosition = worldplayer[currentPlayer].getLocation();
    worldmap[oldPosition]->leaveHere(currentPlayer);

    dice_ = rand()%6 + 1;

    //travel around the world!!
    if( worldplayer[currentPlayer].Move(dice_, worldmap.size()) ) {
        worldplayer[currentPlayer].EarnMoney( AwardMoney );
        cout << "Congratulations!!! You can get $" << AwardMoney
             << " because you travel all over the world!" << endl;
    }
    size_t newPositoin = worldplayer[currentPlayer].getLocation();
    worldmap[newPositoin]->arriveHere(currentPlayer);

    // the host of the Map where you are
    CPlayer * hostPtr = worldmap[newPositoin]->getHost();

    // 沒有主人 可以買的土地
    if( worldmap[newPositoin]->isBuyable() ) {
        cout << worldplayer[currentPlayer].getName();
        cout <<  ", do you want to buy " << worldmap[newPositoin]->getName()  << "? ";
        cout << "(1: Yes [default] / 2: No)";

        string option;
        getline(cin, option);
        if( ! ( option[0] == '2' && option.size()==1 ) ) {
            if( worldplayer[currentPlayer].getMoney() < worldmap[newPositoin]->getPrice() ) {
                cout << "Sorry, you don't have enough money!  Q___Q" << endl;
                return;
            }

            worldplayer[currentPlayer].PayMoney( worldmap[newPositoin]->getPrice() );
            worldmap[newPositoin]->setHost( &worldplayer[currentPlayer] );
            worldmap[newPositoin]->setBuyable();
            worldplayer[currentPlayer].AddUnit();
            if( worldmap[newPositoin]->isCollectable() )
                worldplayer[currentPlayer].AddCollUnit();
            cout << "You pay $" << worldmap[newPositoin]->getPrice()
                 << " to buy " << worldmap[newPositoin]->getName() << endl ;
        }
    }

    // 自己的土地 (you can upgrade your map)
    else if( hostPtr == &worldplayer[currentPlayer] ) {
        if( !worldmap[newPositoin]->isUpgradable() ) return;

        // upgrade your house
        cout << worldplayer[currentPlayer].getName() << ", do you want to upgrade "
             << worldmap[newPositoin]->getName() << "? (1: Yes [default] / 2: No)...>";

        string option;
        getline(cin, option);
        if( !( option[0] != '2' && option.size()==1 ) ) {
            int upgradeMoney = worldmap[newPositoin]->getUpgradeMoney();
            if( worldplayer[currentPlayer].getMoney() < upgradeMoney) {
                cout << "Sorry, you don't have enough money!  Q___Q" << endl;
                return;
            }
            worldplayer[currentPlayer].PayMoney( upgradeMoney );
            worldmap[newPositoin]->upgrade();
            cout << "You pay $" << upgradeMoney << " to upgrade "
                 << worldmap[newPositoin]->getName() << " to Lv."
                 << worldmap[newPositoin]->getLevel() << endl ;
        }
    }

    // 別人的土地 (should pay some money)
    else if( hostPtr != nullptr && hostPtr != &worldplayer[currentPlayer] ) {
        int fine = worldmap[newPositoin]->getFine(dice_);
        //會破產
        if( fine > worldplayer[currentPlayer].getMoney() ) {
            fine = worldplayer[currentPlayer].getMoney();
            worldplayer[currentPlayer].Dead();
            alivePlayer -= 1;
            // should release all the maps which is hosted by currentPlayer
            for(size_t i=0; i<worldmap.size(); i+=1) {
                if( worldmap[i]->getHost() == &worldplayer[currentPlayer] ) {
                    worldmap[i]->releaseMap();
                }
            }
        }
        hostPtr->EarnMoney( fine );
        worldplayer[currentPlayer].PayMoney( fine );
        cout << worldplayer[currentPlayer].getName() <<", you must pay $"
             << fine << " to Player " << hostPtr->getID()
             << " (" << hostPtr->getName() << ")" << endl;
    }

    // 監獄地 \AOA/\AOA/\AOA/
    else if( hostPtr==nullptr ) {
        worldplayer[currentPlayer].Stop();
        cout << "HaHaHa, you are in the jail now. Please take a break!" << endl;
    }
}

void CGame::showEveryThing() const
{
    worldmap.display();
    cout << endl;
    worldplayer.PrintPlayers(currentPlayer);
    cout << endl;
}


