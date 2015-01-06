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

        if( worldplayer[currentID].isDead() );
        // Dead : do nothing
        else if( worldplayer[currentID].isStop() )
            worldplayer[currentID].Continue();
        // 暫停一輪
        else {
            stepLoop();
        }
        currentID += 1;
        currentID %= worldplayer.size();
    }
}

void CGame::stepLoop()
{
    //離開本來的位置
    size_t oldPosition = worldplayer[currentID].getLocation();
    worldmap[oldPosition]->leaveHere(currentID);

    dice_ = rand()%6 + 1;
    worldplayer[currentID].Move(dice_);
    size_t newPositoin = worldplayer[currentID].getLocation();
    worldmap[newPositoin]->arriveHere(currentID);

    // the host of the Map where you are
    CPlayer * hostPtr = worldmap[newPositoin]->getHost();

    // 別人的土地 (should pay some money)
    if( hostPtr != nullptr && hostPtr != &worldplayer[currentID] ) {
        int fine = worldmap[newPositoin]->getFine(dice_);
        if( fine > worldplayer[currentID].getMoney() ) {
            fine = worldplayer[currentID].getMoney();
            worldplayer[currentID].Dead();
            alivePlayer -= 1;
            // should release all the maps which is hosted by currentID
            for(size_t i=0; i<worldmap.size(); i+=1) {
                if( worldmap[i]->getHost() == &worldplayer[currentID] ) {
                    worldmap[i]->releaseMap();
                }
            }
        }
        hostPtr->ModifyMoney( fine );
        worldplayer[currentID].ModifyMoney( 0-fine );
    }

    // 自己的土地 (you can upgrade your map)
    else if( hostPtr == &worldplayer[currentID] ) {
        if( !worldmap[newPositoin]->isUpgradable() ) return;

        // upgrade your house
        int upgradeMoney = worldmap[newPositoin]->getUpgradeMoney();
        cout << "u can upgrade it, cost " << upgradeMoney << " yes or no?";

        string option;
        getline(cin, option);
        if( option[0] != 'n' && option[0] != 'N' ) {
            if( worldplayer[currentID].getMoney() < upgradeMoney) {
                cout << "Sorry, you don't have enough money!  Q___Q" << endl;
                return;
            }
            worldplayer[currentID].ModifyMoney( 0-upgradeMoney );
            worldmap[newPositoin]->upgrade();
        }
    }

    // 沒有主人 可以買的土地
    else if( hostPtr==nullptr && worldmap[newPositoin]->isBuyable() ) {
        //cout << currentID << endl;
        cout << worldplayer[currentID].getName();
        cout <<  ", do you want to buy " << worldmap[newPositoin]->getName()  << "? ";
        cout << "(1: Yes [default] / 2: No)";

        string option;
        getline(cin, option);
        if( option[0] != 'n' && option[0] != 'N' ) {
            worldplayer[currentID].ModifyMoney( worldmap[newPositoin]->getPrice() );
            worldmap[newPositoin]->setHost( &worldplayer[currentID] );
            worldmap[newPositoin]->setBuyable();
            worldplayer[currentID].AddUnit();
            cout << "You pay $" << worldmap[newPositoin]->getPrice()
                 << " to buy " << worldmap[newPositoin]->getName() << endl ;
        }
    }

    // 監獄地 \AOA/\AOA/\AOA/
    else if( hostPtr==nullptr && worldmap[newPositoin]->isBuyable()==false) {
        worldplayer[currentID].Stop();
    }
}

void CGame::showResult() const
{
    //
}
void CGame::showEveryThing()
{
    worldmap.display();
    cout << endl;
    worldplayer.PrintPlayers(currentID);
    cout << endl;
}

