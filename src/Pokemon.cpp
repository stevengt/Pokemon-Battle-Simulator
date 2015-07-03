
#include "Pokemon.h"
#include <stdexcept>
#include <iostream>

Pokemon::Pokemon(){}
Pokemon::Pokemon(std::string name, PokeType type, std::string imageLocation, int maxHp){
    setName(name);
    setType(type);
    setMaxHp(maxHp);
    Status status = NONE;
    setStatus(status);
    setCurrentHp(maxHp);
    setImageLocation(imageLocation);
}
std::string Pokemon::getName(){return name;}
PokeType Pokemon::getType(){return type;}
Status Pokemon::getStatus(){return status;}
std::vector<Attack> Pokemon::getAttacks(){return attacks;}
//ofImage getSprite(){return sprite;}
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

std::string Pokemon::getImageLocation(){
    return imageLocation;
}

void Pokemon::setImageLocation(std::string newImageLocation){
    imageLocation = newImageLocation;
}


//ofImage setSprite(){return sprite;}
void Pokemon::setMaxHp(int newMaxHp){maxHp = newMaxHp;}
void Pokemon::setCurrentHp(int newCurrentHp){currentHp = newCurrentHp;}

bool Pokemon::equals(Pokemon otherPokemon){
    
        if (name != otherPokemon.getName()
            || type != otherPokemon.getType()
            || status != otherPokemon.getStatus()
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

