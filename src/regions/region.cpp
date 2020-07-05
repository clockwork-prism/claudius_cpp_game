#include "region.h"

void read_vec_strings(std::ifstream &file, std::vector<std::string> &vec, std::string endFlag) {
    std::string currentLine{};
    while (true) {
        std::getline(file, currentLine);
        if (currentLine == endFlag) {
            break;
        } else {
            vec.push_back(currentLine);
        }
    };
}

Region::Region(Army _local_army) : local_army{_local_army} {}

Region::Region(std::string file_name): local_army{0, eBeginning, 0}, move_menu{} {
    std::string line {};
    std::vector<std::string> temp {};
    std::string line_2 {};

    std::ifstream in_file;
    in_file.open(file_name);
    if (in_file) {
        try{
        while(std::getline(in_file, line)) {
            if (line == "#MES") {
                read_vec_strings(in_file, temp, "#ENDMES");
                this->messages.push_back(temp);
                temp.clear();
            } else if (line == "#PROMPT") {
                read_vec_strings(in_file, temp, "#ENDPROMPT");
                this->move_menu.set_prompt(temp);
                temp.clear();
            } else if (line == "#CHOICES") {
                std::vector<char> choices;
                std::getline(in_file, line_2);
                for (auto c: line_2)
                    choices.push_back(c);
                this->move_menu.set_valid_choices(choices);
                std::getline(in_file, line_2); //Clears #ENDCHOICES flag
            } else if (line == "#ARMY") {
                int size{};
                std::string loc {};
                int reputation{};
                in_file >> size >> loc >> reputation;
                
                Location location = string_to_loc(loc);

                this->local_army.size = size;
                this->local_army.location = location;
                this->local_army.reputation = reputation;
            }
        }
        } catch (InvalidRegionFile &ex) {
            std::cerr << ex.what() << file_name << std::endl;
        }
        in_file.close();
    } else {
        throw FileNotFoundError(file_name);
    }
}

bool Region::army_joins_claudius(Army &claudius) {
    if (claudius.reputation >= this->local_army.reputation) {
        claudius += this->local_army;
        this->local_army.size = 0;
        return true;
    }
    return false;
}

void Region::update_message(std::vector<std::string> &out_message, int index) {
    out_message.insert(out_message.end(), this->messages.at(index).begin(), this->messages.at(index).end());
}