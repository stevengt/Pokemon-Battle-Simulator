
#include "ItemButtonGroup.h"

ItemButtonGroup::ItemButtonGroup(Bag *bag, bool isHpAndPpItemsGroup){
    setBag(bag);
    
    int itemCount = 0;
    
    int bagSize;
    if (isHpAndPpItemsGroup){
        bagSize = bag->getCurrentHpAndPpItemsSize();
    } else {
        bagSize = bag->getCurrentStatusItemsSize();
    }
    
        for (int i = 0; i < bagSize; i++){
            
            Item *item;
            if(isHpAndPpItemsGroup){
                item = bag->getHpAndPpItems().at(i);
            } else {
                item = bag->getStatusItems().at(i);
            }
            
            int x = locationX;
            int y = locationY + itemCount*rowOffset;
            if (itemCount >= 5){
                x = locationX + col2Offset;
                y = locationY + (itemCount-5)*rowOffset;
            }
            addButton(new Button(x, y, expandedButtonWidth, buttonHeight, item->getName() + " : " + item->getDescription()));
            itemCount++;
            
        }
    }

void ItemButtonGroup::setBag(Bag *newBag){
    bag = newBag;
}