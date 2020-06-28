#include "region.h"

Region::Region(Army _local_army) : local_army{_local_army} {}

bool Region::army_joins_claudius(Army &claudius) {
    if (claudius.reputation >= this->local_army.reputation) {
        claudius += this->local_army;
        this->local_army.size = 0;
        return true;
    }
    return false;
}

void Region::update_message(std::vector<std::string> &out_message, int index) {
    out_message.insert(out_message.end(), this->messages.at(index).begin(), this->messages.at(index).end());
}