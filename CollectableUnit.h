#ifndef COLLECTABLEUNIT_H_INCLUDED
#define COLLECTABLEUNIT_H_INCLUDED

#include "MapUnit.h"

class CCollectableUnit: public CMapUnit
{
    CCollectableUnit() = default;
    CCollectableUnit(std::string name, bool buy, size_t id, size_t numPlayer,const size_t price)
    :CMapUnit(name,buy,id,numPlayer),price_(price),host_(0) { }
//���O���e�^��
    //�g�a���B
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

    //�D�H�}��
    void bankrupt();
private:
    //           �a��      �ɯŪ��B
    const size_t price_=0, upgrade_price=0;
    //     �a�D    �ت��ƶq
    size_t host_=0,num_coll_unit_=0;
};

#endif // COLLECTABLEUNIT_H_INCLUDED
