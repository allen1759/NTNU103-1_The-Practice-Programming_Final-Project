#include "CollectableUnit.h"

//類別內容回傳
    //土地金額
//size_t CCollectableUnit::getPrice() const
//{
//    return price_;
//}
    //過路費
size_t CCollectableUnit::getFine(const size_t dice) const
{
    return host_->getcoll_unit_() * travel_fine_;
}

//類別內容比較

//狀態更動
    //賣出
//void CCollectableUnit::NewHost(CPlayer *P1)
//{
//    host_ = P1;
//    buyable_ = false;
//}


