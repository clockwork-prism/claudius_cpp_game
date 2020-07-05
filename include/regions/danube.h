#ifndef _DANUBE_H_
#define _DANUBE_H_

#include "region.h"

class Danube : public Region {
    public:
        Danube(Army _local_army);
        Danube(std::string file_name) : Region{file_name} {}
        virtual ~Danube() = default;

        virtual std::tuple<std::vector<std::string>, Phase> location_events(Army &claudius) override;
};

#endif // _DANUBE_H_