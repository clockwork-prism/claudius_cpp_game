#ifndef _REGION_H_
#define _REGION_H_

#include "army.h"
#include "menu.h"
#include <string>
#include <vector>


class Region {
    protected:
        Army local_army;
        std::vector<std::vector<std::string>> messages;
        Menu move_menu;
    public:
        virtual std::vector<std::string> location_events(Army &claudius) = 0;
        virtual bool army_joins_claudius(Army &claudius);

        virtual ~Region() = default;
};

#endif // _REGION_H_