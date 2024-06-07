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
    while (option > 2 || option == 0) { // invalid input
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
            myGame.isNewGame = false; 
            playGame(myGame, display);
            break;
    }

    return 0;
}

void playGame(Game &myGame, Display &display) {
    string filename;
    if (myGame.isNewGame == true ) { // ask for the player name and set up the player

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
            int option=0;
            
            while (!(cin >> option) || option < 1 || option > 3) { 
                cout << "Unknown Option!!!" << endl << endl;
                cin >> option;
                display.characterSelection.print();
                cin >> option;
                cin.clear();
             
            }

            cout << "You Selected " << display.characterSelection.getOptions().at(option - 1) << "!!!" << endl;
            Pokemon *selection = new CharmanderLine(); 

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
                cout << "Choose a name to save your game under: ";
                cin>> filename;
                myGame.saveGame(filename);
                loop = false; // exit loop
                myGame.isNewGame = false;

            } 
            
            else {
                loop = true; 
                cout << "Okay, we will reask the information" << endl; 
            }
        }

    }
    
    // if game is being resumed, the player data is already set

    bool loop = true;
    while (loop) {

        string input = "";
        if (input != "next" && input != "pause") {
            cout << "'next' for next turn, 'pause' for pause" << endl;
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
                        cout << "Saving & Exiting" << endl;
                        // cout << "Will implement something better later\nFor now, exiting loop." << endl;
                        loop = false;
                        break;
                    case 2:
                        cout << "Resuming game" << endl;
                        break;
                }
            }
            // cout << "Resuming Game" << endl;
        }
    //
    // THE ACTUAL GAME LOGIC
    //

        else if (input == "next") { // do next turn
            if(myGame.part1Complete == false){
                myGame.part1();
                myGame.saveGame(filename);
            }
            else if(myGame.part2Complete == false){
                myGame.part2();
                myGame.saveGame(filename);
            }
            else if(myGame.part3Complete == false){
                myGame.part3();
                myGame.saveGame(filename);
            }
            else if(myGame.part4Complete == false){
                myGame.part4();
                myGame.saveGame(filename);
            }
            else if(myGame.part5Complete == false){
                myGame.part5();
                myGame.saveGame(filename);
            }
            else if(myGame.part6Complete == false){
                myGame.part6();
                myGame.saveGame(filename);
                cout << "Congrats on completing the game!" << endl; 
                loop = false;  
            }
        }
        
    }
}
