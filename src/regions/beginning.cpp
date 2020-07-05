#include "beginning.h"

Beginning::Beginning(Army _local_army) : Region{_local_army} {
    move_menu = Menu();
    move_menu.set_prompt({
        "1 - \"I accept!\"",
        "2 - \"I cannot, I am unworthy.\""
    });
    move_menu.set_valid_choices({'1', '2'});

    messages = {
        {
            "Standing in a field of victory, you survey your tired army.",
            "Victorious over the Gothic invaders, your men begin to ask",
            "why the emperor, Severus, sits in Rome while you are the one",
            "defending the empire. They come to you now, and proclaim you",
            "Augustus! How do you respond?"
        },
        {
            "Then let the games begin..."
        },
        {
            "Your humility is an example to all, and your reputation grows!",
            "But soon the men approach again, they insist you must accept",
            "the throne. Relenting, you agree to lead them."
        }

    };
}

Beginning::Beginning(std::string file_name) : Region{file_name} {
    
}

std::tuple<std::vector<std::string>, Phase> Beginning::location_events(Army &claudius) {
    print_message(this->messages.at(0));

    char choice = this->move_menu.get_user_input();
    std::vector<std::string> out_message{};

    std::cout << "\n\n";

    if (choice == '1') {
        this->update_message(out_message, 1);     
    } else {
        this->update_message(out_message, 2);  
        claudius.reputation += 1;
    }
    return std::make_tuple(out_message, starting);
}