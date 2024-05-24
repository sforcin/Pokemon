#ifndef ENEMY_H
#define ENEMY_H

#include "NPC.h"
#include <iostream>


class Enemy : public NPC{
private:
int attackPower;
public:
    Enemy(const std::string& name, const std::string& info, int level, int hp, int attackPower): NPC(name, info, level, hp), attackPower(attackPower) {} 
    int attack(){
        //HP = HP - attackPower;
        return attackPower;
    }

    int checkHP() const{
        return (HP);
    }
};

#endif
