
#include "ItemButtonGroup.h"

ItemButtonGroup::ItemButtonGroup(Bag *bag, bool isHpAndPpItemsGroup){
    setBag(bag);
    
    int itemCount = 0;
    for (int i = 0; i < bag->getCurrentSize(); i++){
        Item *item = bag->getItems().at(i);
        int x = locationX;
        int y = locationY + itemCount*rowOffset;
        if (itemCount >= 5){
            x = locationX + col2Offset;
            y = locationY + (itemCount-5)*rowOffset;
        }
        if (isHpAndPpItemsGroup){
            if(item->getItemType() == HP || item->getItemType() == PP ){
                
                addButton(new Button(x, y, expandedButtonWidth, buttonHeight, item->getName() + " : " + item->getDescription()));
                itemCount++;
            }
        } else {
            if(item->getItemType() == STATUS){
                addButton(new Button(x, y, expandedButtonWidth, buttonHeight, item->getName() + " : " + item->getDescription()));
                itemCount++;
            }
        }
    }
}

void ItemButtonGroup::setBag(Bag *newBag){
    bag = newBag;
}