#ifndef RANDOMCOSTUNIT_H_INCLUDED
#define RANDOMCOSTUNIT_H_INCLUDED

#include "MapUnit.h"

class CRandomCostUnit: public CMapUnit
{
    CRandomCostUnit() = default;
    CRandomCostUnit(std::string name, bool buy, size_t id, size_t numPlayer,const size_t price)
    :CMapUnit(name,buy,id,numPlayer),price_(price),host_(0) { }
//類別內容回傳
    //土地金額
    size_t price() const;
    //過路費
    size_t fine(const size_t point) const;
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
    //地價          地主
    size_t price_=0,host_=0;

};

#endif // RANDOMCOSTUNIT_H_INCLUDED
