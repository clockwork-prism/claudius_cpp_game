#include "world.h"

World::World() {
    pBarbariansInvaded = std::make_shared<int>(0);

    gaul = std::make_shared<Gaul>("assets/gaul.reg", pBarbariansInvaded);
    danube = std::make_shared<Danube>("assets/danube.reg");
    iberia = std::make_shared<Iberia>("assets/iberia.reg", pBarbariansInvaded);
    italy = std::make_shared<Italy>("assets/italy.reg");
    britain = std::make_shared<Britain>("assets/britain.reg");
    beginning = std::make_shared<Beginning> ();

    this->load_map("assets/europe_labeled.asc");
}

void World::load_map(std::string file_name) {
    std::ifstream file;
    file.open(file_name);
    if (file) {
        std::string line;
        this->map.clear();
        while (std::getline(file, line)) {
            this->map.push_back(line);
        }
    } else throw FileNotFoundError(file_name);
}

void World::display_map(const Army &claudius) {
    std::vector<std::string> temp_map{};
    temp_map = this->map;

    int crow;
    int ccol;
    switch (claudius.location) {
        case eGaul:
            crow = 7;
            ccol = 19;
            break;
        case eBritain:
            crow = 2;
            ccol = 12;
            break;
        case eIberia:
            crow = 13;
            ccol = 2;
            break;
        case eDanube:
            crow = 9;
            ccol = 42;
            break;
        case eItaly:
            crow = 13;
            ccol = 32;
            break;
        default:
            crow = 0;
            ccol = 0;
    }

    this->place_on_map(temp_map, this->britain->get_army_size(), 'B', 1, 12);
    this->place_on_map(temp_map, this->italy->get_army_size(), 'S', 12, 32);
    this->place_on_map(temp_map, this->danube->get_army_size(), 'D', 8, 42);
    if (*(this->pBarbariansInvaded) == 1) {
        this->place_on_map(temp_map, this->gaul->get_army_size(), 'G', 7, 19);
        if (claudius.location == eGaul) {
            crow++;
            ccol++;
        }
    }
    this->place_on_map(temp_map, claudius.size, 'C', crow, ccol);

    print_message(temp_map);
}

void World::place_on_map(std::vector<std::string> &tmap, int size, char label, int row, int col) {
    std::string s_size {std::to_string(size)};
    tmap.at(row).at(col++) = '[';
    tmap.at(row).at(col++) = label;
    tmap.at(row).at(col++) = ':';
    tmap.at(row).at(col++) = ' ';
    for (auto c: s_size) {
        tmap.at(row).at(col++) = c;
    }
    tmap.at(row).at(col) = ']';
}
