#include "CollectableUnit.h"

//類別內容回傳
    //土地金額
size_t CCollectableUnit::price() const
{
    return price_;
}
    //過路費
size_t CCollectableUnit::fine(const size_t C_Unit) const
{
    return C_Unit * travel_fine_;
}
    //主人id
size_t CCollectableUnit::MyHost_() const
{
    return host_;
}

//類別內容比較
    //主人身分
bool CCollectableUnit::isHostRight(const size_t id) const
{
    return ( id == host_ );
}
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
