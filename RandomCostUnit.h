#ifndef RANDOMCOSTUNIT_H_INCLUDED
#define RANDOMCOSTUNIT_H_INCLUDED

#include "MapUnit.h"
#include "Player.h"

class CRandomCostUnit: public CMapUnit
{
    CRandomCostUnit() = default;
    CRandomCostUnit(const std::string &name, size_t id, size_t numPlayer,const size_t price)
    :CMapUnit(name,true,id,numPlayer),price_(price) { }
//類別內容回傳
    //土地金額
    size_t getPrice() const;
    //過路費
    size_t getFine(size_t point) const;

    //virtual size_t getFine(size_t dice) const;
//類別內容比較

//狀態更動
    //賣出
    void NewHost(CPlayer *P1);
    //主人破產
    void bankrupt();

private:
    size_t price_=0;        //地價
    size_t unit_fine_ = 0;  //罰金
};

#endif // RANDOMCOSTUNIT_H_INCLUDED
