
#ifndef GAME_H
#define GAME_H

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
        bool part2Complete = false;
        bool part3Complete = false;
        bool part4Complete = false;
        bool part5Complete = false;
        bool part6Complete = false;
        Player player;
        vector<Pokemon*> pokes;

    public:
        Game(); // use for creating a new game state
        void saveGame(string filename);
        void loadGame(string filename);

        void part1();
        void part2();
        void part3();
        void part4();
        void part5();
        void part6();
        // void turn(); 
        void battle(); // mini boss battle
        void catchPidgey();
        void catchBulbasaur();
        //void saveGame(const std::string& filename); //save game into a file
       
};

 void type_text(const string& text);
 void type_text(const string& text1, const string &text2);

 #endif