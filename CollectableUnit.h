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
    size_t fine() const;
    //升級金額
    size_t up_price () const;
    //主人id
    size_t MyHost_() const;

//類別內容比較
    //主人身分
    bool isHostRight(const size_t id) const;

//狀態更動
    //賣出

    //主人破產
    void bankrupt();
private:
    //           地價      升級金額
    const size_t price_=0, upgrade_price=0;
    //     地主    建物數量
    size_t host_=0,num_coll_unit_=0;
};

#endif // COLLECTABLEUNIT_H_INCLUDED
