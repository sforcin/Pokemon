#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class DisplayMainMenu {
    private:
        const vector<string> options{"Start new game", "Resume game", "View all games", "Pokedex!"}; // list of options
        const string border = "---------------------------------"; // the border to be printed before and after the menu
        const string indent = "        "; // the indent to print before each line, excluding the border lines
        friend class Display;
    public:
        vector<string> getOptions() const;
        void print() const;
};

class DisplayWelcomeScreen {
    private:
        const string message = "Hello, welcome to the world of Pokemon!\nBefore you begin your adventure, tell us your name: ";
    friend class Display;
    public:
        void print() const;
};

class DisplayCharacterSelection {
    private:
        const string message = "Choose your starter pokemon!:";
        const vector<string> options{"Charmander", "Squirtle", "Bulbasaur"};
        const string border = "---------------------------------"; // the border to be printed before and after the menu
        const string indent = "        "; // the indent to print before each line, excluding the border lines
    friend class Display;
    public:
        vector<string> getOptions() const;
        void print() const;
};

class DisplayPauseMenu {
    private:
        const vector<string> options{"Edit / Add Characters", "Delete Game", "Save & Exit", "Resume Game"};
        const string border = "---------------------------------"; // the border to be printed before and after the menu
        const string indent = "        "; // the indent to print before each line, excluding the border lines        
        friend class Display;
    public:
        vector<string> getOptions() const;
        void print() const;
};

class Display {
    public:
        const DisplayMainMenu mainMenu;
        const DisplayWelcomeScreen welcomeScreen;
        const DisplayCharacterSelection characterSelection;
        const DisplayPauseMenu pauseMenu;
};