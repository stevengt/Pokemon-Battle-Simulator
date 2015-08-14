

#include "AttackAction.h"
#include "math.h"

AttackAction::AttackAction(Pokemon *attackingPokemon, Trainer *defendingTrainer, Attack *attack){
    setAttackingPokemon(attackingPokemon);
    setDefendingTrainer(defendingTrainer);
    setAttack(attack);
}
void AttackAction::setAttackingPokemon(Pokemon *newAttackingPokemon){
    attackingPokemon = newAttackingPokemon;
}
void AttackAction::setDefendingTrainer(Trainer *newDefendingTrainer){
    defendingTrainer = newDefendingTrainer;
}
void AttackAction::setAttack(Attack *newAttack){
    attack = newAttack;
}
std::vector<std::string> AttackAction::execute(){
    Pokemon *defendingPokemon = defendingTrainer->getActivePokemon();
    
   // float effectiveness = 1;
    float effectiveness = Effectiveness::attackingxDefendingChart[attack->getType()][defendingPokemon->getType()]
                            *Effectiveness::attackingxDefendingChart[attack->getType()][defendingPokemon->getType2()];
    float damage = attack->getBaseDamage() * effectiveness;
    int newHp = round(defendingPokemon->getCurrentHp() - damage);
    
    std::string attackingPokemonName = attackingPokemon->getName();
    std::string defendingPokemonName = defendingPokemon->getName();
    std::ostringstream damageAmount;
    
    
    //retVal.push_back(attackingPokemonName + " dealt " + damageAmount.str() + " damage to " + defendingPokemonName);
    
    retVal.push_back(attackingPokemonName + " used " + attack->getName());
    
    if (effectiveness == 0){
        retVal.push_back("It's ineffective...");
    } else if (effectiveness == 0.5 || effectiveness == 0.25){
        retVal.push_back("It's not very effective...");
    } else if (effectiveness == 2 || effectiveness == 4){
        retVal.push_back("It's super effective!");
    }
    
    
    if(newHp < 0){
        newHp = 0;
        defendingPokemon->setCurrentHp(newHp);
        retVal.push_back(defendingPokemonName + " died!");
    }
    
    defendingPokemon->setCurrentHp(newHp);
    attack->setCurrentPp(attack->getCurrentPp()-1);
    damageAmount << attack->getBaseDamage();
    
    
    return retVal;
}