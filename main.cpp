#include <iostream>
#include "Player.h"
#include "MapUnit.h"
#include "JailUnit.h"
#include "CollectableUnit.h"
#include "RandomCostUnit.h"
#include "UpgradableUnit.h"
#include "Game.h"
using namespace std;

int main()
{
    CJailUnit testUnit("213", 0, 4);
    CCollectableUnit testCollect("123", 1, 4, 2000);

    return 0;
}
