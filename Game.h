#pragma once

#include <string>
#include <iostream>

using namespace std;

class Game {
    public:
        int state;
    public:
        Game(); // use for creating a new game state
        void saveGame(string filename);
        void loadGame(string filename);
};