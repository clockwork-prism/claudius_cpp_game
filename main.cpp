#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include "funcs.h"
#include "utils.h"

using namespace std;

// Global Variables

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