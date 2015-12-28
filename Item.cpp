
#include "Item.h"

Item::Item(){}

Item::Item(std::string name, std::string description){
    setName(name);
    setDescription(description);
}

std::string Item::getName(){return name;}
std::string Item::getDescription(){return description;}
void Item::setName(std::string newName){name = newName;}
void Item::setDescription(std::string newDescription){ description = newDescription; }
bool Item::equals(Item *otherItem){ return otherItem->getName() == name && otherItem->getDescription() == description; }

ItemType Item::getItemType(){return type;}
void Item::setItemType(ItemType newType){type = newType;}