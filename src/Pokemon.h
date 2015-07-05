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
    PokeType type;
    Status status;
    
    std::vector<Attack> attacks;
    //ofImage sprite;
    int level;
    int maxHp;
    int currentHp;
    
public:
    Pokemon();
    Pokemon(std::string name, PokeType type, std::string imageLocation, int maxHp);
    virtual Pokemon *clone() const;
    std::string getName();
    std::string getImageLocation();
    PokeType getType();
    Status getStatus();
    std::vector<Attack> getAttacks();
    //ofImage getSprite();
    int getMaxHp();
    int getCurrentHp();
    
    void setImageLocation(std::string newImageLocation);
    void setName(std::string newName);
    void setType(PokeType newType);
    void setStatus(Status newStatus);
    void addAttack(Attack newAttack);
    void removeAttack(int attackNum);
    //ofImage setSprite();
    void setMaxHp(int newMaxHp);
    void setCurrentHp(int newCurrentHp);
    bool equals(Pokemon otherPokemon);
    
};
