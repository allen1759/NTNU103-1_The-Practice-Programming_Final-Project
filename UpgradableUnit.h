#ifndef UPGRADABLEUNIT_H_INCLUDED
#define UPGRADABLEUNIT_H_INCLUDED

#include <string>
#include <vector>
#include "MapUnit.h"

class CUpgradableUnit: public CMapUnit
{
public:
    CUpgradableUnit(const std::string & name, size_t id, size_t numPlayer,size_t price,size_t upgrade,const std::vector<size_t> & f1);
//Ãþ§O¤º®e¦^¶Ç
    //¤g¦aª÷ÃBp
    size_t getPrice() const;
    //¹L¸ô¶O
    virtual size_t getFine(size_t dice) const;
    //¤É¯Åª÷ÃB
    size_t getUp_price() const;

//Ãþ§O¤º®e¤ñ¸û

//ª¬ºA§ó°Ê
    //½æ¥X
    void NewHost(CPlayer *P1);
    //¥D¤H¯}²£
    void bankrupt();
    virtual void display() const override {}

private:
    //           ¦a»ù      ¤É¯Åª÷ÃB
    const size_t price_=0,upgrade_price=0;
    std::vector <size_t> travel_fine_;
    //     µ¥¯Å
    size_t level_ = 1;
};

#endif // UPGRADABLEUNIT_H_INCLUDED
