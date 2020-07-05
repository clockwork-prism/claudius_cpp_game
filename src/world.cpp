#include "world.h"

World::World() {
    pBarbariansInvaded = std::make_shared<int>(0);

    gaul = std::make_shared<Gaul>("assets/gaul.reg", pBarbariansInvaded);
    danube = std::make_shared<Danube>("assets/danube.reg");
    iberia = std::make_shared<Iberia>("assets/iberia.reg", pBarbariansInvaded);
    italy = std::make_shared<Italy>("assets/italy.reg");
    britain = std::make_shared<Britain>("assets/britain.reg");
    beginning = std::make_shared<Beginning> ();
}
