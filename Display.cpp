#include "Display.h"

//
// MAIN MENU CLASS
//

void DisplayMainMenu::print() const {
    cout << border << endl;
    cout << indent << "    MAIN MENU:" << endl;
    for (int i = 0; i < options.size(); i++) {
        cout << indent << (i + 1) << ". " << options.at(i) << endl;
    }
    cout << border << endl;
}

vector<string> DisplayMainMenu::getOptions() const {
    return options;
}

//
// WELCOME SCREEN CLASS
//

void DisplayWelcomeScreen::print() const {
    cout << message << endl;
}

//
// CHARACTER SELECTION SCREEN CLASS
//

void DisplayCharacterSelection::print() const {
    cout << border << endl;
    cout << message << endl;
    for (int i = 0; i < options.size(); i++) {
        cout << indent << (i + 1) << ". " << options.at(i) << endl;
    }
    cout << border << endl;
}

vector<string> DisplayCharacterSelection::getOptions() const {
    return options;
}

//
// PAUSE MENU SCREEN CLASS
//

void DisplayPauseMenu::print() const {
    cout << border << endl;
    cout << indent << "    Settings:" << endl;
    for (int i = 0; i < options.size(); i++) {
        cout << indent << (i + 1) << ". " << options.at(i) << endl;
    }
    cout << border << endl;    
}

vector<string> DisplayPauseMenu::getOptions() const {
    return options;
}