#include "Game.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

CGame::CGame(const std::string & fileName, size_t numPlayer)
{
    // initialize map part
    fstream inf(fileName, std::ios::in);

    if(!inf) return;

    string input;
    size_t currentMap = 0;
    while( getline(inf, input) ) {
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
                CUpgradableUnit * mapPTr = new CUpgradableUnit(mapName, currentMap++, numPlayer, price, upgr, fine);
                worldmap.AddMap(mapPTr);
            }
            break;

        case 'R': {
                string mapName;
                ss >> mapName;
                size_t price, fine;
                ss >> price >> fine;
                CRandomCostUnit * mapPtr = new CRandomCostUnit(mapName, currentMap++, numPlayer, price, fine);
                worldmap.AddMap(mapPtr);
            }
            break;

        case 'C': {
                string mapName;
                ss >> mapName;
                size_t price, fine;
                ss >> price >> fine;
                CCollectableUnit * mapPtr = new CCollectableUnit(mapName, currentMap++, numPlayer, price);
                worldmap.AddMap(mapPtr);
            }
            break;

        case 'J': {
                string mapName;
                ss >> mapName;
                CJailUnit * mapPtr = new CJailUnit(mapName, currentMap++, numPlayer);
                worldmap.AddMap(mapPtr);
            }
            break;

        default:
            cout << "Unknown Case!!" << endl;
        }
    }
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
    alivePlayer = numPlayer;
}

void CGame::startGame()
{
    // alivePlayer == 1 遊戲結束
    while( alivePlayer != 1 ) {
        system("pause");
        system("cls");
        showEveryThing();

        if( worldplayer[currentPlayer].isDead() );
        // Dead : do nothing
        else if( worldplayer[currentPlayer].isStop() )
            worldplayer[currentPlayer].Continue();
        // 暫停一輪
        else {
            stepLoop();
        }
        currentPlayer += 1;
        currentPlayer %= worldplayer.size();
        while( worldplayer[currentPlayer].isDead() ) {
            currentPlayer += 1;
            currentPlayer %= worldplayer.size();
        }
    }
}

void CGame::stepLoop()
{
    //離開本來的位置
    size_t oldPosition = worldplayer[currentPlayer].getLocation();
    worldmap[oldPosition]->leaveHere(currentPlayer);

    dice_ = rand()%6 + 1;
    worldplayer[currentPlayer].Move(dice_, worldmap.size());
    size_t newPositoin = worldplayer[currentPlayer].getLocation();
    worldmap[newPositoin]->arriveHere(currentPlayer);

    // the host of the Map where you are
    CPlayer * hostPtr = worldmap[newPositoin]->getHost();

    // 沒有主人 可以買的土地
    if( worldmap[newPositoin]->isBuyable() ) {
        //cout << currentPlayer << endl;
        cout << worldplayer[currentPlayer].getName();
        cout <<  ", do you want to buy " << worldmap[newPositoin]->getName()  << "? ";
        cout << "(1: Yes [default] / 2: No)";

        string option;
        getline(cin, option);
        if( option[0] != 'n' && option[0] != 'N' ) {
            worldplayer[currentPlayer].ModifyMoney( worldmap[newPositoin]->getPrice() );
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
        int upgradeMoney = worldmap[newPositoin]->getUpgradeMoney();
        cout << "u can upgrade it, cost " << upgradeMoney << " yes or no?";

        string option;
        getline(cin, option);
        if( option[0] != 'n' && option[0] != 'N' ) {
            if( worldplayer[currentPlayer].getMoney() < upgradeMoney) {
                cout << "Sorry, you don't have enough money!  Q___Q" << endl;
                return;
            }
            worldplayer[currentPlayer].ModifyMoney( 0-upgradeMoney );
            worldmap[newPositoin]->upgrade();
        }
    }

    // 別人的土地 (should pay some money)
    else if( hostPtr != nullptr && hostPtr != &worldplayer[currentPlayer] ) {
        int fine = worldmap[newPositoin]->getFine(dice_);
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
        hostPtr->ModifyMoney( fine );
        worldplayer[currentPlayer].ModifyMoney( 0-fine );
    }


    // 監獄地 \AOA/\AOA/\AOA/
    else if( hostPtr==nullptr ) {
        worldplayer[currentPlayer].Stop();
    }
}

void CGame::showEveryThing() const
{
    worldmap.display();
    cout << endl;
    worldplayer.PrintPlayers(currentPlayer);
    cout << endl;
}

