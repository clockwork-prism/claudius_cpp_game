#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include "funcs.h"
#include "utils.h"
#include "game_state.h"

using namespace std;


// ***************************************************************************************

int main() {

    print_message({
        " ------------------------------------------------------------ ",
        "|                                                            |",
        "|             Claudius: Praetorian Prefect                   |",
        "|                                                            |",
        " ------------------------------------------------------------ "
    });

    GameState gameState {
        Army {10000, Beginning, 0}, // Claudius
        Army {5000, Britain, 1}, // British
        Army {5000, Danube, 0}, // Danube
        Army {2000, Gaul, 1}, // Goths
        Army {12000, Italy, 2}, // Severus
        2500 // Defection Size
    };

    do {
        main_game_loop(gameState);
    } while (gameState.choice != 'Q' && (gameState.currentPhase == playing || gameState.currentPhase == starting));

    game_end(gameState);

    return 0;
}

// ***************************************************************************************