#include "UpgradableUnit.h"

//類別內容回傳
    //土地金額
size_t CUpgradableUnit::price() const
{
    return price_;
}
    //過路費
size_t CUpgradableUnit::fine() const
{
    return ( price_*0.1 ) * level_;
}
    //升級金額
size_t CUpgradableUnit::up_price () const
{
    return upgrade_price;
}
    //主人id (-1表無主地)
size_t CUpgradableUnit::MyHost_() const
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
    //主人破產
void CUpgradableUnit::bankrupt()
{
    host_ = -1;
    level_ = 1;
}
