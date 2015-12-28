
#pragma once

#include "ButtonGroup.h"
#include "Bag.h"

class ItemButtonGroup : public ButtonGroup {
private:
    static const int locationX = 350;
    static const int locationY = 350;
    static const int col2Offset = 350;
    static const int rowOffset = 75;
    static const int expandedButtonWidth = 300;
    Bag *bag;
    
public:
    ItemButtonGroup(Bag *bag, bool isHpAndPpItemsGroup);
    void setBag(Bag *newbag);
};