#include "game_state.h"

GameState::GameState(Army claudius_, Army british_, Army danube_, Army goths_, Army severus_):
    claudius {claudius_}, 
    britishLegions{british_}, 
    danubeLegions {danube_}, 
    goths {goths_},
    severus {severus_},
    message{}, 
    menu{}, 
    currentPhase {Phase::starting}, 
    barbariansInvaded{0} 
    {

}

bool GameState::danube_joins_claudius() {
    if (claudius.reputation > danubeLegions.reputation) {
        claudius.size += danubeLegions.size;
        danubeLegions.size = 0;
        return true;
    }
    return false;
}

bool GameState::british_joins_claudius() {
    if (claudius.reputation > britishLegions.reputation) {
        claudius.size += britishLegions.size;
        britishLegions.size = 0;
        return true;
    }
    return false;
}

void GameState::goth_battle() {
    claudius.size -= goths.size;
    claudius.reputation += goths.reputation;
    goths.size = 0;
    barbariansInvaded = 2;
}

bool GameState::severus_defects(int defectionSize) {
    if (claudius.reputation > severus.reputation) {
        claudius.size += defectionSize;
        severus.size -= defectionSize;
        return true;
    }
    return false;
}

