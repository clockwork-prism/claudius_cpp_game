#include "gaul.h"

Gaul::Gaul() {
    pBarbariansInvaded = new int {0};

    messages = std::vector<std::vector<std::string>> {
        {
            "You descend on Gaul and fan out your forces to confront the",
            "invaders. You lose some men, but your reputation grows higher!",
            "\nAs your army recovers, you weigh your options. To the south is",
            "Italy where Severus waits with his army.",
            "The Danube is to the east, legions there have no love for the",
            "emperor. To the west is Iberia, currently not garrisoned. And",
            "to the north lies Britain. The legions there may be more",
            "hesitant to follow an unkown."
        }, 
        {
            "The familiar land of Gaul surrounds you. To the south is Italy",
            "where Severus waits with his army.",
            "The Danube is to the east, legions there have no love for the",
            "emperor. To the west is Iberia, currently not garrisoned. And",
            "to the north lies Britain. The legions there may be more",
            "hesitant to follow an unkown."
        }
    };

    move_menu = Menu();

    move_menu.set_prompt({
        "\nWhere will you go?",
        "B - Britain",
        "D - Danube",
        "I - Italy",
        "E - Iberia",
        "Q - Quit the game"
    });

    move_menu.set_valid_choices({'B', 'D', 'I', 'E', 'Q'});

    local_army = Army{2000, eGaul, 1};
}

Gaul::~Gaul() {
    delete pBarbariansInvaded;
}

std::vector<std::string> Gaul::location_events(Army &claudius) {
    int out_index {1};
    if (*(this->pBarbariansInvaded) == 1) {
        this->goth_battle(claudius);
        out_index = 0;
    }
    return messages.at(out_index);
}

void Gaul::goth_battle(Army &claudius) {
    claudius -= this->local_army;
    claudius.reputation += this->local_army.reputation;
    this->local_army.size = 0;
    *(this->pBarbariansInvaded) = 2;
}