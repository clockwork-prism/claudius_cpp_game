#include "italy.h"
#include "utils.h"

Italy::Italy(Army _local_army, int defectionSize_) : Region{_local_army}, defectionSize{defectionSize_} {
    messages = {
        {
            "The crossing of the Alps is as smooth as it can be, Severus",
            "is not waiting for you on the other side. Reports are he is",
            "further south. You pause at the Rubicon to make camp, a part",
            "of you amused to think of yourself as Julius himself. The next",
            "day, the scouts report in. Severus approaches. You form up for",
            "battle."
        },
        {
            "You're exploits have reached the people of Rome, and",
            "now Severus's armies begin to abandon him! Your ranks swell",
            "but will it be enough?"
        }
    };

    local_army = Army {12000, eItaly, 2};
}

Italy::Italy(std::string file_name) : Region(file_name), defectionSize{} {
    std::ifstream file;
    file.open(file_name);
    if (file) {
        std::string line{};
        while (std::getline(file, line)) {
            if (line == "#DEFECTIONSIZE") {
                file >> this->defectionSize;
                break;
            }
        }
    } else throw FileNotFoundError(file_name);
    file.close();
}

std::tuple<std::vector<std::string>, Phase> Italy::location_events(Army &claudius) {
    std::vector<std::string> out_message{};
    out_message = this->messages.at(0);
    if (this->army_joins_claudius(claudius)) {
        out_message.insert(out_message.end(), this->messages.at(1).begin(), this->messages.at(1).end());;
    }
    Phase out_phase = this->severus_battle(claudius);
    return std::make_tuple(out_message, out_phase);
}

Phase Italy::severus_battle(Army &claudius) {
    if (claudius.size > this->local_army.size) {
        return Phase::victory;
    } else {
        return Phase::defeat;
    }
}

bool Italy::army_joins_claudius(Army &claudius) {
    if (claudius.reputation >= this->local_army.reputation) {
        claudius += this->defectionSize;
        this->local_army -= this->defectionSize;
        return true;
    }
    return false;
}