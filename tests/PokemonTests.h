
#pragma once

#include <TestSuite.h>
#include "testVariables.h"

using namespace testVariables;

class PokemonTests : public CxxTest::TestSuite {
    
public:
    
    void testAddAttack(void) {
        Pokemon *pokemon = new Pokemon(pokemonName1, pokemonType1 , " ", pokemonLevel1, pokemonMaxHp1);
        
        pokemon->addAttack(attack1);
        pokemon->addAttack(attack2);
        TS_ASSERT_EQUALS(pokemon->getAttacks().size(), 2);
        
        pokemon->addAttack(attack4);
        TS_ASSERT(pokemon->equals(pokemon1));
        
        pokemon->addAttack(attack3);
        TS_ASSERT(pokemon->getAttacks().at(3).equals(attack3));
        TS_ASSERT_THROWS_ANYTHING(pokemon->addAttack(attack5));
        
    }
    
    void testRemoveAttack(void) {
        Pokemon *pokemon = new Pokemon(pokemonName1, pokemonType1 , " ", pokemonLevel1, pokemonMaxHp1);
        TS_ASSERT_THROWS_ANYTHING(pokemon->removeAttack(-1));
        TS_ASSERT_THROWS_ANYTHING(pokemon->removeAttack(0));
        TS_ASSERT_THROWS_ANYTHING(pokemon->removeAttack(1));
        
        pokemon->addAttack(attack1);
        pokemon->addAttack(attack2);
        pokemon->addAttack(attack3);
        pokemon->addAttack(attack4);
        
        pokemon->removeAttack(2);
        TS_ASSERT(pokemon->equals(pokemon1));
        TS_ASSERT_EQUALS(pokemon->getAttacks().size(),3);
        TS_ASSERT(pokemon->getAttacks().at(2).equals(attack4));
        
    }
    
};