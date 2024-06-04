#include "../includeFiles/Player.h"
// #include "../includeFiles/Pokemon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Player::Player(const std::string& name, char gender) : Name(name), Gender(gender), XP(0), Level(1), HP(3 * Level + 100){
}

void Player::gainXP(int amount){
    XP+= amount;
    checkLevel();
}

void Player::checkLevel(){
    while(XP>=100 * Level){
        Level++;
        HP= 3* Level + 100;
        std::cout<< "Leveled up to "<< Level<< "! HP is now" << HP<< "."<<std::endl;
    }
}

int Player::getHP() const{
    return HP;

}

//ITEMS/INVENTORY FUNCTIONS ---------------------------------------------------------------------------------------------------------------------------------
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
void Player::useItem(const std::string& itemName, Pokemon &pokemon, vector<Pokemon*> pokes) {
    if(itemName == "Potion"){
        pokemon.heal(20);
        cout << "You used a Potion. It heals your Pokemon by 20 HP." << endl;
    }

    else if (itemName == "PokeBall"){
        cout << "You used a Poké Ball. Attempting to catch the wild Pokemon." << endl;
        srand(time(0));
        int random = 1+ rand() % 10;

        if( random>=7){
            pokes.push_back(&pokemon);
            cout << "Congrats! You've caught " << pokemon.getName() << "!" << endl; 
        }
        else{
            cout << "Unfortunately, " << pokemon.getName() << "got away :(" << endl; 
        }
    }

    removeItem(itemName);
    return; 
}

int Player::getXP() const{
    return XP;
}

std::string Player::toString() const {
    return "Name: " + Name + ", Gender: " + Gender;
}