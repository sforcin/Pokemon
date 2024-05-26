#include "../includeFiles/trainer.h"
#include <iostream>

using namespace std;

void Trainer::choosePokemon(){
    std::cout << "Trainer: choose a pokemon!"<< std::endl;

}

void Trainer::updateLevel(){
    //i dont think this is necessary since evolve..?
}

std::string Trainer::checkLevel() const{
    return "Level: " + std::to_string(Level);
}

int Trainer::checkHP() const{
    return getHP();
}

int Trainer::checkXP() const{
    return getXP();
}