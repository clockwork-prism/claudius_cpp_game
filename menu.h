#ifndef _MENU_H_
#define _MENU_H_

#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include "utils.h"

class Menu {
private:
    std::vector <std::string> prompt;
    std::vector <char> validChoices;
public:
    Menu();
    ~Menu();
    char get_user_input();
    void set_prompt(std::vector <std::string> newPrompt) {prompt = newPrompt;}
    void set_valid_choices(std::vector <char> newChoices) {validChoices = newChoices;}
};

#endif