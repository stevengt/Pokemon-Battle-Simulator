

#include "AttackAction.h"


AttackAction::AttackAction(Pokemon *attackingPokemon, Pokemon *defendingPokemon, Attack attack){
    setAttackingPokemon(attackingPokemon);
    setDefendingPokemon(defendingPokemon);
    setAttack(attack);
}
void AttackAction::setAttackingPokemon(Pokemon *newAttackingPokemon){
    attackingPokemon = newAttackingPokemon;
}
void AttackAction::setDefendingPokemon(Pokemon *newDefendingPokemon){
    defendingPokemon = newDefendingPokemon;
}
void AttackAction::setAttack(Attack newAttack){
    attack = newAttack;
}
void AttackAction::execute(){
    int newHp = defendingPokemon->getCurrentHp()-attack.getBaseDamage();
    if(newHp < 0){ newHp = 0; }
    defendingPokemon->setCurrentHp(newHp);
}