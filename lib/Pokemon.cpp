#include "../includeFiles/Pokemon.h"
#include <iostream>
#include <string>

using namespace std;

void Pokemon::ChooseType(const std::string &type){
    Type = type;
    std::cout<< Name<< " is type " << Type<< "!"<< std::endl;
}

void Pokemon::setName(const std::string& name){
    Name = name;
}



//charmanderLine functions

void CharmanderLine::evolve(){
    if(Attack>= 60 && Defense >=50){
        Name = "Charmeleon";
        HP= 58;
        Attack = 64;
        Defense = 58;
        SpeedAttack = 80;
        SpeedDefense = 65;
        std::cout<< "Evolution Complete";

    }
}

int CharmanderLine::useAbility() {
    return Attack;
}

// Bulb-Line functions

void BulbasaurLine::evolve(){
    if(Attack>= 60 && Defense >=50){
        Name = "Ivysaur";
        HP= 60;
        Attack = 62;
        Defense = 63;
        SpeedAttack = 80;
        SpeedDefense = 80;
        std::cout<< "Evolution Complete!";

    }
}

int BulbasaurLine::useAbility() {
    return Attack;
}

// Squirtle-Line functions

void SquirtleLine::evolve(){
    if(Attack>= 60 && Defense >=50){
        Name = "Wartortle";
        HP= 59;
        Attack = 63;
        Defense = 80;
        SpeedAttack = 65;
        SpeedDefense = 80;
        std::cout<< "Evolution Complete!";

    }
}

int SquirtleLine::useAbility() {
    return Attack;
}