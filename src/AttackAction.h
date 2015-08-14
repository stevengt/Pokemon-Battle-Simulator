
#pragma once

#include "PlayerAction.h"
#include "Pokemon.h"
#include "Trainer.h"

#include <sstream>

class AttackAction : public PlayerAction {
private:
    Pokemon *attackingPokemon;
    Trainer *defendingTrainer;
    Attack *attack;
public:
    AttackAction(Pokemon *attackingPokemon, Trainer *defendingTrainer, Attack *attack);
    void setAttackingPokemon(Pokemon *newAttackingPokemon);
    void setDefendingTrainer(Trainer *newDefendingTrainer);
    void setAttack(Attack *newAttack);
    std::vector<std::string> execute();
};