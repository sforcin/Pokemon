#include "Pokemon.h"
#include <iostream>
#include <string>

using namespace std;

//constructor made in header file

Pokemon::~Pokemon(){
    Name = "unknown";
    Type = "unknown";
}

void Pokemon::ChooseType(const std::string &type){
    cout << "Choose your Pokemon type!";
    Type = type;
}

void Pokemon::setName(const std::string& name){
    Name = name;
}

std::string Pokemon::getName() const{
    return name;
}