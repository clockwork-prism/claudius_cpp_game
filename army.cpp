#include "army.h"

Army operator+(const Army &lhs, const Army &rhs) {
    Army out{lhs.size, lhs.location, lhs.reputation};
    out.size += rhs.size;
    return out;
}

Army operator+(const Army &lhs, const int &rhs) {
    Army out{lhs.size, lhs.location, lhs.reputation};
    out.size += rhs;
    return out;
}

Army operator+(const Army &lhs, const int &&rhs) {
    Army out{lhs.size, lhs.location, lhs.reputation};
    out.size += rhs;
    return out;    
}

Army &Army::operator+=(const Army &rhs) {
    *this = *this + rhs;
    return *this;
}
Army &Army::operator+=(const int &rhs) {
    *this = *this + rhs;
    return *this;
}
Army &Army::operator+=(const int &&rhs) {
    *this = *this + rhs;
    return *this;
}

Army operator-(const Army &lhs, const Army &rhs) {
    Army out{lhs.size, lhs.location, lhs.reputation};
    out.size -= rhs.size;
    return out;
}

Army operator-(const Army &lhs, const int &rhs) {
    Army out{lhs.size, lhs.location, lhs.reputation};
    out.size -= rhs;
    return out;
}

Army operator-(const Army &lhs, const int &&rhs) {
    Army out{lhs.size, lhs.location, lhs.reputation};
    out.size -= rhs;
    return out;    
}

Army &Army::operator-=(const Army &rhs) {
    *this = *this - rhs;
    return *this;
}
Army &Army::operator-=(const int &rhs) {
    *this = *this - rhs;
    return *this;
}
Army &Army::operator-=(const int &&rhs) {
    *this = *this - rhs;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Army &rhs) {
    os << "\nArmy: " << rhs.size << ", Reputation: ";
    os << (
        (rhs.reputation == 0) ? "Unkown"   : 
        (rhs.reputation == 1) ? "Renowned" : 
                                "Exalted"
    );
    return os;
}