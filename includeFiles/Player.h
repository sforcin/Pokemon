#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std; 

class Player{
protected:
    std:: string Name;
    char Gender;
    int XP;
    int Level;
    int HP;
    std::vector<string> Inventory; //Inventory vector

public:
    Player(const std::string& name, char gender);
    std::string toString() const;
    void gainXP(int amount);
    void checkLevel();
    int getXP() const;
    std::string getName() const{return Name;}
    int getHP() const;

    void getItemDescription(string& item);
    void addItem(const string& item);
    bool removeItem(const std::string& item);
    void useItem(const std::string& item, Pokemon& pokemon, vector<Pokemon*> pokes);
    void listItems() const;


};
#endif
