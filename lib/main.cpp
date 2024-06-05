#include <iostream>
#include <string>

#include "../includeFiles/Display.h"
#include "../includeFiles/Game.h"
#include "../includeFiles/Pokemon.h"

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
            getline(cin, playerName);
            getline(cin, playerName);

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
            Pokemon *selection = new CharmanderLine(); //DO WE USE delete[] when destructing this?????????????????????????????/ cause we are using the new operator 

            switch(option) {
                case 1:
                    selection = new CharmanderLine();
                    break;
                case 2:
                    selection = new SquirtleLine();
                    break;
                case 3:
                    selection = new BulbasaurLine();
                    break;
            }

            myGame.pokes.push_back(selection); // add selected started pokemon to player profile

            cout << endl;
            cout << "Profile:" << endl;
            cout << "    Player: " << myGame.player.toString() << endl;
            cout << "    Starter Pokemon: " << myGame.pokes.at(0)->getName() << endl;

            char input = ' ';
            cout << endl;

            while (tolower(input) != 'y' && tolower(input) != 'n') {
                cout << "Confirm Options? (Y/N):";
                cin >> input;
            }

            if (tolower(input) == 'y') {
                string filename;
                cout << "Choose a name to save your game under: ";
                cin>> filename;
                myGame.saveGame(filename);
                loop = false; // exit loop

            } 
            
            else {
                // maybe make a change characteristics function and call
            }
        }

    }
    
    // if game is being resumed, the player data is already set

    bool loop = true;
    while (loop) {

        string input = "";
        if (input != "next" && input != "pause") {
            cout << "'next' for next turn, 'pause' for pause menu" << endl;
            cin >> input;
        }

    //
    // PAUSE MENU IMPLEMENTATION - make this a seperate function !!!! to call later in main. 
    //

        if (input == "pause") { // pause/settings menu
            display.pauseMenu.print();
            int option = 0;
            bool validOption = false;
            while (!validOption) {
                cout << "$:";
                cin >> option;
                validOption = true; // setup for if not the default case
                switch(option) {
                    default:
                        validOption = false; // if the option isn't recognized
                        break;
                    case 1:
                        cout << "Don't know how to pause game\nResuming game lmao" << endl;
                        break;
                    case 2:
                        cout << "This feature has been removed\nResuming game lmao" << endl;
                        break;
                    case 3:
                        cout << "Delete Game" << endl;
                        cout << "Will implement something better later\nFor now, exiting loop." << endl;
                        loop = false;
                        break;
                    case 4:
                        cout << "Will implement saving game later\n for now, resuming game" << endl;
                        break;
                    case 5:
                        break;
                }
            }
            cout << "Resuming Game" << endl;
        }
    //
    // THE ACTUAL GAME LOGIC
    //

///FIX  THISSSSSSS - for loop 
        else if (input == "next") { // do next turn
            if(myGame.part1Complete == false){
                myGame.part1();
                //add do you want to exit function after each part 
            }
            if(myGame.part2Complete == false){
                myGame.part2();
            }
             if(myGame.part3Complete == false){
                myGame.part3();
            }
            if(myGame.part4Complete == false){
                myGame.part4();
            }
            if(myGame.part5Complete == false){
                myGame.part5();
            }
            if(myGame.part6Complete == false){
                myGame.part6();
            }
        }

    }

}