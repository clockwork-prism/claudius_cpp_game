#include <iostream>

using namespace std;

int main() {

    const string frameTopOrBottom {" ------------------------------------------------------------ \n"};
    const string frameMiddleEmpty {"|                                                            |\n"};

    string frameMiddle0 {"|             Claudius: Praetorian Prefect                   |\n"};

    cout << frameTopOrBottom;
    cout << frameMiddleEmpty;
    cout << frameMiddle0;
    cout << frameMiddleEmpty;
    cout << frameTopOrBottom;

    cout << "\nEnter 1 to start the game, 2 to exit." << endl;
    int choice;
    cin >> choice;
    cout << "You have selected " << choice << ".";

    return 0;
}