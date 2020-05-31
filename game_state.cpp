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
    if (claudius.reputation >= danubeLegions.reputation) {
        claudius += danubeLegions;
        danubeLegions.size = 0;
        return true;
    }
    return false;
}

bool GameState::british_joins_claudius() {
    if (claudius.reputation >= britishLegions.reputation) {
        claudius += britishLegions;
        britishLegions.size = 0;
        return true;
    }
    return false;
}

void GameState::goth_battle() {
    claudius -= goths;
    claudius.reputation += goths.reputation;
    goths.size = 0;
    barbariansInvaded = 2;
}

bool GameState::severus_defects() {
    if (claudius.reputation >= severus.reputation) {
        claudius += defectionSize;
        severus -= defectionSize;
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
    std::cout << claudius;
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
