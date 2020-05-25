#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

// Forward declarations

void print_message(const vector <string> &message);
void get_choice();
void game_start();
void print_stats();
void main_game_loop();
void process_location_events();
void gaul_loc_events();
void move_loc();
void iberia_loc_events();
void briain_loc_events();
void danube_loc_events();
void italy_loc_events();
void game_end();

// Global Variables

enum Location {Iberia, Britain, Gaul, Danube, Italy, Beginning};
enum GameState {starting, playing, victory, defeat};

char choice {'G'};

int ClaudiusRep {0};

GameState state {starting};

vector <string> titleScreen {
    " ------------------------------------------------------------ ",
    "|                                                            |",
    "|             Claudius: Praetorian Prefect                   |",
    "|                                                            |",
    " ------------------------------------------------------------ "
};
string sceneBreak {"\n==============================================================\n\n"};
vector <string> message {};
vector <string> detailedChoices {};
vector <char> validChoices {};

Location ClaudiusLoc {Beginning};

int ClaudiusArmySize {10000};
int SeverusArmySize {12000};

int DanubeLegions {5000};
int BritishLegions {5000};

int BarbariansInvaded {0};


// ***************************************************************************************

int main() {

    print_message(titleScreen);

    do {
        main_game_loop();
    } while (choice != 'Q' && (state == playing || state == starting));

    game_end();

    return 0;
}

// ***************************************************************************************





void get_choice() {
    print_message(detailedChoices);
    do {
        cout << "Your choice: ";
        cin >> choice;
        if (islower(choice));
            choice = toupper(choice);
    } while (!char_in_vector(choice, validChoices));
}

void print_stats() {
    cout << "\nArmy: " << ClaudiusArmySize << ", Reputation: ";
    cout << ((ClaudiusRep == 0) ? "Unkown"   : 
             (ClaudiusRep == 1) ? "Renowned" : 
                                  "Exalted") << endl;
}

void main_game_loop() {
    message.clear();
    validChoices.clear();
    detailedChoices.clear();
    cout << sceneBreak;
    process_location_events();
    print_message(message);
    if (state == playing && choice != 'Q') {
        print_stats();
        get_choice();
        move_loc();
    }
}

void game_start() {
    print_message({
        "Standing in a field of victory, you survey your tired army.",
        "Victorious over the Gothic invaders, your men begin to ask",
        "why the emperor, Severus, sits in Rome while you are the one",
        "defending the empire. They come to you now, and proclaim you",
        "Augustus! How do you respond?"
    });

    detailedChoices = {
        "1 - \"I accept!\"",
        "2 - \"I cannot, I am unworthy.\""
    };
    validChoices = {'1', '2'};

    get_choice();

    cout << sceneBreak;

    if (choice == '1') {
        message = {"Then let the games begin..."};     
    } else {
        message = {
            "Your humility is an example to all, and your reputation grows!",
            "But soon the men approach again, they insist you must accept",
            "the throne. Relenting, you agree to lead them."
        };
        ClaudiusRep += 1;
    }
    ClaudiusLoc = Gaul;
}

void process_location_events() {
    switch (ClaudiusLoc) {
        case Beginning: {
            game_start();
            break;
        }
        case Gaul:{
            gaul_loc_events();
            break;
        }
        case Iberia: {
            iberia_loc_events();
            break;
        }
        case Britain: {
            briain_loc_events();
            break;
        }
        case Danube: {
            danube_loc_events();
            break;
        }
        case Italy: {
            italy_loc_events();
            break;
        }
        default:
            break;
    }
}

void move_loc() {
    switch (choice) {
        case 'Z': {
            ClaudiusLoc = Beginning;
            break;
        }
        case 'B': {
            ClaudiusLoc = Britain;
            break;
        }
        case 'I': {
            ClaudiusLoc = Italy;
            break;
        }
        case 'G': {
            ClaudiusLoc = Gaul;
            break;
        }
        case 'E': {
            ClaudiusLoc = Iberia;
            break;
        }
        case 'D': {
            ClaudiusLoc = Danube;
            break;
        }
        case 'Q':{
            cout << "So that's it? Maybe you were not meant to be" << endl;
            cout << "the Augustus after all..." << endl;
        }
        default:
            break;
    }
}

