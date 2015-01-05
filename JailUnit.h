#ifndef JAILUNIT_H_INCLUDED
#define JAILUNIT_H_INCLUDED

#include "MapUnit.h"

class CJailUnit: public CMapUnit
{
public:
    CJailUnit(std::string name,size_t id,size_t numPlayer):CMapUnit(name,false,id,numPlayer){}

    virtual size_t getFine(const size_t dice) const override
    {return 0;}
    virtual bool isBuyable() const override {return false;}
    virtual bool stopPlayer() const override {return true;}
    virtual void display(size_t index) const override {
        CMapUnit::display(index);
    }

private:
};

#endif // JAILUNIT_H_INCLUDED
