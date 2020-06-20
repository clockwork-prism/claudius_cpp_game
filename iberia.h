#ifndef _IBERIA_H_
#define _IBERIA_H_

#include "region.h"

class Iberia : public Region {
    private:
        int *pBarbariansInvaded;
    public:
        Iberia();
        virtual ~Iberia();

        virtual std::vector<std::string> location_events(Army &claudius) override;
};

#endif // _IBERIA_H_