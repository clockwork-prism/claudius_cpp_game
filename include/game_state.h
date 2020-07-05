#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include <vector>
#include <string>
#include "menu.h"
#include "army.h"
#include "world.h"

class GameState {
private:
    World world;

public:
    GameState(Army claudius_, Army british_, Army danube_, Army goths_, Army severus_, int defectionSize_);
    GameState(std::string file_name);
    Army claudius;
    
    std::shared_ptr<Region> currentRegion;
    Phase currentPhase;
    char choice;

    void reputation_gained(int rep) {claudius.reputation += rep;}
    Location get_claudius_loc() {return claudius.location;}
    void move_location();
    void print_stats();
};

#endif //_GAMESTATE_H_