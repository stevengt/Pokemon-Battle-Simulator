

#include "AttackAction.h"


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
std::string AttackAction::execute(){
    Pokemon *defendingPokemon = defendingTrainer->getActivePokemon();
    int newHp = defendingPokemon->getCurrentHp()-attack->getBaseDamage();
    std::string attackingPokemonName = attackingPokemon->getName();
    std::string defendingPokemonName = defendingPokemon->getName();
    std::ostringstream damageAmount;
    if(newHp < 0){
        newHp = 0;
        defendingPokemon->setCurrentHp(newHp);
        return defendingPokemonName + " died!";
    }
    defendingPokemon->setCurrentHp(newHp);
    attack->setCurrentPp(attack->getCurrentPp()-1);
    damageAmount << attack->getBaseDamage();
    return attackingPokemonName + " dealt " + damageAmount.str() + " damage to " + defendingPokemonName;
}