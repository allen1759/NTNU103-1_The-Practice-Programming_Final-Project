#include <iostream>
#include <iomanip>
#include "Player.h"

using namespace std;

void CPlayer::PrintPlayer() const
{
    cout << "[" << id_ << "]" << setw(15) << name_ << "  $" << setw(5) << money_
         << " with " << num_unit_ << " units \n" ;
}

bool CPlayer::Move(size_t dice, size_t numOfMapUnit)
{
    location_ += dice;
    if( location_ >= numOfMapUnit ) {
        location_ = location_ % numOfMapUnit;
        return true;
    }
    return false;
}


void CPlayer::EarnMoney(int m)
{
    money_ += m;
}

void CPlayer::PayMoney(int m)
{
    money_ -= m;
    if(money_ < 0)
    {
        dead_ = true;
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
