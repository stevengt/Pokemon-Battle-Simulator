
#pragma once

#include "Item.h"
class StatusItem;
class HpAndPpItem : public Item {
    
private:
    int restoreAmount;
public:
    HpAndPpItem();
    HpAndPpItem(std::string name, std::string description, int restoreAmount, ItemType type);
    int getRestoreAmount();
    void setRestoreAmount(int newRestoreAmount);
    void use();
    
};
