#pragma once

#include "Status.h"
#include "Attack.h"
#include "string"
#include "PokeType.h"
#include <vector>

class Pokemon{
    
private:
    std::string name;
    PokeType type;
    Status status;
    
    std::vector<Attack> attacks;
    //ofImage sprite;
    int level;
    int maxHp;
    int currentHp;
    
public:
    Pokemon();
    Pokemon(std::string name, PokeType type, std::string imageLocation, int level, int maxHp);
    std::string getName();
    PokeType getType();
    Status getStatus();
    std::vector<Attack> getAttacks();
    //ofImage getSprite();
    int getLevel();
    int getMaxHp();
    int getCurrentHp();
    
    void setName(std::string newName);
    void setType(PokeType newType);
    void setStatus(Status newStatus);
    void addAttack(Attack newAttack);
    void removeAttack(int attackNum);
    //ofImage setSprite();
    void setLevel(int newLevel);
    void setMaxHp(int newMaxHp);
    void setCurrentHp(int newCurrentHp);
    
    bool equals(Pokemon otherPokemon);
    
};
