#ifndef _GAUL_H_
#define _GAUL_H_

#include "region.h"

class Gaul: public Region {
    private:
        std::shared_ptr<int> pBarbariansInvaded;
    public:
        Gaul(Army _local_army, std::shared_ptr<int> bi);
        Gaul(std::string file, std::shared_ptr<int> bi);
        virtual ~Gaul();
        // TODO: add move and copy constructors to handle pointer

        virtual std::tuple<std::vector<std::string>, Phase> location_events(Army &claudius) override;
        void goth_battle(Army &claudius);
};

#endif // _GAUL_H_