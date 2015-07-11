#pragma once

#include "Status.h"
#include "Attack.h"
#include "string"
#include "PokeType.h"
#include <vector>

class Pokemon{
    
private:
    std::string name;
    std::string imageLocation;
    PokeType type1;
    PokeType type2;
    Status status;
    
    std::vector<Attack*> attacks;
    int level;
    int maxHp;
    int currentHp;
    
public:
    Pokemon();
    Pokemon(std::string name, PokeType type, std::string imageLocation, int maxHp);
    Pokemon(std::string name, PokeType type1, PokeType type2, std::string imageLocation, int maxHp);
    std::string getName();
    std::string getImageLocation();
    PokeType getType();
    PokeType getType2();
    Status getStatus();
    std::vector<Attack*> getAttacks();
    int getMaxHp();
    int getCurrentHp();
    
    void setImageLocation(std::string newImageLocation);
    void setName(std::string newName);
    void setType(PokeType newType);
    void setType2(PokeType newType);
    void setStatus(Status newStatus);
    void addAttack(Attack *newAttack);
    void removeAttack(int attackNum);
    void setMaxHp(int newMaxHp);
    void setCurrentHp(int newCurrentHp);
    bool equals(Pokemon otherPokemon);
    
};
