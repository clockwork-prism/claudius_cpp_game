#ifndef _GAUL_H_
#define _GAUL_H_

#include "region.h"

class Gaul: public Region {
    private:
        int *pBarbariansInvaded;
    public:
        Gaul();
        virtual ~Gaul();
        // TODO: add move and copy constructors to handle pointer

        virtual std::vector<std::string> location_events(Army &claudius) override;
        void goth_battle(Army &claudius);
};

#endif // _GAUL_H_