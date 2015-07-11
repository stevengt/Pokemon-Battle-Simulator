
#pragma once

#include <TestSuite.h>
#include "testVariables.h"

using namespace testVariables;

class AttackTests : public CxxTest::TestSuite {
    
public:
    
    void testEquals(void) {
        
        std::string attackName = "Thunderbolt";
        PokeType attackType = ELECTRIC;
        int attackBaseDamage = 30;
        int attackMaxPp = 15;
        
        Attack *attack = new Attack(attackName1, attackType1, attackBaseDamage1, attackMaxPp1);
        
        TS_ASSERT(attack->equals(attack1));
        TS_ASSERT(!attack->equals(attack2));
        
        attack->setName(attackName2);
        attack->setType(attackType2);
        attack->setBaseDamage(attackBaseDamage2);
        
        
        TS_ASSERT(!attack->equals(attack2));
        
        attack->setMaxPp(attackMaxPp2);
        TS_ASSERT(attack->equals(attack2));
        
    }
    
};