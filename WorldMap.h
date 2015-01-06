#ifndef WORLDMAP_H_INCLUDED
#define WORLDMAP_H_INCLUDED

#include "MapUnit.h"
#include "UpgradableUnit.h"
#include "CollectableUnit.h"
#include "RandomCostUnit.h"
#include "JailUnit.h"
#include <vector>

class CWorldMap
{
public:
    CWorldMap() = default;
    ~CWorldMap() {}

    size_t size() const { return units_.size(); }
    void AddMap(CMapUnit *);
    void GoTo_StartPoint(size_t num);
    void display() const;
    CMapUnit * & operator [] (size_t ind) {return units_[ind];}
    CMapUnit * const & operator [] (size_t ind) const {return units_[ind];}

private:
    std::vector<CMapUnit *> units_;
};
#endif // WORLDMAP_H_INCLUDED
