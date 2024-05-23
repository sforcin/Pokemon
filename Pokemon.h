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

    void ChooseType(const std::string &type);
    void setName(const std::string& name);
    std::string getName() const;

   virtual int  attack();
   virtual int  speedAttack();
   virtual int  checkHP() const;
   virtual int  useAbility();
};


class CharmanderLine{

private:
    int HP = 39;
    int attack = 52;
    int defense = 49;
    int speedAttackValue = 60;
    int speedDefense = 50;

public:
    CharmanderLine(const std::string& name = "Charmander", const std::string& type = "Fire");
    ~CharmanderLine();
    void evolve();
    int attack();
    int speedAttack();
    int checkHP() const;
    int useAbility();

};

class BulbasaurLine{

private:
    int HP = 45;
    int attack = 49;
    int defense = 49;
    int speedAttackValue = 65;
    int speedDefense = 65;

public:
    BulbasaurLine(const std::string& name = "Bulbasaur", const std::string& type = "Grass");
    ~BulbasaurLine();
    void evolve();
    int attack();
    int speedAttack();
    int checkHP() const;
    int useAbility();
};


class SquirtleLine{

private:
    int HP = 44;
    int attack = 48;
    int defense = 65;
    int speedAttackValue = 50;
    int speedDefense = 64;

public:
    SquirtleLine(const std::string& name = "Squirtle", const std::string& type = "Water");
    ~SquirtleLine();
    void evolve();
    int attack();
    int speedAttack();
    int checkHP() const;
    int useAbility();
};








#endif