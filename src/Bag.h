
#pragma once

#include <vector>
#include "Item.h"

//Does not allow duplicate items, each item must be its own object

class Bag{
    
private:
    int maxSize;
    std::vector<Item*> items;
    
public:
    Bag();
    Bag(int size);
    int getMaxSize();
    void setMaxSize(int newSize);
    int getCurrentSize();
    std::vector<Item*> getItems();
    void addItem(Item *item);
    void removeItem(int itemNum);
    bool equals(Bag otherBag);
};
