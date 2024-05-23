#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

class Pokemon{
protected:
    std::string Name = "undecided";
    std::string Type = "undecided";

public:

    void ChooseType();
    void setName(const std::string& name);
    int  getName() const;
    int  attack();
    int  speedAttack();
    int  checkHP() const;
    int  useAbility();


};









#endif