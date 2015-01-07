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
    void showEveryThing() const;
    bool AlreadyWin() const { return (alivePlayer==1); }

private:
    static constexpr size_t MaxLevel = 5;
    static constexpr size_t AwardMoney = 2000;
    size_t dice_;
    size_t currentPlayer = 0;
    size_t alivePlayer;
    CWorldMap worldmap;
    CWorldPlayer worldplayer;

    void SwichMap(const std::string & input, size_t numPlayer, size_t currentMap);
};

#endif // GAME_H_INCLUDED
