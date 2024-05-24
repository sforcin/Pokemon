#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "item.h"

class Player{
private:
    std:: string Name;
    char Gender;
    int XP;
    int Level;
    int HP;
    std::vector<Item> Inventory;

public:
    Player(const std::string& name, char gender);
    void gainXP(int amount);
    void checkLevel();
    int getHP() const;
    void addItem(const Item& item);
    bool removeItem(const std::string& item);
    void listItems() const;

};


#endif