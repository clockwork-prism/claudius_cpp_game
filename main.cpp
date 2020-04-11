#include <iostream>
#include <array>

using namespace std;

int main() {
    
    array <string, 5> titleScreen {
        " ------------------------------------------------------------ ",
        "|                                                            |",
        "|             Claudius: Praetorian Prefect                   |",
        "|                                                            |",
        " ------------------------------------------------------------ "
    };

    cout << titleScreen.at(0) << endl;
    cout << titleScreen.at(1) << endl;
    cout << titleScreen.at(2) << endl;
    cout << titleScreen.at(3) << endl;
    cout << titleScreen.at(4) << endl;

    cout << "\nEnter 1 to start the game, 2 to exit." << endl;
    int choice;
    cin >> choice;
    cout << "You have selected " << choice << ".\n" << endl;

    titleScreen.at(2) = "|              Then let the games begin...                   |";

    cout << titleScreen.at(0) << endl;
    cout << titleScreen.at(1) << endl;
    cout << titleScreen.at(2) << endl;
    cout << titleScreen.at(3) << endl;
    cout << titleScreen.at(4) << endl;

    return 0;
}