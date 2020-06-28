#ifndef _IBERIA_H_
#define _IBERIA_H_

#include "region.h"

class Iberia : public Region {
    private:
        int *pBarbariansInvaded;
    public:
        Iberia(Army _local_army, int *_bi);
        virtual ~Iberia();

        virtual std::tuple<std::vector<std::string>, Phase>location_events(Army &claudius) override;
        void set_barbarians_invaded(int *val) {pBarbariansInvaded = val;}
};

#endif // _IBERIA_H_