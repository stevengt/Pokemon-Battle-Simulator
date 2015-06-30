
#include "Bag.h"
#include <stdexcept>

Bag::Bag(){}
Bag::Bag(int maxSize){
    if (maxSize <1){
        setMaxSize(1);
    } else {
        setMaxSize(maxSize);
    }
}
int Bag::getMaxSize(){return maxSize;}
void Bag::setMaxSize(int newSize){maxSize = newSize;}
int Bag::getCurrentSize(){return items.size();}
std::vector<Item*> Bag::getItems(){return items;}
void Bag::addItem(Item *item){
    if (maxSize==items.size()){
        throw std::invalid_argument( "Bag too small" );
    }
    items.push_back(item);
}

void Bag::removeItem(int itemNum){
    if (items.size() == 0){
        throw std::invalid_argument( "Nothing to remove" );
    }
    if (itemNum < 0 || itemNum >= getCurrentSize()){
        throw std::invalid_argument( "Invalid item index" );
    }
    items.erase(items.begin() + itemNum);
}

bool Bag::equals(Bag otherBag){
    if (getCurrentSize() != otherBag.getCurrentSize() || getMaxSize() != otherBag.getMaxSize()){
        return false;
    }
    for (int i=0; i < getCurrentSize();i++){
        if(items.at(i)!=otherBag.getItems().at(i)){
            return false;
        }
    }
    return true;
}
