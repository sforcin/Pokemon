#include <iostream>

#include "Display.h"
#include "Game.h"

using namespace std;

void playGame(Game *myGame);

int main() {
    Display display;
    Game *myGame = new Game(); // passing by reference for playGame was giving too many issues (revisit this later)

    display.mainMenu.print();
    cout << "$:";
    int option = 0;
    cin >> option;
    while (option < 1 || 4 < option) { // invalid input
        cout << "Unknown Option!!!" << endl << endl;
        display.mainMenu.print();
        cin >> option;
    }

    string inputFileName = "";
    switch(option) {
        case 1: // start new game
            playGame(myGame);
            break;
        case 2: // resume game
            cout << "Enter your save filename" << endl << ":";
            cin >> inputFileName;
            myGame->loadGame(inputFileName);
            playGame(myGame);
            break;
        case 3: // view all games
            break;
        case 4: // pokedex
            break;
    }

    delete myGame;

    return 0;
}

void playGame(Game *myGame) {
    cout << myGame->state << endl;
}