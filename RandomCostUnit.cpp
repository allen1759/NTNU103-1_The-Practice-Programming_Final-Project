#include "RandomCostUnit.h"

//類別內容回傳
    //土地金額
size_t CRandomCostUnit::getPrice() const
{
    return price_;
}
    //過路費(需傳入點數)
size_t CRandomCostUnit::getFine(size_t point) const
{
    return point * ( 0.1 * price_ );
}

//類別內容比較
//狀態更動
    //賣出
void CRandomCostUnit::NewHost(const size_t id)
{
    host_ = id;
    buyable_ = false;
    return;
}
    //主人破產
void CRandomCostUnit::bankrupt()
{
    buyable_ = true;
}


