#include "iberia.h"

Iberia::Iberia(Army _local_army, std::shared_ptr<int> _bi) : Region{_local_army}  {
    pBarbariansInvaded = _bi;

    messages = {
        {
            "As you make camp in Iberia just beyond the mountains",
            "you receive dire news. Barbarians have invaded Gaul!",
            "This is a great misfortune, though a fresh victory",
            "may bring more renown..."
        },
        {
            "The Iberian peninsula is mercifully peaceful. You briefly",
            "allow yourself to think about quiet retirement, but the",
            "the war beckons."
        }
    };
    move_menu = Menu();
    move_menu.set_prompt({
            "\nWhere will you go?",
            "G - Gaul",
            "Q - Quit the game"
    });
    move_menu.set_valid_choices({'G', 'Q'});
}

Iberia::Iberia(std::string file_name, std::shared_ptr<int> bi_) : Region{file_name}, pBarbariansInvaded{bi_} {}

std::tuple<std::vector<std::string>, Phase> Iberia::location_events(Army &claudius) {
    int out_index {1};
    if (*(this->pBarbariansInvaded) == 0) {
        out_index = 0;
        *(this->pBarbariansInvaded) = 1;
    } 
    return std::make_tuple(this->messages.at(out_index), Phase::playing);
}