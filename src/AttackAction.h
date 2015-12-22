
#pragma once

#include "PlayerAction.h"
#include "Pokemon.h"
#include "Trainer.h"

#include <sstream>

class AttackAction : public PlayerAction {
private:
    Pokemon *attackingPokemon;
    Trainer *defendingTrainer;
    int attackIndex;
    Attack *attack;
public:
    AttackAction(Pokemon *attackingPokemon, Trainer *defendingTrainer, int attackIndex);
    void setAttackingPokemon(Pokemon *newAttackingPokemon);
    void setDefendingTrainer(Trainer *newDefendingTrainer);
    void setAttack(int newAttack);
    std::vector<std::string> execute();
    std::string getJSON();
};