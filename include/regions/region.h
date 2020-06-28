#ifndef _REGION_H_
#define _REGION_H_

#include "army.h"
#include "menu.h"
#include <string>
#include <vector>
#include <tuple>


class Region {
    protected:
        Army local_army;
        std::vector<std::vector<std::string>> messages;
    public:
        Region(Army _local_army);

        Menu move_menu;

        virtual std::tuple<std::vector<std::string>, Phase> location_events(Army &claudius) = 0;
        virtual bool army_joins_claudius(Army &claudius);
        int get_army_size() {return local_army.size;}
        void update_message(std::vector<std::string> &out_message, int index);

        virtual ~Region() = default;
};

#endif // _REGION_H_