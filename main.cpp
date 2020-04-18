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
    string sceneBreak {"\n==============================================================\n\n"};

    cout << titleScreen.at(0) << endl;
    cout << titleScreen.at(1) << endl;
    cout << titleScreen.at(2) << endl;
    cout << titleScreen.at(3) << endl;
    cout << titleScreen.at(4) << endl << endl;
          // --------------------------------------------------------------
    cout << "Standing in a field of victory, you survey your tired army." << endl;
    cout << "Victorious over the Gothic invaders, your men begin to ask" << endl;
    cout << "why the emperor, Severus, sits in Rome while you are the one" << endl;
    cout << "defending the empire. They come to you now, and proclaim you" << endl;
    cout << "Augustus! How do you respond?" << endl << endl;
    cout << "1 - \"I accept! Let us march on Rome.\"" << endl;
    cout << "2 - \"I cannot, I am unworthy.\"" << endl;
    cout << "Your choice: ";
    
    int choice;
    cin >> choice;

    cout << sceneBreak;
    if (choice == 1) {
        cout << "Then let the games begin..." << endl;
    } 
    else {
               //--------------------------------------------------------------
        cout << "Your men are displeased, but accept your humility. Another day" << endl;
        cout << "perhaps..." << endl;
    }
    return 0;
}