#ifndef COLLECTABLEUNIT_H_INCLUDED
#define COLLECTABLEUNIT_H_INCLUDED

#include "MapUnit.h"

class CCollectableUnit: public CMapUnit
{
    CCollectableUnit() = default;
    CCollectableUnit(const std::string &name, bool buy, size_t id, size_t numPlayer,const size_t price)
    :CMapUnit(name,buy,id,numPlayer),price_(price)
    { }
//���O���e�^��
    //�g�a���B
    size_t getPrice() const;
    //�L���O
    size_t getFine(const size_t C_Unit) const;

//���O���e���

//���A���
    //��X
    void NewHost(CPlayer *P1);
    //�D�H�}��
    void bankrupt();


private:
    //           �a��      �@��
    const size_t price_=0, travel_fine_ =0;
    //      �ӤH�{���ت��ƶq�j�q�bhost���W���ΡA
    //      �u�n�b�p��@����host���W�����Y�i
};

#endif // COLLECTABLEUNIT_H_INCLUDED
