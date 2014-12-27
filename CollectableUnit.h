#ifndef COLLECTABLEUNIT_H_INCLUDED
#define COLLECTABLEUNIT_H_INCLUDED

#include "MapUnit.h"

class CCollectableUnit: public CMapUnit
{
    CCollectableUnit() = default;
    CCollectableUnit(std::string name, bool buy, size_t id, size_t numPlayer,const size_t price)
    :CMapUnit(name,buy,id,numPlayer),price_(price),host_(0) { }
//類別內容回傳
    //土地金額
    size_t price() const;
    //過路費
    size_t fine(const size_t C_Unit) const;
    //升級金額
    size_t up_price () const;
    //主人id
    size_t MyHost_() const;

//類別內容比較
    //主人身分
    bool isHostRight(const size_t id) const;

//狀態更動
    //賣出
    void NewHost(const size_t id);
    //主人破產
    void bankrupt();

private:
    //           地價      罰金
    const size_t price_=0, travel_fine_ =0;
    //     地主
    size_t host_=0;
    //      個人認為建物數量綁訂在host身上較佳，
    //      只要在計算罰金自host身上拿取即可
};

#endif // COLLECTABLEUNIT_H_INCLUDED
