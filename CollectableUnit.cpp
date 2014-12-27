#include "CollectableUnit.h"

//類別內容回傳
    //土地金額
size_t CCollectableUnit::getPrice() const
{
    return price_;
}
    //過路費
size_t CCollectableUnit::getFine(const size_t C_Unit) const
{
    return C_Unit * travel_fine_;
}

//類別內容比較

//狀態更動
    //賣出
void CCollectableUnit::NewHost(const size_t id)
{
    host_ = id;
    buyable_ = false;
}
    //主人破產
void CCollectableUnit::bankrupt()
{
    buyable_ = true;
}
