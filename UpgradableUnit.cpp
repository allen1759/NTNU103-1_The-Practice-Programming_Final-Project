#include "UpgradableUnit.h"

CUpgradableUnit::CUpgradableUnit(const std::string & name, size_t id, size_t numPlayer,size_t price,size_t upgrade,const std::vector<size_t> & f1)
    :CMapUnit(name,true,id,numPlayer),price_(price),upgrade_price(upgrade),level_(1)
    {
        for(int i=0,L1 = f1.size();i<L1;i++) {
            travel_fine_.push_back(f1[i]);
        }
    }


//類別內容回傳
    //土地金額
size_t CUpgradableUnit::getPrice() const
{
    return price_;
}
    //過路費
size_t CUpgradableUnit::getFine(const size_t dice) const
{
    return travel_fine_[level_-1];
}
    //升級金額
size_t CUpgradableUnit::getUp_price () const
{
    return upgrade_price;
}

//類別內容比較

//狀態更動
    //賣出
void CUpgradableUnit::NewHost(CPlayer *P1)
{
    host_ = P1;
    buyable_ = false;
    level_ = 1;
}
    //主人破產
void CUpgradableUnit::bankrupt()
{
    level_ = 1;
    buyable_ = true;
}
