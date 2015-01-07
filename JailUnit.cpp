#include "JailUnit.h"
#include <iostream>

void CJailUnit::display(const size_t index) const
{
    CMapUnit::display(index);
    std::cout << "               " ;
    // 12 spaces;
}
