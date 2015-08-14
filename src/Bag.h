
#pragma once

#include <vector>
#include "StatusItem.h"
#include "HpAndPpItem.h"

//Does not allow duplicate items, each item must be its own object

class Bag{
    
private:
    int maxSize;
    std::vector<HpAndPpItem*> hpAndPpItems;
    std::vector<StatusItem*> statusItems;
public:
    Bag();
    Bag(int size);
    int getMaxSize();
    void setMaxSize(int newSize);
    int getCurrentHpAndPpItemsSize();
    int getCurrentStatusItemsSize();
    std::vector<HpAndPpItem*> getHpAndPpItems();
    std::vector<StatusItem*> getStatusItems();
    void addItem(Item *item);
    //void removeItem(int itemNum);
    void removeItem(Item *item);
    bool equals(Bag otherBag);
};
