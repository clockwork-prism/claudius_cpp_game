#ifndef _WORLD_H_
#define _WORLD_H_
#include "gaul.h"
#include "britain.h"
#include "danube.h"
#include "italy.h"
#include "iberia.h"
#include "beginning.h"

struct World {
    Region *gaul {nullptr};
    Region *danube {nullptr};
    Region *britain {nullptr};
    Region *italy {nullptr};
    Region *iberia {nullptr};
    Region *beginning {nullptr};

    World(Army british_, Army danube_, Army goths_, Army severus_, int defectionSize_);
    ~World();
};

#endif // _WORLD_H_