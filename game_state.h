#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <vector>
#include <string>
#include "menu.h"
#include "army.h"

enum Phase {starting, playing, victory, defeat};

class GameState {
private:
    Army claudius;
    Army britishLegions;
    Army danubeLegions;
    Army goths;
    Army severus;
    std::vector <std::string> message;
    int defectionSize;

public:
    GameState(Army claudius_, Army british_, Army danube_, Army goths_, Army severus_, int defectionSize_);

    Phase currentPhase;
    Menu menu;
    int barbariansInvaded;
    char choice;

    void display_message() {print_message(message);}
    void clear_message() {message.clear();}
    void update_message(std::vector <std::string> newMessage) {
        message.insert(message.end(), newMessage.begin(), newMessage.end());
    }
    void reputation_gained(int rep) {claudius.reputation += rep;}
    bool danube_garrisoned() {return danubeLegions.size > 0;}
    bool britain_garrisoned() {return britishLegions.size > 0;}
    Location get_claudius_loc() {return claudius.location;}
    void move_location();
    bool danube_joins_claudius();
    bool british_joins_claudius();
    void goth_battle();
    void print_stats();
    bool severus_defects();
    void severus_battle();
};

#endif //_GAMESTATE_H_