#ifndef COLLECTABLEUNIT_H_INCLUDED
#define COLLECTABLEUNIT_H_INCLUDED

#include "MapUnit.h"

class CCollectableUnit: public CMapUnit
{
    CCollectableUnit(const std::string &name, bool buy, size_t id,size_t numPlayer,const size_t price)
    :CMapUnit(name,buy,id,numPlayer),price_(price)
    { }
//類別內容回傳
    //土地金額
    size_t getPrice() const;
    //過路費 ( 統一傳 dice )
    virtual size_t getFine(const size_t dice) const;

//類別內容比較

//狀態更動
    //賣出
    void NewHost(CPlayer *P1);
    //主人破產
    void bankrupt();

private:
    //           地價      罰金
    const size_t price_=0, travel_fine_ =0;
};

#endif // COLLECTABLEUNIT_H_INCLUDED
