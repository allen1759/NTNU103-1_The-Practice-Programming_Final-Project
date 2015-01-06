#ifndef JAILUNIT_H_INCLUDED
#define JAILUNIT_H_INCLUDED

#include "MapUnit.h"

class CJailUnit: public CMapUnit
{
public:
    CJailUnit(std::string name,size_t id,size_t numPlayer):CMapUnit(name,false,id,numPlayer){}

    virtual bool stopPlayer() const override {return true;}
    virtual void display(size_t index) const override;
    virtual void releaseMap() override {}

private:
};

#endif // JAILUNIT_H_INCLUDED
