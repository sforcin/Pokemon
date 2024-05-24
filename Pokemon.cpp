#include "Pokemon.h"
#include <iostream>
#include <string>

using namespace std;

//constructor made in header file

Pokemon::~Pokemon(){
  //  Name = "unknown";
    //Type = "unknown";
}

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
        std::cout<< "Evolved into Charmeleon";

    }
}