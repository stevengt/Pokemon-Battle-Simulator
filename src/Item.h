
#pragma once

#include <iostream>

class Item {

private:
    std::string name;
    std::string description;
    
    
public:
    Item();
    Item(std::string name, std::string description);
    std::string getName();
    std::string getDescription();
    void setName(std::string newName);
    void setDescription(std::string newDescription);
    
    //Name and Description are unique identifiers of an item
    bool equals(Item *otherItem);
    virtual void use()=0;
    
};



