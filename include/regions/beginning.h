#ifndef _BEGINNING_H_
#define _BEGINNING_H_

#include "region.h"

class Beginning: public Region {
    public:
        Beginning(Army local_army_ = Army{0, eBeginning, 0});
        virtual ~Beginning() = default;

        virtual std::tuple<std::vector<std::string>, Phase> location_events(Army &claudius) override;

};

#endif