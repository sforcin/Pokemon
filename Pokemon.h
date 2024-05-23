#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

class Pokemon{
protected:
    std::string Name = "undecided";
    std::string Type = "undecided";

public:

    Pokemon(const std::string &name = "undefined", const std::string& type = "undefined"){}
    virtual ~Pokemon();

    void ChooseType();
    void setName(const std::string& name);
    std::string getName() const;

   virtual int  attack();
   virtual int  speedAttack();
   virtual int  checkHP() const;
   virtual int  useAbility();
};











#endif