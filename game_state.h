#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <vector>
#include <string>

enum Phase {starting, playing, victory, defeat};
enum Location {Iberia, Britain, Gaul, Danube, Italy, Beginning};

struct GameState {

    char choice {'G'};

    int ClaudiusRep {0};

    Phase phase {starting};

    std::vector <std::string> titleScreen {
        " ------------------------------------------------------------ ",
        "|                                                            |",
        "|             Claudius: Praetorian Prefect                   |",
        "|                                                            |",
        " ------------------------------------------------------------ "
    };
    std::string sceneBreak {"\n==============================================================\n\n"};
    std::vector <std::string> message {};
    std::vector <std::string> detailedChoices {};
    std::vector <char> validChoices {};

    Location ClaudiusLoc {Beginning};

    int ClaudiusArmySize {10000};
    int SeverusArmySize {12000};

    int DanubeLegions {5000};
    int BritishLegions {5000};

    int BarbariansInvaded {0};
};

#endif //_GAMESTATE_H_