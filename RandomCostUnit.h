#ifndef RANDOMCOSTUNIT_H_INCLUDED
#define RANDOMCOSTUNIT_H_INCLUDED

#include "MapUnit.h"
#include "Player.h"

class CRandomCostUnit: public CMapUnit
{
public:
    CRandomCostUnit(const std::string &name, size_t id, size_t numPlayer,size_t price,size_t fine)
        :CMapUnit(name,true,id,numPlayer),price_(price),travel_fine_(fine) { }
//類別內容回傳
    //土地金額
    size_t getPrice() const;
    //過路費
    virtual size_t getFine(const size_t dice) const;

//類別內容比較

//狀態更動
    //賣出
    void NewHost(CPlayer *P1);
    //主人破產
    void bankrupt();

private:
    size_t price_= 0;         //地價
    size_t travel_fine_ = 0;  //罰金
};

#endif // RANDOMCOSTUNIT_H_INCLUDED
