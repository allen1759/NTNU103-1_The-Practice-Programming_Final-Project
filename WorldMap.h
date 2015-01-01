#ifndef WORLDMAP_H_INCLUDED
#define WORLDMAP_H_INCLUDED

#include "MapUnit.h"
#include <vector>

class CWorldMap
{
public:
    CWorldMap() = default;
    ~CWorldMap() {}

    size_t size() const { return units_.size(); }
    void AddMap(CMapUnit *);

private:
    //static constexpr size_t MaxNumUnit = 20;
    std::vector<CMapUnit *> units_;
};
#endif // WORLDMAP_H_INCLUDED
