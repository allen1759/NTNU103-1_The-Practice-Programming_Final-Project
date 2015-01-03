#ifndef COLLECTABLEUNIT_H_INCLUDED
#define COLLECTABLEUNIT_H_INCLUDED

#include "MapUnit.h"

class CCollectableUnit: public CMapUnit
{
public:
    CCollectableUnit(const std::string &name, size_t id,size_t numPlayer,const size_t price)
    :CMapUnit(name,true,id,numPlayer),price_(price)
    { }
//類別內容回傳
    //土地金額
    virtual size_t getPrice() const override {return price_;}
    //過路費 ( 統一傳 dice )
    virtual size_t getFine(size_t dice) const override;


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
