#include "Player.h"
#include <iostream>

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


//implement add and remove items to the inventory

void Player::addItem(const Item& item){
    Inventory.push_back(item);
}

bool Player::removeItem(const std::string& item){
    for(size_t i =0; i< Inventory.size();++i){
        if(Inventory[i].getName()==item){
            Inventory.erase(Inventory.begin()+i); //remove item at index i
            return true;
        }
    }
    return false; //if the item is not in the inventory
}

int Player::getXP() const{
    return XP;
}

std::string Player::toString() const {
    return "Name: " + Name + ", Gender: " + Gender;
}