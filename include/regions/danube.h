#ifndef _DANUBE_H_
#define _DANUBE_H_

#include "region.h"

class Danube : public Region {
    public:
        Danube(Army _local_army);
        virtual ~Danube() = default;

        virtual std::tuple<std::vector<std::string>, Phase> location_events(Army &claudius) override;
};

#endif // _DANUBE_H_