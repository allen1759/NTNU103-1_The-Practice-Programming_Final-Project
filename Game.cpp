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
                CUpgradableUnit * mapPTr = new CUpgradableUnit(mapName, currentID++, numPlayer, price, upgr, fine);
                worldmap.AddMap(mapPTr);
            }
            break;

        case 'R': {
                string mapName;
                ss >> mapName;
                size_t price, fine;
                ss >> price >> fine;
                CRandomCostUnit * mapPtr = new CRandomCostUnit(mapName, currentID++, numPlayer, price, fine);
                worldmap.AddMap(mapPtr);
            }
            break;

        case 'C': {
                string mapName;
                ss >> mapName;
                size_t price, fine;
                ss >> price >> fine;
                CCollectableUnit * mapPtr = new CCollectableUnit(mapName, currentID++, numPlayer, price);
                worldmap.AddMap(mapPtr);
            }
            break;

        case 'J': {
                string mapName;
                ss >> mapName;
                CJailUnit * mapPtr = new CJailUnit(mapName, currentID++, numPlayer);
                worldmap.AddMap(mapPtr);
            }
            break;

        default:
            cout << "Unknown Case!!" << endl;
        }
    }

    inf.close();

    getchar(); //to eat the '\n'
    // initialize player part
    string playerName, default_name[4] = {"AllenYang", "HEDE0724", "CarolChen", "YuShan"};
    for(size_t i=0; i<numPlayer; i+=1) {
        cout << "Please input player " << i+1 << "'s name (Default: " << default_name[i] << " )...>";
        getline(cin, playerName);
        if(playerName == "") playerName = default_name[i];
        worldplayer.AddPlayer(i, playerName);
    }
    alivePlayer = numPlayer;
}

void CGame::startGame()
{
    system("cls");
    // alivePlayer == 0 遊戲結束
    while( alivePlayer != 0 ) {
        showEveryThing();

        if( worldplayer[currentID].isDead() );
        // Dead : do nothing
        else if( worldplayer[currentID].isStop() )
            worldplayer[currentID].Continue();
        // 暫停一輪
        else
            stepLoop();

        currentID += 1;

        currentID %= worldplayer.size();
    }
}

void CGame::stepLoop()
{
    dice_ = rand()%6 + 1;
    worldplayer[currentID].Move(dice_);
    size_t newPositoin = worldplayer[currentID].getLocation();

    CPlayer * hostPtr = worldmap[newPositoin]->getHost();
    // 別人的土地
    if( hostPtr != nullptr ) {
        int fine = worldmap[newPositoin]->getFine(dice_);
        if( fine > worldplayer[currentID].getMoney() ) {
            fine = worldplayer[currentID].getMoney();
            worldplayer[currentID].Dead();
            alivePlayer -= 1;
            // should release all the maps
            // hint : bankrupt funct
        }
        hostPtr->ModifyMoney( fine );
        worldplayer[currentID].ModifyMoney( 0-fine );
    }
    // 可以買的土地
    else if( worldmap[newPositoin]->isBuyable() ) {
        cout << " do u want to buy???" << endl;
        string option;
        getline(cin, option);
        if( option[0] != 'n' ) {
            worldplayer[currentID].ModifyMoney( worldmap[newPositoin]->getPrice() );
            worldmap[newPositoin]->setHost( &worldplayer[currentID] );
            worldmap[newPositoin]->setBuyable();
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
    showAllMap();
    cout << endl;
    worldplayer.PrintPlayers(currentID);
    cout << endl;
}

void CGame::showAllMap() const
{
    for(size_t i=0; i<worldmap.size(); i+=1) {
        worldmap[i]->display();
        cout << "       ";
        worldmap[ worldmap.size()-1-i ]->display();
        cout << endl;
    }
}
