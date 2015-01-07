#ifndef WORLDPLAYER_H_INCLUDED
#define WORLDPLAYER_H_INCLUDED

#include "Player.h"

class CWorldPlayer
{
public:
    CWorldPlayer() {}

    void GetNumOfPlayer (const size_t num) { num_of_player_ = num; }
    void AddPlayer(const size_t id,std::string name_);
    void PrintPlayers(const size_t current_id) const;
    CPlayer & operator [] (const size_t ind) {return players[ind];}
    const CPlayer & operator [] (const size_t ind) const {return players[ind];}
    size_t size() const { return num_of_player_;}

    static constexpr size_t max_num_player = 4;
private:
    size_t num_of_player_ = 0;
    CPlayer players[max_num_player];
};
#endif // WORLDPLAYER_H_INCLUDED
