#include <iostream>
#include <array>
#include <cctype>
#include <string>

using namespace std;

int main() {
    enum Location {Iberia, Britain, Gaul, Danube, Italy};
    Location ClaudiusLoc {Gaul};

    int ClaudiusArmySize {10000};
    int SeverusArmySize {12000};
    int DanubeLegions {5000};
    int BritishLegions {5000};
    int ClaudiusRep {0};
    int BarbariansInvaded {0};
    enum GameState {playing, victory, defeat};
    GameState state = playing;
    
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
    cout << "1 - \"I accept!\"" << endl;
    cout << "2 - \"I cannot, I am unworthy.\"" << endl;
    cout << "Your choice: ";
    
    char choice;
    cin >> choice;

    cout << sceneBreak;
    if (choice == '1') {
        cout << "Then let the games begin..." << endl;
        
    } else {
               //--------------------------------------------------------------
        cout << "Your humility is an example to all, and your reputation grows!" << endl;
        cout << "But soon the men approach again, they insist you must accept" << endl;
        cout << "the throne. Relenting, you agree to lead them." << endl;

        ClaudiusRep += 1;
    }
    do {
        cout << sceneBreak;
        switch (ClaudiusLoc) {
            case Gaul:{
                       //--------------------------------------------------------------
                if (BarbariansInvaded == 1) {
                    ClaudiusRep += 1;
                    ClaudiusArmySize -= 2000;
                    BarbariansInvaded = 2;
                    cout << "You descend on Gaul and fan out your forces to confront the" << endl;
                    cout << "invaders. You lose some men, but your reputation grows higher!" << endl;
                    cout << sceneBreak;
                }
                cout << "The familiar land of Gaul surrounds you. To the south is Italy" << endl;
                cout << "where Severus waits with his army of " << SeverusArmySize << " men." << endl;
                cout << "The Danube is to the east, legions there have no love for the" << endl;
                cout << "emperor. To the west is Iberia, currently not garrisoned. And" << endl;
                cout << "to the north lies Britain. The legions there may be more" << endl;
                cout << "hesitant to follow an unkown." << endl;
                do {
                    cout << "\nArmy: " << ClaudiusArmySize << ", Reputation: ";
                    cout << ((ClaudiusRep == 0) ? "Unkown" : 
                             (ClaudiusRep == 1) ? "Renowned" : 
                                                  "Exalted") << endl;
                    cout << "\nWhere will you go?" << endl;
                    cout << "B - Britain" << endl;
                    cout << "D - Danube" << endl;
                    cout << "I - Italy" << endl;
                    cout << "E - Iberia" << endl;
                    cout << "Q - Quit the game" << endl;
                    cout << "\nYour choice: ";
                    cin >> choice;
                    choice = toupper(choice);
                } while (choice != 'B' && choice != 'D' && choice != 'I' && choice != 'E' && choice != 'Q');
                break;
            }
            case Iberia: {
                if (BarbariansInvaded == 0) {
                    cout << "As you make camp in Iberia just beyond the mountains," << endl;
                    cout << "you receive dire news. Barbarians have invaded Gaul!" << endl;
                    cout << "This is a great misfortune, though a fresh victory" << endl;
                    cout << "may bring more renown..." << endl;
                    BarbariansInvaded = 1;
                } else {
                    cout << "The Iberian peninsula is mercifully peaceful. You briefly" << endl;
                    cout << "allow yourself to think about quiet retirement, but the" << endl;
                    cout << "the war beckons." << endl;
                }
                do {
                    cout << "\nArmy: " << ClaudiusArmySize << ", Reputation: ";
                    cout << ((ClaudiusRep == 0) ? "Unkown" : 
                             (ClaudiusRep == 1) ? "Renowned" : 
                                                  "Exalted") << endl;
                    cout << "\nWhere will you go?" << endl;
                    cout << "G - Gaul" << endl;
                    cout << "Q - Quit the game" << endl;
                    cout << "\nYour choice: ";
                    cin >> choice;
                    choice = toupper(choice);
                } while (choice != 'G' && choice != 'Q');
                break;
            }
            case Britain: {
                if (BritishLegions > 0) {
                    if (ClaudiusRep > 0) {
                        cout << "Your reputation precedes you, and the men of the British" << endl;
                        cout << "legions flock to your banner!" << endl;
                        ClaudiusArmySize += BritishLegions;
                        BritishLegions = 0;
                    } else {
                        cout << "While not in a hurry to challenge you, the British legions" << endl;
                        cout << "will not aid your cause. Maybe if you can increase your reputation" << endl;
                        cout << "somehow they will join." << endl;
                    }
                } else {
                    cout << "The British isles are never quite peaceful, and it would be" << endl;
                    cout << "dangerous to pull away any more men from the garrison. Best" << endl;
                    cout << "head back to the mainland soon." << endl;
                }
                do {
                    cout << "\nArmy: " << ClaudiusArmySize << ", Reputation: ";
                    cout << ((ClaudiusRep == 0) ? "Unkown" : 
                             (ClaudiusRep == 1) ? "Renowned" : 
                                                  "Exalted") << endl;
                    cout << "\nWhere will you go?" << endl;
                    cout << "G - Gaul" << endl;
                    cout << "Q - Quit the game" << endl;
                    cout << "\nYour choice: ";
                    cin >> choice;
                    choice = toupper(choice);
                } while (choice != 'G' && choice != 'Q');
                break;
            }
            case Danube: {
                if (DanubeLegions > 0) {
                    cout << "The Danube legions are overjoyed to hear someone wants to kill" << endl;
                    cout << "Severus. Some of your officers are a little concerned at this" << endl;
                    cout << "quick turn around, but you need all the forces you can muster." << endl;
                    ClaudiusArmySize += DanubeLegions;
                    DanubeLegions = 0;
                } else {
                    cout << "You stare at the Danube, for the moment lost in thought. Which" << endl;
                    cout << "river has seen more violence? The Rhine or the Danube? Staring at" << endl;
                    cout << "the far bank, you decide it's best to move on rather than recruit" << endl;
                    cout << "any more men." << endl;
                }
                do {
                    cout << "\nArmy: " << ClaudiusArmySize << ", Reputation: ";
                    cout << ((ClaudiusRep == 0) ? "Unkown" : 
                             (ClaudiusRep == 1) ? "Renowned" : 
                                                  "Exalted") << endl;
                    cout << "\nWhere will you go?" << endl;
                    cout << "G - Gaul" << endl;
                    cout << "I - Italy" << endl;
                    cout << "Q - Quit the game" << endl;
                    cout << "\nYour choice: ";
                    cin >> choice;
                    choice = toupper(choice);
                } while (choice != 'G' && choice != 'I' && choice != 'Q');
                break;
            }
            case Italy: {
                cout << "The crossing of the Alps is as smooth as it can be, Severus" << endl;
                cout << "is not waiting for you on the other side. Reports are he is" << endl;
                cout << "further south. You pause at the Rubicon to make camp, a part" << endl;
                cout << "of you amused to think of yourself as Julius himself. The next" << endl;
                cout << "day, the scouts report in. Severus approaches. You form up for" << endl;
                cout << "battle." << endl;
                if (ClaudiusRep > 1) {
                    cout << "You're exploits have reached the people of Rome, and" << endl;
                    cout << "now Severus's armies begin to abandon him! Your ranks swell" << endl;
                    cout << "but will it be enough?" << endl;
                    ClaudiusArmySize += 2500;
                    SeverusArmySize -= 2500;
                }
                if (ClaudiusArmySize > SeverusArmySize) {
                    state = victory;
                } else {
                    state = defeat;
                }
                break;
            }
            default:
                break;
        }

        switch (choice) {
            case 'B': {
                ClaudiusLoc = Britain;
                break;
            }
            case 'I': {
                ClaudiusLoc = Italy;
                break;
            }
            case 'G': {
                ClaudiusLoc = Gaul;
                break;
            }
            case 'E': {
                ClaudiusLoc = Iberia;
                break;
            }
            case 'D': {
                ClaudiusLoc = Danube;
                break;
            }
            case 'Q':{
                cout << "So that's it? Maybe you were not meant to be" << endl;
                cout << "the Augustus after all..." << endl;
            }
            default:
                break;
        }

    } while (choice != 'Q' && state == playing);
    cout << sceneBreak;
    if (state == victory) {
        cout << "As the dust clears, you see Severus's army either surrendering" << endl;
        cout << "or fleeing. You give orders for generous quarter to be given," << endl;
        cout << "and search out Severus. You find him dead, a slave having assisted" << endl;
        cout << "him in suicide. You feel yourself breathe a sigh of relief, and" << endl;
        cout << "realize that you are now Caesar! And as you realize that, the relief" << endl;
        cout << "turns to a new anxiety. The game for the throne might be over, but" << endl;
        cout << "how long will you keep it?" << endl;
    } else {
        cout << "You stare in stunned silence as first the left flank collapses," << endl;
        cout << "then the right. Your center backs up trying to prevent a gap in the" << endl;
        cout << "line, but this soon becomes a route. Your whole army is in flight, and" << endl;
        cout << "a merciless Severus deploys the light cavalry to cut down fleeing" << endl;
        cout << "soldiers. You try to rally the men, but a thrown spear strikes you in the" << endl;
        cout << "throat. So ends the tragic tale of Claudius." << endl;
    }

    cout << sceneBreak;
    cout << "GAME OVER" << endl;
    cout << sceneBreak;
    return 0;
}