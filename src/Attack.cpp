
#include "Attack.h"
#include <iostream>

Attack::Attack(){};
Attack::Attack(std::string name, PokeType type, int baseDamage, int maxPp){
    setName(name);
    setType(type);
    setBaseDamage(baseDamage);
    setMaxPp(maxPp);
    setCurrentPp(maxPp);
}

std::string Attack::getName(){return attackName;}
PokeType Attack::getType(){return type;}
int Attack::getBaseDamage(){return baseDamage;}
int Attack::getMaxPp(){return maxPp;}
int Attack::getCurrentPp(){return currentPp;}


void Attack::setName(std::string newName){attackName = newName;}
void Attack::setType(PokeType newType){type = newType;}
void Attack::setBaseDamage(int newBaseDamage){baseDamage = newBaseDamage;}
void Attack::setMaxPp(int newMaxPp){
    maxPp = newMaxPp;
    setCurrentPp(newMaxPp);
}
void Attack::setCurrentPp(int newCurrentPp){currentPp = newCurrentPp;};

bool Attack::equals(Attack otherAttack){
    
    return (attackName == otherAttack.getName()
            && type == otherAttack.getType()
            && baseDamage == otherAttack.getBaseDamage()
            && maxPp == otherAttack.getMaxPp()
            && currentPp == otherAttack.getCurrentPp());
}