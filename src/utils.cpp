#include "utils.h"


bool char_in_vector(const char item, const std::vector<char> &v) {
    for (auto c: v) {
        if (c == item) {
            return true;
        }
    }
    return false;
}

void print_message(const std::vector <std::string> &message) {
    for (const auto &s: message) {
        std::cout << s << std::endl;
    }
}