#ifndef COLLECTABLEUNIT_H_INCLUDED
#define COLLECTABLEUNIT_H_INCLUDED

#include "MapUnit.h"

class CCollectableUnit: public CMapUnit
{
public:
    CCollectableUnit(const std::string &name, size_t id,size_t numPlayer,const size_t price)
    :CMapUnit(name,true,id,numPlayer),price_(price)
    { }
//Ãþ§O¤º®e¦^¶Ç
    //¤g¦aª÷ÃB
    virtual size_t getPrice() const override {return price_;}
    //¹L¸ô¶O ( ²Î¤@¶Ç dice )
    virtual size_t getFine(size_t dice) const override;


//ª¬ºA§ó°Ê
    //½æ¥X
    void NewHost(CPlayer *P1);
    //¥D¤H¯}²£
    void bankrupt();
    virtual void display() const override {}

private:
    //           ¦a»ù      »@ª÷
    const size_t price_=0, travel_fine_ =0;
};

#endif // COLLECTABLEUNIT_H_INCLUDED
