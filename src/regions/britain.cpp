#include "britain.h"

Britain::Britain(Army _local_army) : Region{_local_army} {
    messages = {
        {
            "Your reputation precedes you, and the men of the British",
            "legions flock to your banner!"
        },
        {
            "While not in a hurry to challenge you, the British legions",
            "will not aid your cause. Maybe if you can increase your reputation",
            "somehow they will join."
        },
        {
            "The British isles are never quite peaceful, and it would be",
            "dangerous to pull away any more men from the garrison. Best",
            "head back to the mainland soon."
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

std::tuple<std::vector<std::string>, Phase> Britain::location_events(Army &claudius) {
    std::vector<std::string> out_message{};
    if (this->local_army.size > 0) {
        if (army_joins_claudius(claudius)) {
            out_message.insert(out_message.end(), this->messages.at(0).begin(), this->messages.at(0).end());
        } else {
            out_message.insert(out_message.end(), this->messages.at(1).begin(), this->messages.at(1).end());
        }
    } else {
        out_message.insert(out_message.end(), this->messages.at(2).begin(), this->messages.at(2).end());
    }
    return std::make_tuple(out_message, Phase::playing);
}