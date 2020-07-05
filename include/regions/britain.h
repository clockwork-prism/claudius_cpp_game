#ifndef _BRITAIN_H_
#define _BRITAIN_H_

#include "region.h"

class Britain : public Region {
    public:
        Britain(Army _local_army);
        Britain(std::string file_name) : Region{file_name} {}
        virtual ~Britain() = default;

        virtual std::tuple<std::vector<std::string>, Phase> location_events(Army &claudius) override;
};

#endif // _BRITAIN_H_