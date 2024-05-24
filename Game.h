#pragma once

#include <string>
#include <iostream>

#include "Player.h"
#include "Pokemon.h"

using namespace std;

class Game {
    public:
        bool isNewGame;
        Player player;
        vector<Pokemon*> pokes;

    public:
        Game(); // use for creating a new game state
        void saveGame(string filename);
        void loadGame(string filename);

};