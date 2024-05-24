#ifndef INFO_FRIEND_H
#define INFO_FRIEND_H
#include <iostream>

#include "NPC.h"

using namespace std;

class InfoFriend : public NPC{

public:
    InfoFriend(const std::string& name, const std::string& info, int level, int hp) : NPC(name, info, level, hp) {}
    void provideInfo() const override{
        std::cout << "Info: " << info<< std::endl;

    }

    int calculateDamage() const override{
        return 0; //friends dont create damage
    }
};

#endif