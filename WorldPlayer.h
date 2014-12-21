#ifndef WORLDPLAYER_H_INCLUDED
#define WORLDPLAYER_H_INCLUDED

#include "Player.h"

class CWorldPlayer
{
public:
private:
    static constexpr size_t NumPlayer = 4;
    CPlayer player[NumPlayer];
};

#endif // WORLDPLAYER_H_INCLUDED
