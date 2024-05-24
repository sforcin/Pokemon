#include "Display.h"

void DisplayMainMenu::print() const {
    cout << border << endl;
    cout << indent << "MAIN MENU:" << endl;
    for (int i = 0; i < options.size(); i++) {
        cout << indent << options.at(i) << endl;
    }
    cout << border << endl;
}

vector<string> DisplayMainMenu::getOptions() const {
    return options;
}