#ifndef _utils_H_
#define _utils_H_

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

static const std::string END_MESSAGE {"END_MESSAGE"};

template <typename T, typename I>
bool char_in_vector(const T item, const I &v) {
    auto it = std::find(v.begin(), v.end(), item);
    if (it == v.end())
        return false;
    return true;
}

template <typename T>
void print_message(const std::vector <T> &message) {
    for (const auto &s: message) {
        std::cout << s << std::endl;
    }
}

enum Phase {starting, playing, victory, defeat};

#endif