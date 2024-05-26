#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item{
private:
    std::string name;
    std::string description;

public:
    Item(const std::string& name, const std::string& description);

    std::string getName() const;
    std::string getDescription() const;

};

#endif