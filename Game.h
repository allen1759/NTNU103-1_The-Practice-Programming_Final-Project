#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <string>
#include <stdlib.h>
#include "WorldMap.h"
#include "WorldPlayer.h"

class CGame
{
public:
    CGame(const std::string & fileName, size_t numPlayer);
    ~CGame() {}

    void startGame();
    void stepLoop();
    void showResult() const;
    // haven't finished
    void showAllMap() const;

private:
    const size_t MaxLevel = 5;
    size_t dice_;
    size_t currentID = 0;
    size_t alivePlayer;
    CWorldMap worldmap;
    CWorldPlayer worldplayer;
};

#endif // GAME_H_INCLUDED
