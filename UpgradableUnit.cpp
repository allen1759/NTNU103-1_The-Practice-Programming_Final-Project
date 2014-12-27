#include "UpgradableUnit.h"

//類別內容回傳
    //土地金額
size_t CUpgradableUnit::getPrice() const
{
    return price_;
}
    //過路費
size_t CUpgradableUnit::getFine() const
{
    return travel_fine_[level_-1];
}
    //升級金額
size_t CUpgradableUnit::getUp_price () const
{
    return upgrade_price;
}
    //主人id (-1表無主地)
size_t CUpgradableUnit::getHost() const
{
    return host_;
}
//類別內容比較
    //主人身分
bool CUpgradableUnit::isHostRight(const size_t id) const
{
    return ( id == host_ );
}
//狀態更動
    //賣出
void CUpgradableUnit::NewHost(const size_t id)
{
    host_ = id;
    buyable_ = false;
}
    //主人破產
void CUpgradableUnit::bankrupt()
{
    level_ = 1;
    buyable_ = true;
}
