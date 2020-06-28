#ifndef _WORLD_H_
#define _WORLD_H_
#include "gaul.h"
#include "britain.h"
#include "danube.h"
#include "italy.h"
#include "iberia.h"
#include "beginning.h"
#include <memory>

struct World {
    std::shared_ptr<Region> gaul;
    std::shared_ptr<Region> danube;
    std::shared_ptr<Region> britain;
    std::shared_ptr<Region> italy;
    std::shared_ptr<Region> iberia;
    std::shared_ptr<Region> beginning;

    std::shared_ptr<int> pBarbariansInvaded;

    World(Army british_, Army danube_, Army goths_, Army severus_, int defectionSize_);
    ~World() = default;
};

#endif // _WORLD_H_