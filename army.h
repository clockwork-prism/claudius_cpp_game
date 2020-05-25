#ifndef _ARMY_H_
#define _ARMY_H_

enum Location {Iberia, Britain, Gaul, Danube, Italy, Beginning};

struct Army {
    int size;
    Location location;
    int reputation;
}

#endif