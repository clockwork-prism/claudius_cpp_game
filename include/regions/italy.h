#ifndef _ITALY_H_
#define _ITALY_H_

#include "region.h"

class Italy : public Region {
    protected:
        int defectionSize {};
    public:
        Italy(Army _local_army, int defectionSize_);
        virtual ~Italy() = default;
        virtual std::tuple<std::vector<std::string>, Phase> location_events(Army &claudius) override;
        Phase severus_battle(Army &claudius);
        virtual bool army_joins_claudius(Army &claudius) override;
};

#endif // _ITALY_H_