
#pragma once

#include "string"
#include "PokeType.h"

class Attack{
private:
    std::string attackName;
    PokeType type;
    int baseDamage;
    int maxPp;
    int currentPp;
    
public:
    Attack();
    Attack(std::string name, PokeType type, int baseDamage, int maxPp);
    std::string getName();
    PokeType getType();
    int getBaseDamage();
    int getMaxPp();
    int getCurrentPp();
    
    void setName(std::string newName);
    void setType(PokeType newType);
    void setBaseDamage(int newBaseDamage);
    void setMaxPp(int newMaxPp);
    void setCurrentPp(int newCurrentPp);
    
    bool equals(Attack otherAttack);
};