
#include "Pokemon.h"
#include <stdexcept>
#include <iostream>

Pokemon::Pokemon(){}
Pokemon::Pokemon(std::string name, PokeType type, std::string imageLocation, int maxHp){
    setName(name);
    setType(type);
    setType2(NULL_TYPE);
    setMaxHp(maxHp);
    Status status = NONE;
    setStatus(status);
    setCurrentHp(maxHp);
    setImageLocation(imageLocation);
}

Pokemon::Pokemon(std::string name, PokeType type, PokeType type2 , std::string imageLocation, int maxHp){
    setName(name);
    setType(type);
    setType2(type2);
    setMaxHp(maxHp);
    Status status = NONE;
    setStatus(status);
    setCurrentHp(maxHp);
    setImageLocation(imageLocation);
}



std::string Pokemon::getName(){return name;}
PokeType Pokemon::getType(){return type1;}
PokeType Pokemon::getType2(){return type2;}
Status Pokemon::getStatus(){return status;}
std::vector<Attack*> Pokemon::getAttacks(){return attacks;}
//ofImage getSprite(){return sprite;}
int Pokemon::getMaxHp(){return maxHp;}
int Pokemon::getCurrentHp(){return currentHp;}

void Pokemon::setName(std::string newName){name = newName;}
void Pokemon::setType(PokeType newType){type1 = newType;}
void Pokemon::setType2(PokeType newType){type2 = newType;}
void Pokemon::setStatus(Status newStatus){status=newStatus;}

void Pokemon::addAttack(Attack *newAttack){
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


void Pokemon::setMaxHp(int newMaxHp){maxHp = newMaxHp;}
void Pokemon::setCurrentHp(int newCurrentHp){currentHp = newCurrentHp;}

bool Pokemon::equals(Pokemon otherPokemon){
    
        if (name != otherPokemon.getName()
            || type1 != otherPokemon.getType()
            || type2 != otherPokemon.getType2()
            || status != otherPokemon.getStatus()
            || maxHp != otherPokemon.getMaxHp()
            ||currentHp != otherPokemon.getCurrentHp()){
            
            return false;
        }
    
    for (int i = 0; i < attacks.size(); i++){
        if (!attacks.at(i)->equals(otherPokemon.getAttacks().at(i))){
            return false;
        }
    }
    
    return true;
            
}

std::string Pokemon::getJSON(){
    std::string json = "{ \"pokemon name\" : \"";
    json = json + this->getName();
    json = json + "\" } ";
    return json;
}

