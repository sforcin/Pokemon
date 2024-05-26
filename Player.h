#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Item.h"

class Player{
protected:
    std:: string Name;
    char Gender;
    int XP;
    int Level;
    int HP;
    std::vector<Item> Inventory; //Inventory vector

public:
    Player(const std::string& name, char gender);
    std::string toString() const;
    void gainXP(int amount);
    void checkLevel();
    int getHP() const;
    void addItem(const Item& item);
    bool removeItem(const std::string& item);
    void listItems() const;
    int getXP() const;
    std::string getName() const{return Name;}

};


#endif