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
    size_t price() const;
    //�L���O
    size_t fine(const size_t point) const;
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
    //�a��          �a�D
    size_t price_=0,host_=0;

};

#endif // RANDOMCOSTUNIT_H_INCLUDED
