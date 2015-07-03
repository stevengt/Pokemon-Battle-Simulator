
#pragma once

#include <TestSuite.h>
#include "testVariables.h"

using namespace testVariables;

class TrainerTests : public CxxTest::TestSuite {
    
public:
    
    void testAddPokemon(void) {
        
        Trainer trainer = Trainer();
        
        trainer.addPokemon(pokemon1);
        trainer.addPokemon(pokemon2);
        trainer.addPokemon(pokemon3);
        trainer.addPokemon(pokemon4);
        trainer.addPokemon(pokemon5);
        trainer.addPokemon(pokemon6);
        
        TS_ASSERT(trainer.equals(trainer1));
        
        TS_ASSERT_THROWS_ANYTHING(trainer.addPokemon(pokemon5));
        
    }
    
    void testRemovePokemon(void) {
        
        Trainer trainer = Trainer();
        TS_ASSERT_THROWS_ANYTHING(trainer.removePokemon(-1));
        TS_ASSERT_THROWS_ANYTHING(trainer.removePokemon(0));
        TS_ASSERT_THROWS_ANYTHING(trainer.removePokemon(1));
        
        trainer.addPokemon(pokemon1);
        trainer.addPokemon(pokemon2);
        trainer.addPokemon(pokemon3);
        trainer.addPokemon(pokemon4);
        
        trainer.removePokemon(2);
        TS_ASSERT(trainer.equals(trainer2));
        TS_ASSERT_EQUALS(trainer.getAllPokemon().size(),3);
        TS_ASSERT(trainer.getPokemon(2)->equals(*pokemon4));
        
    }

    
};
