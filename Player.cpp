#include <iostream>
#include <iomanip>
#include "Player.h"

using namespace std;

void CPlayer::AddPlayer(size_t id)
{
    string d_name_[4] = {"AllenYang", "HEDE0724", "CarolChen", "YuShan"};
    cout << "\nPlease input player " << id << "'s name (Default: "
         << d_name_[id] << " ";
    getline(cin,name_);
    if(name_ == "")
    {
        name_ = d_name_[id];
    }
    id_ = id;
}

void CPlayer::PrintPlayer()
{
    cout << "[" << id_ << "]" << setw(10) << name_ << "  $" << setw(5) << money_
         << " with " << num_unit_ << " units \n" ;
}

void CPlayer::Move(size_t dice)
{
    location_ += dice;
    location_ = location_ % 10;
}

int CPlayer::ModifyMoney(int m)
{
    money_ += m;
    if(money_ < 0)
    {
        dead_ = true;
        return -1;
    }
}

void CPlayer::AddUnit()
{
    num_unit_++;
}

void CPlayer::AddCollUnit()
{
    num_coll_unit_++;
}

void CPlayer::Continue()
{
    stop_ = false;
}

void CPlayer::Stop()
{
    stop_ = true;
}
