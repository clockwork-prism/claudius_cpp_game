#ifndef _IBERIA_H_
#define _IBERIA_H_

#include "region.h"

class Iberia : public Region {
    private:
        std::shared_ptr<int> pBarbariansInvaded;
    public:
        Iberia(Army _local_army, std::shared_ptr<int> _bi);
        virtual ~Iberia() = default;

        virtual std::tuple<std::vector<std::string>, Phase>location_events(Army &claudius) override;
};

#endif // _IBERIA_H_