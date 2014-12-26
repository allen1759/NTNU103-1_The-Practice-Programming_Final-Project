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
//���O���e�^��
    //�g�a���Bp
    size_t price() const;
    //�L���O
    size_t fine() const;
    //�ɯŪ��B
    size_t up_price () const;
    //�D�Hid
    size_t MyHost_() const;

//���O���e���
    //�D�H����
    bool isHostRight(const size_t id) const;

//���A���
    //��X
    void NewHost(const size_t id);
    //�D�H�}��
    void bankrupt();
private:
    //           �a��      �ɯŪ��B
    const size_t price_=0,upgrade_price=0;
    std::vector <int> travel_fine_;
    //     ����       �a�D
    size_t level_ = 1,host_ = 0;
};

#endif // UPGRADABLEUNIT_H_INCLUDED
