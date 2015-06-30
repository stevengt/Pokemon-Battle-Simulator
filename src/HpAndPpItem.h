
#pragma once

#include "Item.h"
#include "RestoreType.h"
class StatusItem;
class HpAndPpItem : public Item {
    
private:
    int restoreAmount;
    RestoreType type;
    
public:
    HpAndPpItem(std::string name, std::string description, int restoreAmount, RestoreType type);
    int getRestoreAmount();
    RestoreType getRestoreType();
    void setRestoreAmount(int newRestoreAmount);
    void setRestoreType(RestoreType newType);
    void use();
    
};
