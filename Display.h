#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Display {
    public:
        const DisplayMainMenu mainMenu;
        const DisplayWelcomeScreen welcomeScreen;
        const DisplayCharacterSelection characterSelection;
};

class DisplayMainMenu {
    private:
        const vector<string> options{"Start new game"}; // list of options
        const string border = "----------------------------"; // the border to be printed before and after the menu
        const string indent = "        "; // the indent to print before each line, excluding the border lines
        void print() const;
        friend class Display;
    public:
        vector<string> getOptions() const;
};

class DisplayWelcomeScreen {
    private:
        const string message = "Hello, welcome to the world of Pokemon!\nBefore you begin your adventure, tell us your name: ";
        void print() const;
    friend class Display;
};

class DisplayCharacterSelection {
    private:
        const string message = "Choose your starter pokemon!:";
        const vector<string> options{"Charmander", "Squirtle", "Bulbasaur"};
        const string border = "----------------------------"; // the border to be printed before and after the menu
        const string indent = "        "; // the indent to print before each line, excluding the border lines
        void print() const;
    friend class Display;
    public:
        vector<string> getOptions() const;
};