#ifndef UPGRADABLEUNIT_H_INCLUDED
#define UPGRADABLEUNIT_H_INCLUDED

#include <string>
#include "MapUnit.h"

class CUpgradableUnit: public CMapUnit
{
public:
    CUpgradableUnit() = default;
    CUpgradableUnit(std::string name, bool buy, size_t id, size_t numPlayer,const size_t price)
    :CMapUnit(name,buy,id,numPlayer),price_(price),upgrade_price(0.1*price_+100),level_(1),host_(-1) { }
//類別內容回傳
    //土地金額
    size_t price() const;
    //過路費
    size_t fine() const;
    //升級金額
    size_t up_price () const;
    //主人id (-1表無主地)
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
    size_t level_=1;     //等級
    int host_=-1;        //地主

};

#endif // UPGRADABLEUNIT_H_INCLUDED
