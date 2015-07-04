
#pragma once

#include "PlayerAction.h"
#include "Pokemon.h"

class AttackAction : public PlayerAction {
private:
    Pokemon *attackingPokemon;
    Pokemon *defendingPokemon;
    Attack attack;
public:
    AttackAction(Pokemon *attackingPokemon, Pokemon *defendingPokemon, Attack attack);
    void setAttackingPokemon(Pokemon *newAttackingPokemon);
    void setDefendingPokemon(Pokemon *newDefendingPokemon);
    void setAttack(Attack newAttack);
    void execute();
};