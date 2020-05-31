#ifndef _ARMY_H_
#define _ARMY_H_

#include <iostream>

enum Location {Iberia, Britain, Gaul, Danube, Italy, Beginning};

struct Army {
    int size;
    Location location;
    int reputation;

    Army &operator+=(const Army &rhs);
    Army &operator+=(const int &rhs);
    Army &operator+=(const int &&rhs);
};

Army operator+(const Army &lhs, const Army &rhs);
Army operator+(const Army &lhs, const int &rhs);
Army operator+(const Army &lhs, const int &&rhs);

std::ostream &operator<<(std::ostream &os, const Army &rhs);

#endif