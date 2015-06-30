
#include "HpAndPpItem.h"

//int restoreAmount;
HpAndPpItem::HpAndPpItem(std::string name, std::string description, int restoreAmount, RestoreType type) : Item(name, description){
    setRestoreAmount(restoreAmount);
    setRestoreType(type);
}

int HpAndPpItem::getRestoreAmount(){return restoreAmount;}
RestoreType HpAndPpItem::getRestoreType(){return type;}
void HpAndPpItem::setRestoreAmount(int newRestoreAmount){restoreAmount = newRestoreAmount;}
void HpAndPpItem::setRestoreType(RestoreType newType){type = newType;}

//TODO
void HpAndPpItem::use(){return;}