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

    print_message<std::string>({
        " ------------------------------------------------------------ ",
        "|                                                            |",
        "|             Claudius: Praetorian Prefect                   |",
        "|                                                            |",
        " ------------------------------------------------------------ "
    });

    GameState gameState {"assets/gamestate.scn"};

    do {
        main_game_loop(gameState);
    } while (gameState.choice != 'Q' && (gameState.currentPhase == playing || gameState.currentPhase == starting));

    game_end(gameState);

    return 0;
}

// ***************************************************************************************