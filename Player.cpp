#include <iostream>
#include <iomanip>
#include "Player.h"

using namespace std;

void CPlayer::PrintPlayer() const
{
    cout << "[" << id_ << "]" << setw(15) << name_ << "  $" << setw(5) << money_
         << " with " << num_unit_ << " units \n" ;
}

void CPlayer::Move(size_t dice, size_t numOfMapUnit)
{
    location_ += dice;
    location_ = location_ % numOfMapUnit;
}

bool CPlayer::ModifyMoney(int m)
{
    money_ += m;
    if(money_ < 0)
    {
        dead_ = true;
    }
    return !dead_;
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
