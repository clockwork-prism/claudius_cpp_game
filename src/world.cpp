#include "world.h"

World::World(Army british_, Army danube_, Army goths_, Army severus_, int defectionSize_) {
    pBarbariansInvaded = std::make_shared<int>(0);

    gaul = std::make_shared<Gaul>(goths_, pBarbariansInvaded);
    danube = std::make_shared<Danube>(danube_);
    iberia = std::make_shared<Iberia>(Army {0, eIberia, 0}, pBarbariansInvaded);
    italy = std::make_shared<Italy>(severus_, defectionSize_);
    britain = std::make_shared<Britain>(british_);
    beginning = std::make_shared<Beginning> ();
}
