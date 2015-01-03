#ifndef RANDOMCOSTUNIT_H_INCLUDED
#define RANDOMCOSTUNIT_H_INCLUDED

#include "MapUnit.h"
#include "Player.h"

class CRandomCostUnit: public CMapUnit
{
public:
    CRandomCostUnit(const std::string &name, size_t id, size_t numPlayer,size_t price,size_t fine)
        :CMapUnit(name,true,id,numPlayer),price_(price),travel_fine_(fine) { }
//Ãþ§O¤º®e¦^¶Ç
    //¤g¦aª÷ÃB
    size_t getPrice() const;
    //¹L¸ô¶O
    virtual size_t getFine(size_t dice) const;

//Ãþ§O¤º®e¤ñ¸û

//ª¬ºA§ó°Ê
    //½æ¥X
    void NewHost(CPlayer *P1);
    //¥D¤H¯}²£
    void bankrupt();
    virtual void display() const override {}

private:
    size_t price_= 0;         //¦a»ù
    size_t travel_fine_ = 0;  //»@ª÷
};

#endif // RANDOMCOSTUNIT_H_INCLUDED
