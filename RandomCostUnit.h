#ifndef RANDOMCOSTUNIT_H_INCLUDED
#define RANDOMCOSTUNIT_H_INCLUDED

#include "MapUnit.h"
#include "Player.h"

class CRandomCostUnit: public CMapUnit
{
public:
    CRandomCostUnit(const std::string &name, size_t id, size_t numPlayer,size_t price,size_t fine)
        :CMapUnit(name,true,id,numPlayer),price_(price),travel_fine_(fine) { }
//���O���e�^��
    //�g�a���B
    size_t getPrice() const;
    //�L���O
    virtual size_t getFine(const size_t dice) const;

//���O���e���

//���A���
    //��X
    void NewHost(CPlayer *P1);
    //�D�H�}��
    void bankrupt();

private:
    size_t price_= 0;         //�a��
    size_t travel_fine_ = 0;  //�@��
};

#endif // RANDOMCOSTUNIT_H_INCLUDED
