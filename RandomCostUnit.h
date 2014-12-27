#ifndef RANDOMCOSTUNIT_H_INCLUDED
#define RANDOMCOSTUNIT_H_INCLUDED

#include "MapUnit.h"

class CRandomCostUnit: public CMapUnit
{
    CRandomCostUnit() = default;
    CRandomCostUnit(std::string name, bool buy, size_t id, size_t numPlayer,const size_t price)
    :CMapUnit(name,buy,id,numPlayer),price_(price),host_(0) { }
//���O���e�^��
    //�g�a���B
    size_t getPrice() const;
    //�L���O
    size_t getFine(const size_t point) const;

//���O���e���

//���A���
    //��X
    void NewHost(const size_t id);
    //�D�H�}��
    void bankrupt();
private:
    //�a��          �a�D
    size_t price_=0,host_=0;

};

#endif // RANDOMCOSTUNIT_H_INCLUDED
