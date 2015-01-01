#ifndef UPGRADABLEUNIT_H_INCLUDED
#define UPGRADABLEUNIT_H_INCLUDED

#include <string>
#include <vector>
#include "MapUnit.h"

class CUpgradableUnit: public CMapUnit
{
public:
    CUpgradableUnit(const std::string & name, size_t id, size_t numPlayer,size_t price,size_t upgrade,const std::vector<size_t> & f1);
//���O���e�^��
    //�g�a���Bp
    size_t getPrice() const;
    //�L���O
    virtual size_t getFine(const size_t dice) const;
    //�ɯŪ��B
    size_t getUp_price() const;

//���O���e���

//���A���
    //��X
    void NewHost(CPlayer *P1);
    //�D�H�}��
    void bankrupt();

private:
    //           �a��      �ɯŪ��B
    const size_t price_=0,upgrade_price=0;
    std::vector <size_t> travel_fine_;
    //     ����
    size_t level_ = 1;
};

#endif // UPGRADABLEUNIT_H_INCLUDED
