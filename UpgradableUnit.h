#ifndef UPGRADABLEUNIT_H_INCLUDED
#define UPGRADABLEUNIT_H_INCLUDED

#include <string>
#include <vector>
#include "MapUnit.h"

class CUpgradableUnit: public CMapUnit
{
public:
    CUpgradableUnit(const std::string & name, size_t id, size_t numPlayer,size_t price,size_t upgrade,const std::vector<size_t> & f1);
//類別內容回傳
    //土地金額p
    size_t getPrice() const;
    //過路費
    virtual size_t getFine(const size_t dice) const;
    //升級金額
    size_t getUp_price() const;

//類別內容比較

//狀態更動
    //賣出
    void NewHost(CPlayer *P1);
    //主人破產
    void bankrupt();

private:
    //           地價      升級金額
    const size_t price_=0,upgrade_price=0;
    std::vector <size_t> travel_fine_;
    //     等級
    size_t level_ = 1;
};

#endif // UPGRADABLEUNIT_H_INCLUDED
