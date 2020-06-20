#include "region.h"

bool Region::army_joins_claudius(Army &claudius) {
    if (claudius.reputation >= this->local_army.reputation) {
        claudius += this->local_army;
        this->local_army.size = 0;
        return true;
    }
    return false;
}