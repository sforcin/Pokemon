#include "item.h"
#include <iostream>
#include <vector>

using namespace std;

Item::Item(const std::string& name, const std::string& description): name(name), description(description){}

std::string Item::getDescription() const{
    return description;
}
std::string Item::getName() const{
    return name;
}