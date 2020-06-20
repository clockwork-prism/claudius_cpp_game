#include "menu.h"

Menu::Menu(): validChoices{}, prompt{} {

}

Menu::~Menu() {

}

char Menu::get_user_input() {
    char choice {};
    do {
        print_message(prompt);
        std::cin >> choice;
        if (std::islower(choice))
            choice = std::toupper(choice);
    } while (!char_in_vector(choice, validChoices));
    return choice;
}
