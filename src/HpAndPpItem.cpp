
#include "HpAndPpItem.h"

//int restoreAmount;
HpAndPpItem::HpAndPpItem(std::string name, std::string description, int restoreAmount, ItemType type) : Item(name, description){
    setRestoreAmount(restoreAmount);
    setItemType(type);
}

int HpAndPpItem::getRestoreAmount(){return restoreAmount;}
void HpAndPpItem::setRestoreAmount(int newRestoreAmount){restoreAmount = newRestoreAmount;}

//TODO
void HpAndPpItem::use(){return;}