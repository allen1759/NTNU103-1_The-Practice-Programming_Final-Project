#ifndef COLLECTABLEUNIT_H_INCLUDED
#define COLLECTABLEUNIT_H_INCLUDED

#include "MapUnit.h"

class CCollectableUnit: public CMapUnit
{
public:
    CCollectableUnit(const std::string &name, size_t id,size_t numPlayer,const size_t price)
    :CMapUnit(name,true,id,numPlayer),price_(price)
    { }
//���O���e�^��
    //�g�a���B
    virtual size_t getPrice() const override {return price_;}
    //�L���O ( �Τ@�� dice )
    virtual size_t getFine(size_t dice) const override;


//���A���
    //��X
    void NewHost(CPlayer *P1);
    //�D�H�}��
    void bankrupt();

private:
    //           �a��      �@��
    const size_t price_=0, travel_fine_ =0;
};

#endif // COLLECTABLEUNIT_H_INCLUDED
