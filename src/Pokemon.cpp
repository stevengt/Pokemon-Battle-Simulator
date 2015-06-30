
#include "Pokemon.h"
#include <stdexcept>
#include <iostream>

Pokemon::Pokemon(){}
Pokemon::Pokemon(std::string name, PokeType type, std::string imageLocation, int level, int maxHp){
    setName(name);
    setType(type);
    setLevel(level);
    setMaxHp(maxHp);
    Status status = NONE;
    setStatus(status);
    setCurrentHp(maxHp);
}
std::string Pokemon::getName(){return name;}
PokeType Pokemon::getType(){return type;}
Status Pokemon::getStatus(){return status;}
std::vector<Attack> Pokemon::getAttacks(){return attacks;}
//ofImage getSprite(){return sprite;}
int Pokemon::getLevel(){return level;}
int Pokemon::getMaxHp(){return maxHp;}
int Pokemon::getCurrentHp(){return currentHp;}

void Pokemon::setName(std::string newName){name = newName;}
void Pokemon::setType(PokeType newType){type = newType;}
void Pokemon::setStatus(Status newStatus){status=newStatus;}

void Pokemon::addAttack(Attack newAttack){
    if(attacks.size() == 4){
        throw std::invalid_argument( "This Pokemon already has 4 attacks" );
    }
    attacks.push_back(newAttack);
}

void Pokemon::removeAttack(int attackNum){
    if (attacks.size() == 0){
        throw std::invalid_argument( "Nothing to remove" );
    }
    if (attackNum<0 || attackNum>=4){
        throw std::invalid_argument( "Invalid attack index" );
    }
    attacks.erase(attacks.begin() + attackNum);
}


//ofImage setSprite(){return sprite;}
void Pokemon::setLevel(int newLevel){level = newLevel;}
void Pokemon::setMaxHp(int newMaxHp){maxHp = newMaxHp;}
void Pokemon::setCurrentHp(int newCurrentHp){currentHp = newCurrentHp;}

bool Pokemon::equals(Pokemon otherPokemon){
    
        if (name != otherPokemon.getName()
            || type != otherPokemon.getType()
            || status != otherPokemon.getStatus()
            || level != otherPokemon.getLevel()
            || maxHp != otherPokemon.getMaxHp()
            ||currentHp != otherPokemon.getCurrentHp()){
            
            return false;
        }
    
    for (int i = 0; i < attacks.size(); i++){
        if (!attacks.at(i).equals(otherPokemon.getAttacks().at(i))){
            return false;
        }
    }
    
    return true;
            
}

