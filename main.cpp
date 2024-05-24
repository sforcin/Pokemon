#include <iostream>
#include <string>

#include "Display.h"
#include "Game.h"
#include "Pokemon.h"

using namespace std;

void playGame(Game &myGame, Display &display);

int main() {
    Display display;
    Game myGame;

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
            playGame(myGame, display);
            break;
        case 2: // resume game
            cout << "Enter your save filename" << endl << ":";
            cin >> inputFileName;
            myGame.loadGame(inputFileName);
            playGame(myGame, display);
            break;
        case 3: // view all games
            cout << "Not Implemented Yet" << endl;
            break;
        case 4: // pokedex
            cout << "Not Implemented Yet" << endl;
            break;
    }

    return 0;
}

void playGame(Game &myGame, Display &display) {
    if (myGame.isNewGame) { // ask for the player name and set up the player

        bool loop = true;
        while (loop) {

        display.welcomeScreen.print();
        cout << "$:";
        string playerName = "";
        cin >> playerName;

        myGame.player = Player(playerName, 'X');

        display.characterSelection.print();
        cout << "$:";
        int option = 0;
        cin >> option;
        while (option < 1 || 3 < option) { // invalid input
            cout << "Unknown Option!!!" << endl << endl;
            display.characterSelection.print();
            cin >> option;
        }

        cout << "You Selected " << display.characterSelection.getOptions().at(option - 1) << "!!!" << endl;
        Pokemon *selection = new CharmanderLine();
        switch(option) {
            case 1:
                // selection = new CharmanderLine();
                break;
            case 2:
                // selection = new SquirtleLine();
                break;
            case 3:
                // selection = new BulbasaurLine();
                break;
        }
        myGame.pokes.push_back(selection); // add selected started pokemon to player profile

        cout << endl;
        cout << "Profile:" << endl;
        cout << "    Player: " << myGame.player.toString() << endl;
        cout << "    Starter Pokemon: " << myGame.pokes.at(0)->getName() << endl;

        string input = "";
        cout << endl;
        while (input != "Yes" && input != "No") {
            cout << "Confirm Options? (Yes/No):";
            cin >> input;
        }

        if (input == "Yes") {
            loop = false; // exit loop
        } else {
            // stay in loop
        }
        }

    }
    
    // if game is being resumed, the player data is already set

    

}