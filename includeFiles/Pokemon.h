
#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
//pokemon base class function
class Pokemon{
protected:
    std::string Name;
    std::string Type;
    int HP;
    int Attack;
    int Defense;
    int SpeedAttack;
    int SpeedDefense;
    int MaxHP = 100; 
public:
    Pokemon(const std::string& name, const std::string& type, int hp, int attack, int defense, int speedAttack, int speedDefense): Name(name), Type(type), HP(hp), Attack(attack), Defense(defense), SpeedAttack(speedAttack), SpeedDefense(speedDefense) {}
    virtual ~Pokemon() {}
    virtual void ChooseType(const std::string &type);

    virtual void evolve() =0;
    virtual int  useAbility() =0;
    void setName(const std::string& name);

    std::string getName() const{
        return Name;
    }

    int  attack()const{
        return Attack;
    }
    int  speedAttack() const{
        return SpeedAttack;
    }
    int checkHP() const{
        return HP;
    }

    void hurt(int amount) {
        HP -= amount;
    }

    void heal(int amount) {
        HP += amount;
        if (HP > MaxHP) HP = MaxHP;
    }
};



//Charmander class
class CharmanderLine: public Pokemon{
public:
    CharmanderLine(): Pokemon("Charmander", "Fire", 39, 52, 43, 60, 50){}
    //~CharmanderLine();

    void evolve() override; //todo
    int useAbility() override; //todo

};

// Bulbasaur class
class BulbasaurLine: public Pokemon{
public:

    BulbasaurLine(): Pokemon("Bulbasaur", "Grass", 45, 49, 49, 65, 65){}
    void evolve() override; // todo
    int useAbility() override; //todo
};


//SquirtleLine class
class SquirtleLine: public Pokemon{

public:
    SquirtleLine(): Pokemon("Squirtle", "Water", 44, 48, 65, 50, 64){}
    //~SquirtleLine();
    void evolve() override;
    int useAbility() override;
};


//Pidgey class
class PidgeyLine: public Pokemon{

public:
    PidgeyLine(): Pokemon("Pidgey", "Flying", 40, 45, 40, 35, 45){}
    //~PidgeyLine();
    void evolve() override;
    int useAbility() override;
};

#endif
