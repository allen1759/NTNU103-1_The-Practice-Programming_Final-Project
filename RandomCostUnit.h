#ifndef RANDOMCOSTUNIT_H_INCLUDED
#define RANDOMCOSTUNIT_H_INCLUDED

#include "MapUnit.h"
#include "Player.h"

class CRandomCostUnit: public CMapUnit
{
    CRandomCostUnit() = default;
    CRandomCostUnit(const std::string &name, size_t id, size_t numPlayer,const size_t price)
    :CMapUnit(name,true,id,numPlayer),price_(price) { }
//���O���e�^��
    //�g�a���B
    size_t getPrice() const;
    //�L���O
    size_t getFine(size_t point) const;

    //virtual size_t getFine(size_t dice) const;
//���O���e���

//���A���
    //��X
    void NewHost(CPlayer *P1);
    //�D�H�}��
    void bankrupt();

private:
    size_t price_=0;        //�a��
    size_t unit_fine_ = 0;  //�@��
};

#endif // RANDOMCOSTUNIT_H_INCLUDED
