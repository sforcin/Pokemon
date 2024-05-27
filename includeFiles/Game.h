#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

#include "Player.h"
#include "Pokemon.h"

using namespace std;

class Game {
    public:
        bool isNewGame;
        bool part1Complete = false; 
        Player player;
        vector<Pokemon*> pokes;

    public:
        Game(); // use for creating a new game state
        void saveGame(string filename);
        void loadGame(string filename);

        void part1();

        void turn(); // where the game is played
        void battle(); // mini boss battle
        //void saveGame(const std::string& filename); //save game into a file
       
};

 void type_text(const string& text);