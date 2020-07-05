#ifndef _ARMY_H_
#define _ARMY_H_

#include <iostream>
#include <exception>

enum Location {eIberia, eBritain, eGaul, eDanube, eItaly, eBeginning};

Location string_to_loc (std::string &loc);

class InvalidLocationError : public std::runtime_error {
    public:
        InvalidLocationError(std::string message) : std::runtime_error{message} {}
};

struct Army {
    int size;
    Location location;
    int reputation;

    Army &operator+=(const Army &rhs);
    Army &operator+=(const int &rhs);
    Army &operator+=(const int &&rhs);

    Army &operator-=(const Army &rhs);
    Army &operator-=(const int &rhs);
    Army &operator-=(const int &&rhs);
};

Army operator+(const Army &lhs, const Army &rhs);
Army operator+(const Army &lhs, const int &rhs);
Army operator+(const Army &lhs, const int &&rhs);

Army operator-(const Army &lhs, const Army &rhs);
Army operator-(const Army &lhs, const int &rhs);
Army operator-(const Army &lhs, const int &&rhs);

std::ostream &operator<<(std::ostream &os, const Army &rhs);

#endif