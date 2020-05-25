#include "game_state.h"

GameState::GameState(Army claudius_, Army british_, Army danube_, Army goths_, Army severus_, int defectionSize_):
    claudius {claudius_}, 
    britishLegions{british_}, 
    danubeLegions {danube_}, 
    goths {goths_},
    severus {severus_},
    defectionSize{defectionSize_},
    message{}, 
    menu{}, 
    currentPhase {Phase::starting}, 
    barbariansInvaded{0},
    choice{}
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

bool GameState::severus_defects() {
    if (claudius.reputation > severus.reputation) {
        claudius.size += defectionSize;
        severus.size -= defectionSize;
        return true;
    }
    return false;
}

void GameState::severus_battle() {
    if (claudius.size > severus.size) {
        currentPhase = victory;
    } else {
        currentPhase = defeat;
    }
}

void GameState::print_stats() {
    std::cout << "\nArmy: " << claudius.size << ", Reputation: ";
    std::cout << (
        (claudius.reputation == 0) ? "Unkown"   : 
        (claudius.reputation == 1) ? "Renowned" : 
                                     "Exalted"
    );
    std::cout << std::endl << "Severus Army: " << severus.size << std::endl;
}

void GameState::move_location() {
    switch (choice) {
        case 'Z': {
            claudius.location = Beginning;
            break;
        }
        case 'B': {
            claudius.location = Britain;
            break;
        }
        case 'I': {
            claudius.location = Italy;
            break;
        }
        case 'G': {
            claudius.location = Gaul;
            break;
        }
        case 'E': {
            claudius.location = Iberia;
            break;
        }
        case 'D': {
            claudius.location = Danube;
            break;
        }
        case 'Q':{
            std::cout << "So that's it? Maybe you were not meant to be" << std::endl;
            std::cout << "the Augustus after all..." << std::endl;
        }
        default:
            break;
    }
}
