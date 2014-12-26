#include "RandomCostUnit.h"

//類別內容回傳
    //土地金額
size_t CRandomCostUnit::price() const
{
    return price_;
}
    //過路費(需傳入點數)
size_t CRandomCostUnit::fine(const size_t point) const
{
    return point * ( 0.1 * price_ );
}
    //主人id
size_t CRandomCostUnit::MyHost_() const
{
    return host_;
}

//類別內容比較
    //主人身分
bool CRandomCostUnit::isHostRight(const size_t id) const
{
    return ( host_ == id );
}
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
    return;
}
