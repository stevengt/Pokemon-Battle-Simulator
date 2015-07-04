
#pragma once

#include <TestSuite.h>
#include "testVariables.h"

using namespace testVariables;

class ItemTests : public CxxTest::TestSuite {
    
public:
    
    void testEquals(void) {
        
        std::string itemName = "Potion";
        std::string itemDescription = "Heal 20 damage";
        int itemRestoreAmount = 20;
        ItemType itemRestoreType = HP;
        
        
        Item *item = nullptr;
        item = new HpAndPpItem(itemName, itemDescription, itemRestoreAmount, itemRestoreType);
        
        TS_ASSERT(item->equals(item1));
        TS_ASSERT(!item->equals(item3));
        TS_ASSERT(!item->equals(item4));
        
        itemName = "Awaken";
        itemDescription = "Wakes up an asleep Pokemon";
        Status itemStatus = ASLEEP;
        
        item = new StatusItem(itemName, itemDescription, itemStatus);
        
        TS_ASSERT(item->equals(item4));
        TS_ASSERT(!item->equals(item3));
        TS_ASSERT(!item->equals(item5));
        
    }
    
};