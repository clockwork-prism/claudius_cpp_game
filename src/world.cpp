#include "world.h"

World::World(Army british_, Army danube_, Army goths_, Army severus_, int defectionSize_) {
    pBarbariansInvaded = new int {0};

    gaul = new Gaul(goths_, pBarbariansInvaded);
    danube = new Danube(danube_);
    iberia = new Iberia({0, eIberia, 0}, pBarbariansInvaded);
    italy = new Italy(severus_, defectionSize_);
    britain = new Britain(british_);
    beginning = new Beginning();
}

World::~World() {
    delete gaul;
    delete danube;
    delete iberia;
    delete italy;
    delete britain;
    delete beginning;
    delete pBarbariansInvaded;
}