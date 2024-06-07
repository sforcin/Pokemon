#include "../includeFiles/Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

Player::Player(const std::string& name, char gender) : Name(name), XP(0){
}

void Player::gainXP(int amount){
    XP+= amount;
}

const vector<string>& Player::getInventory() const {
    return Inventory;
}

void Player::setInventory(const vector<string>& inventory) {
    Inventory = inventory;
}

//ITEMS&NVENTORY FUNCTIONS ---------------------------------------------------------------------------------------------------------------------------------
void getItemDescription(string& item) {
    if(item == "Potion"){
       cout << "The Potion Item heals a Pokemon by 20 HP <3" << endl;
    }

    else if (item == "PokeBall"){
        cout << "The PokeBall Item is used to catch wild Pokemon" << endl; 
    }
}

void Player::addItem(const string& item){
    Inventory.push_back(item);
}

bool Player::removeItem(const std::string& item){
    for(size_t i =0; i< Inventory.size();++i){
        if(Inventory.at(i)==item){
            Inventory.erase(Inventory.begin()+i); //remove item at index i
            return true;
        }
    }
    cout << "Item is not in inventory!"<< endl; 
    return false; 
}

//create an overload with no pokemon pass through if it needs to be appluied to player 
void Player::useItem(const std::string& itemName, Pokemon *pokemon, vector<Pokemon*> pokes) {
    if(itemName == "Potion"){
        pokemon->heal(20);
        cout << "You used a Potion. It heals your Pokemon by 20 HP." << endl;
    }

    if(itemName == "Rare Candy"){
        pokemon->evolve();
        cout << "You used a Rare Candy. It lead to your Pokemon evolving." << endl;
    }

    else if (itemName == "PokeBall"){
        cout << "You used a Poké Ball. Attempting to catch the wild Pokemon." << endl;
        srand(time(0));
        int random = 1+ rand() % 10;

        if( random>=7){
            pokes.push_back(pokemon);
            cout << "Congrats! You've caught " << pokemon->getName() << "!" << endl; 
        }
        else{
            cout << "Unfortunately, " << pokemon->getName() << "got away :(" << endl; 
        }
    }

    removeItem(itemName);
    return; 
}


std::string Player::toString() const {
    return "Name: " + Name;
}

void Player::getPokeballAmt() {
    int counter =0; 
    for(size_t i =0; i< Inventory.size(); ++i){
        if(Inventory.at(i)=="Pokeball"){
            counter++;
        }
    }
    cout << "You have " << counter << " Pokeballs." << endl;  
}

void Player::getPotionAmt() {
 int counter =0; 
    for(size_t i =0; i< Inventory.size(); ++i){
        if(Inventory.at(i)=="Potion"){
            counter++;
        }
    }
    cout << "You have " << counter << " Potions." << endl;  
}

int Player::getItemCount(const string& item) const {
    return count(Inventory.begin(), Inventory.end(), item);
}
