#ifndef NPC_H
#define NPC_H

#include <string>

class NPC {
protected:
    std::string name;
    std::string info;
    int level;
    int HP;

public:
    NPC(const std::string& name, const std::string& info, int level, int hp) : name(name), info(info), level(level), HP(hp) {}
    virtual void provideInfo() const =0;
    virtual int calculateDamage() const =0;
};

#endif