#pragma once
#include <TestSuite.h>
#include "testVariables.h"

using namespace testVariables;

class BagTests : public CxxTest::TestSuite {

public:
    
    void testConstructor(void) {
        Bag bag = Bag(3);
        TS_ASSERT_EQUALS(bag.getCurrentSize(),0);
        TS_ASSERT_EQUALS(bag.getMaxSize(),3);
    }
    
    void testAddItem(void) {
        Bag bag = Bag(3);
        
        bag.addItem(item1);
        bag.addItem(item3);
        bag.addItem(item5);
        
        TS_ASSERT_EQUALS(bag.getCurrentSize(),3);
        TS_ASSERT(bag.equals(bag1));
        TS_ASSERT_THROWS_ANYTHING(bag.addItem(item4));
        
    }
    
    void testRemoveItem(void){
        Bag bag = Bag(5);
        TS_ASSERT_THROWS_ANYTHING(bag.removeItem(-1));
        TS_ASSERT_THROWS_ANYTHING(bag.removeItem(0));
        TS_ASSERT_THROWS_ANYTHING(bag.removeItem(1));
        
        bag.addItem(item1);
        bag.addItem(item2);
        bag.addItem(item3);
        bag.addItem(item4);
        bag.addItem(item5);
        
        bag.removeItem(2);
        
        TS_ASSERT_EQUALS(bag.getCurrentSize(),4);
        TS_ASSERT(bag.equals(bag2));
        
        TS_ASSERT_THROWS_ANYTHING(bag.removeItem(-1));
        TS_ASSERT_THROWS_ANYTHING(bag.removeItem(4));
        TS_ASSERT_THROWS_ANYTHING(bag.removeItem(5));
        TS_ASSERT_THROWS_NOTHING(bag.removeItem(3));
        
    }
    
    void testEquals(void){
        Bag bag = Bag(3);
        
        bag.addItem(item1);
        bag.addItem(item3);
        bag.addItem(item5);
        
        TS_ASSERT(bag.equals(bag1));
        
    }
    
};