void gaul_loc_events() {
    state = playing;
    message.clear();
    if (BarbariansInvaded == 1) {
        ClaudiusRep += 1;
        ClaudiusArmySize -= 2000;
        BarbariansInvaded = 2;
        message = {
            "You descend on Gaul and fan out your forces to confront the",
            "invaders. You lose some men, but your reputation grows higher!\n"
        };
    }

    message.insert(message.end(), {
        "The familiar land of Gaul surrounds you. To the south is Italy",
        "where Severus waits with his army of " + to_string(SeverusArmySize) + " men.",
        "The Danube is to the east, legions there have no love for the",
        "emperor. To the west is Iberia, currently not garrisoned. And",
        "to the north lies Britain. The legions there may be more",
        "hesitant to follow an unkown."
    });

    detailedChoices = {
        "\nWhere will you go?",
        "B - Britain",
        "D - Danube",
        "I - Italy",
        "E - Iberia",
        "Q - Quit the game"
    };

    validChoices = {'B', 'D', 'I', 'E', 'Q'};
}


void iberia_loc_events() {
    if (BarbariansInvaded == 0) {
        message = {
            "As you make camp in Iberia just beyond the mountains",
            "you receive dire news. Barbarians have invaded Gaul!",
            "This is a great misfortune, though a fresh victory",
            "may bring more renown..."
        };
        BarbariansInvaded = 1;
    } else {
        message = {
            "The Iberian peninsula is mercifully peaceful. You briefly",
            "allow yourself to think about quiet retirement, but the",
            "the war beckons."
        };
    }
    detailedChoices = {
            "\nWhere will you go?",
            "G - Gaul",
            "Q - Quit the game"
    };
    validChoices = {'G', 'Q'};
}


void briain_loc_events() {
    if (BritishLegions > 0) {
        if (ClaudiusRep > 0) {
            message = {
                "Your reputation precedes you, and the men of the British",
                "legions flock to your banner!"
            };
            ClaudiusArmySize += BritishLegions;
            BritishLegions = 0;
        } else {
            message = {
                "While not in a hurry to challenge you, the British legions",
                "will not aid your cause. Maybe if you can increase your reputation",
                "somehow they will join."
            };
        }
    } else {
        message = {
            "The British isles are never quite peaceful, and it would be",
            "dangerous to pull away any more men from the garrison. Best",
            "head back to the mainland soon."
        };
    }
    detailedChoices = {
        "\nWhere will you go?",
        "G - Gaul",
        "Q - Quit the game"
    };
    validChoices = {'G', 'Q'};
}

void danube_loc_events() {
    if (DanubeLegions > 0) {
        message = {
            "The Danube legions are overjoyed to hear someone wants to kill",
            "Severus. Some of your officers are a little concerned at this",
            "quick turn around, but you need all the forces you can muster."
        };
        ClaudiusArmySize += DanubeLegions;
        DanubeLegions = 0;
    } else {
        message = {
            "You stare at the Danube, for the moment lost in thought. Which",
            "river has seen more violence? The Rhine or the Danube? Staring at",
            "the far bank, you decide it's best to move on rather than recruit",
            "any more men."
        };
    }
    detailedChoices = {
        "\nWhere will you go?",
        "G - Gaul",
        "I - Italy",
        "Q - Quit the game"
    };
    validChoices = {'G', 'I', 'Q'};
}

void italy_loc_events() {
    message = {
        "The crossing of the Alps is as smooth as it can be, Severus",
        "is not waiting for you on the other side. Reports are he is",
        "further south. You pause at the Rubicon to make camp, a part",
        "of you amused to think of yourself as Julius himself. The next",
        "day, the scouts report in. Severus approaches. You form up for",
        "battle."
    };
    if (ClaudiusRep > 1) {
        message.insert(message.end(), {
            "You're exploits have reached the people of Rome, and",
            "now Severus's armies begin to abandon him! Your ranks swell",
            "but will it be enough?"
        });
        ClaudiusArmySize += 2500;
        SeverusArmySize -= 2500;
    }
    if (ClaudiusArmySize > SeverusArmySize) {
        state = victory;
    } else {
        state = defeat;
    }
}

void game_end() {
    cout << sceneBreak;
    if (state == victory) {
        print_message({
            "As the dust clears, you see Severus's army either surrendering",
            "or fleeing. You give orders for generous quarter to be given,",
            "and search out Severus. You find him dead, a slave having assisted",
            "him in suicide. You feel yourself breathe a sigh of relief, and",
            "realize that you are now Caesar! And as you realize that, the relief",
            "turns to a new anxiety. The game for the throne might be over, but",
            "how long will you keep it?"
        });
    } else if (state == defeat) {
        print_message({
            "You stare in stunned silence as first the left flank collapses,",
            "then the right. Your center backs up trying to prevent a gap in the",
            "line, but this soon becomes a route. Your whole army is in flight, and",
            "a merciless Severus deploys the light cavalry to cut down fleeing",
            "soldiers. You try to rally the men, but a thrown spear strikes you in the",
            "throat. So ends the tragic tale of Claudius."
        });
    }

    cout << sceneBreak;
    cout << "GAME OVER" << endl;
    cout << sceneBreak;
}