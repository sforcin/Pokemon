#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Pokemon.h"
using namespace std; 

class Player{
protected:
    string Name;
    int XP;
    vector<string> Inventory; //Inventory vector

public:
    Player(const std::string& name, char gender);
   
    void setName(const string &playerName){ Name = playerName;}
    void setXP(const int &playerXP){ XP = playerXP;}
    string getName() const{return Name;}
    int getXP() const { return XP;}
    
    void gainXP(int amount);
    string toString() const;

    void getItemDescription(string& item);
    void addItem(const string& item);
    bool removeItem(const std::string& item);
    void useItem(const std::string& item, Pokemon *pokemon, vector<Pokemon*> pokes);
    void getPokeballAmt() ;
    void getPotionAmt() ;
    int getItemCount(const string& item) const;

    const vector<string>& getInventory() const;
    void setInventory(const vector<string>& inventory);

};
#endif