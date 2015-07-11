
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

int Bag::getCurrentHpAndPpItemsSize(){return hpAndPpItems.size();}

int Bag::getCurrentStatusItemsSize(){return statusItems.size();}

std::vector<HpAndPpItem*> Bag::getHpAndPpItems(){return hpAndPpItems;}

std::vector<StatusItem*> Bag::getStatusItems(){return statusItems;}


void Bag::addItem(Item *item){
    if (item->getItemType() == STATUS){
        if (maxSize==statusItems.size()){
            throw std::invalid_argument( "Bag too small" );
        }
        statusItems.push_back(static_cast<StatusItem*>(item));
    } else {
        if (maxSize==hpAndPpItems.size()){
            throw std::invalid_argument( "Bag too small" );
        }
        hpAndPpItems.push_back(static_cast<HpAndPpItem*>(item));
    }
}


//void Bag::removeItem(int itemNum){
//    if (items.size() == 0){
//        throw std::invalid_argument( "Nothing to remove" );
//    }
//    if (itemNum < 0 || itemNum >= getCurrentSize()){
//        throw std::invalid_argument( "Invalid item index" );
//    }
//    items.erase(items.begin() + itemNum);
//}



void Bag::removeItem(Item *item){
    if (item->getItemType() == STATUS){
        if (statusItems.size() == 0){
            throw std::invalid_argument( "Nothing to remove" );
        }
        for (int i = 0; i < statusItems.size(); i++){
            if (item == statusItems.at(i)){
                statusItems.erase(statusItems.begin() + i);
                return;
            }
        }
            throw std::invalid_argument( "Item not found" );
    } else {
        if (hpAndPpItems.size() == 0){
            throw std::invalid_argument( "Nothing to remove" );
        }
        for (int i = 0; i < hpAndPpItems.size(); i++){
            if (item == hpAndPpItems.at(i)){
                hpAndPpItems.erase(hpAndPpItems.begin() + i);
                return;
            }
        }
        throw std::invalid_argument( "Item not found" );
    }
}



bool Bag::equals(Bag otherBag){
    if (getCurrentHpAndPpItemsSize() != otherBag.getCurrentHpAndPpItemsSize() || getMaxSize() != otherBag.getMaxSize()
        || getCurrentStatusItemsSize() != otherBag.getCurrentStatusItemsSize()){
        return false;
    }
    for (int i=0; i < getCurrentHpAndPpItemsSize();i++){
        if(hpAndPpItems.at(i)!=otherBag.getHpAndPpItems().at(i)){
            return false;
        }
    }
    for (int i=0; i < getCurrentStatusItemsSize();i++){
        if(statusItems.at(i)!=otherBag.getStatusItems().at(i)){
            return false;
        }
    }
    return true;
}
