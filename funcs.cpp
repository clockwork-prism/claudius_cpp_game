#include "funcs.h"

void main_game_loop(GameState &gameState, int sceneWidth) {
    gameState.clear_message();
    scene_break(sceneWidth);
    process_location_events(gameState);
    gameState.display_message();
    if (gameState.currentPhase == playing && gameState.choice != 'Q') {
        gameState.print_stats();
        gameState.choice = gameState.menu.get_user_input();
        gameState.move_location();
    }
}

void game_start(GameState &gameState) {
    print_message({
        "Standing in a field of victory, you survey your tired army.",
        "Victorious over the Gothic invaders, your men begin to ask",
        "why the emperor, Severus, sits in Rome while you are the one",
        "defending the empire. They come to you now, and proclaim you",
        "Augustus! How do you respond?"
    });

    gameState.menu.set_prompt({
        "1 - \"I accept!\"",
        "2 - \"I cannot, I am unworthy.\""
    });
    gameState.menu.set_valid_choices({'1', '2'});

    gameState.choice = gameState.menu.get_user_input();

    std::cout << "\n\n";

    if (gameState.choice == '1') {
        gameState.update_message({"Then let the games begin..."});     
    } else {
        gameState.update_message({
            "Your humility is an example to all, and your reputation grows!",
            "But soon the men approach again, they insist you must accept",
            "the throne. Relenting, you agree to lead them."
        });
        gameState.reputation_gained(1);
    }
    gameState.choice = 'G';
    gameState.move_location();
}

void process_location_events(GameState &gameState) {
    switch (gameState.get_claudius_loc()) {
        case eBeginning: {
            game_start(gameState);
            break;
        }
        case eGaul:{
            gaul_loc_events(gameState);
            break;
        }
        case eIberia: {
            iberia_loc_events(gameState);
            break;
        }
        case eBritain: {
            briain_loc_events(gameState);
            break;
        }
        case eDanube: {
            danube_loc_events(gameState);
            break;
        }
        case eItaly: {
            italy_loc_events(gameState);
            break;
        }
        default:
            break;
    }
}

void gaul_loc_events(GameState &gameState) {
    gameState.currentPhase = playing;
    gameState.clear_message();
    if (gameState.barbariansInvaded == 1) {
        gameState.goth_battle();
        gameState.update_message({
            "You descend on Gaul and fan out your forces to confront the",
            "invaders. You lose some men, but your reputation grows higher!\n"
        });
    }

    gameState.update_message({
        "The familiar land of Gaul surrounds you. To the south is Italy",
        "where Severus waits with his army.",
        "The Danube is to the east, legions there have no love for the",
        "emperor. To the west is Iberia, currently not garrisoned. And",
        "to the north lies Britain. The legions there may be more",
        "hesitant to follow an unkown."
    });

    gameState.menu.set_prompt({
        "\nWhere will you go?",
        "B - Britain",
        "D - Danube",
        "I - Italy",
        "E - Iberia",
        "Q - Quit the game"
    });

    gameState.menu.set_valid_choices({'B', 'D', 'I', 'E', 'Q'});
}


void iberia_loc_events(GameState &gameState) {
    if (gameState.barbariansInvaded == 0) {
        gameState.update_message({
            "As you make camp in Iberia just beyond the mountains",
            "you receive dire news. Barbarians have invaded Gaul!",
            "This is a great misfortune, though a fresh victory",
            "may bring more renown..."
        });
        gameState.barbariansInvaded = 1;
    } else {
        gameState.update_message({
            "The Iberian peninsula is mercifully peaceful. You briefly",
            "allow yourself to think about quiet retirement, but the",
            "the war beckons."
        });
    }
    gameState.menu.set_prompt({
            "\nWhere will you go?",
            "G - Gaul",
            "Q - Quit the game"
    });
    gameState.menu.set_valid_choices({'G', 'Q'});
}


void briain_loc_events(GameState &gameState) {
    if (gameState.britain_garrisoned()) {
        if (gameState.british_joins_claudius()) {
            gameState.update_message({
                "Your reputation precedes you, and the men of the British",
                "legions flock to your banner!"
            });
        } else {
            gameState.update_message({
                "While not in a hurry to challenge you, the British legions",
                "will not aid your cause. Maybe if you can increase your reputation",
                "somehow they will join."
            });
        }
    } else {
        gameState.update_message({
            "The British isles are never quite peaceful, and it would be",
            "dangerous to pull away any more men from the garrison. Best",
            "head back to the mainland soon."
        });
    }
    gameState.menu.set_prompt({
        "\nWhere will you go?",
        "G - Gaul",
        "Q - Quit the game"
    });
    gameState.menu.set_valid_choices({'G', 'Q'});
}

void danube_loc_events(GameState &gameState) {
    if (gameState.danube_garrisoned()) {
        gameState.update_message({
            "The Danube legions are overjoyed to hear someone wants to kill",
            "Severus. Some of your officers are a little concerned at this",
            "quick turn around, but you need all the forces you can muster."
        });
        gameState.danube_joins_claudius();
    } else {
        gameState.update_message({
            "You stare at the Danube, for the moment lost in thought. Which",
            "river has seen more violence? The Rhine or the Danube? Staring at",
            "the far bank, you decide it's best to move on rather than recruit",
            "any more men."
        });
    }
    gameState.menu.set_prompt({
        "\nWhere will you go?",
        "G - Gaul",
        "I - Italy",
        "Q - Quit the game"
    });
    gameState.menu.set_valid_choices({'G', 'I', 'Q'});
}

void italy_loc_events(GameState &gameState) {
    gameState.update_message({
        "The crossing of the Alps is as smooth as it can be, Severus",
        "is not waiting for you on the other side. Reports are he is",
        "further south. You pause at the Rubicon to make camp, a part",
        "of you amused to think of yourself as Julius himself. The next",
        "day, the scouts report in. Severus approaches. You form up for",
        "battle."
    });
    if (gameState.severus_defects()) {
        gameState.update_message({
            "You're exploits have reached the people of Rome, and",
            "now Severus's armies begin to abandon him! Your ranks swell",
            "but will it be enough?"
        });
    }
    gameState.severus_battle();
}

void game_end(GameState &gameState) {
    if (gameState.currentPhase == victory) {
        print_message({
            "As the dust clears, you see Severus's army either surrendering",
            "or fleeing. You give orders for generous quarter to be given,",
            "and search out Severus. You find him dead, a slave having assisted",
            "him in suicide. You feel yourself breathe a sigh of relief, and",
            "realize that you are now Caesar! And as you realize that, the relief",
            "turns to a new anxiety. The game for the throne might be over, but",
            "how long will you keep it?"
        });
    } else if (gameState.currentPhase == defeat) {
        print_message({
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