
#pragma once

#include <iostream>
#include "ItemType.h"

class Item {

protected:
    std::string name;
    std::string description;
    ItemType type;
    
public:
    Item();
    Item(std::string name, std::string description);
    std::string getName();
    std::string getDescription();
    void setName(std::string newName);
    void setDescription(std::string newDescription);
    
    ItemType getItemType();
    void setItemType(ItemType newType);
    //Name and Description are unique identifiers of an item
    bool equals(Item *otherItem);
    virtual void use()=0;
    virtual std::string getJSON()=0;
    
};



