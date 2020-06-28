#ifndef _utils_H_
#define _utils_H_

#include <vector>
#include <string>
#include <iostream>

static const std::string END_MESSAGE {"END_MESSAGE"};

bool char_in_vector(const char item, const std::vector<char> &v);
void print_message(const std::vector <std::string> &message);

enum Phase {starting, playing, victory, defeat};

#endif