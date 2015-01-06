#include "JailUnit.h"
#include <iostream>

void CJailUnit::display(size_t index) const
{
    CMapUnit::display(index);
    std::cout << "               " ;
    // 12 spaces;
}
