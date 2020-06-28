#include "danube.h"

Danube::Danube(Army _local_army) : Region{_local_army} {
    messages = {
        {
            "The Danube legions are overjoyed to hear someone wants to kill",
            "Severus. Some of your officers are a little concerned at this",
            "quick turn around, but you need all the forces you can muster."
        },
        {
            "You stare at the Danube, for the moment lost in thought. Which",
            "river has seen more violence? The Rhine or the Danube? Staring at",
            "the far bank, you decide it's best to move on rather than recruit",
            "any more men."
        }
    };

    move_menu = Menu();
    move_menu.set_prompt({
        "\nWhere will you go?",
        "G - Gaul",
        "I - Italy",
        "Q - Quit the game"
    });
    move_menu.set_valid_choices({'G', 'I', 'Q'});

    local_army = Army{5000, eBritain, 1};
}

std::tuple<std::vector<std::string>, Phase> Danube::location_events(Army &claudius) {
    int out_index {1};
    if (this->local_army.size > 0) {
        out_index = 0;
        army_joins_claudius(claudius);
    } 
    return std::make_tuple(this->messages.at(out_index), Phase::playing);
}