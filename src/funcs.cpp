#include "funcs.h"

void main_game_loop(GameState &gameState, int sceneWidth) {
    scene_break(sceneWidth);
    std::tuple<std::vector<std::string>, Phase> result {
        gameState.currentRegion->location_events(gameState.claudius)
    };
    gameState.display_map();
    scene_break(sceneWidth);
    print_message(std::get<0>(result));
    gameState.currentPhase = std::get<1>(result);
    if (gameState.currentPhase == playing && gameState.choice != 'Q') {
        gameState.print_stats();
        gameState.choice = gameState.currentRegion->move_menu.get_user_input();
        gameState.move_location();
    } else if (gameState.currentPhase == starting) {
        gameState.choice = 'G';
        gameState.move_location();
    }
}

void game_end(GameState &gameState) {
    if (gameState.currentPhase == victory) {
        print_message<std::string>({
            "As the dust clears, you see Severus's army either surrendering",
            "or fleeing. You give orders for generous quarter to be given,",
            "and search out Severus. You find him dead, a slave having assisted",
            "him in suicide. You feel yourself breathe a sigh of relief, and",
            "realize that you are now Caesar! And as you realize that, the relief",
            "turns to a new anxiety. The game for the throne might be over, but",
            "how long will you keep it?"
        });
    } else if (gameState.currentPhase == defeat) {
        print_message<std::string>({
            "You stare in stunned silence as first the left flank collapses,",
            "then the right. Your center backs up trying to prevent a gap in the",
            "line, but this soon becomes a route. Your whole army is in flight, and",
            "a merciless Severus deploys the light cavalry to cut down fleeing",
            "soldiers. You try to rally the men, but a thrown spear strikes you in the",
            "throat. So ends the tragic tale of Claudius."
        });
    }

    std::cout << "GAME OVER" << std::endl;
}

void scene_break(int sceneWidth) {
    std::cout << "\n";
    for (int i; i < sceneWidth; i++) {
        std::cout << "=";
    }
    std::cout << "\n\n";
}