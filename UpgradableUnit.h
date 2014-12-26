#ifndef UPGRADABLEUNIT_H_INCLUDED
#define UPGRADABLEUNIT_H_INCLUDED

#include <string>
#include <vector>
#include "MapUnit.h"

class CUpgradableUnit: public CMapUnit
{
public:
    CUpgradableUnit() = default;
    CUpgradableUnit(std::string name, bool buy, size_t id, size_t numPlayer,const size_t price,const size_t upgrade,const std::vector<int>f1)
    :CMapUnit(name,buy,id,numPlayer),price_(price),upgrade_price(upgrade),level_(1),host_(0) {
        for(int i=0,L1 = f1.size();i<L1;i++) {
            travel_fine_.push_back(f1[i]);
        }
    }
//類別內容回傳
    //土地金額p
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
    void NewHost(const size_t id);
    //主人破產
    void bankrupt();
private:
    //           地價      升級金額
    const size_t price_=0,upgrade_price=0;
    std::vector <int> travel_fine_;
    //     等級       地主
    size_t level_ = 1,host_ = 0;
};

#endif // UPGRADABLEUNIT_H_INCLUDED
