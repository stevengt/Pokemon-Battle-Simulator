
#include "Trainer.h"
#include <stdexcept>


Trainer::Trainer(){}

std::vector<Pokemon> Trainer::getAllPokemon(){return pokemon;}

Pokemon Trainer::getPokemon(int pokemonNum){
    if(pokemonNum<0 || pokemonNum>5){
        throw std::invalid_argument( "Invalid Pokemon index" );
    }
    return pokemon[pokemonNum];
}

Bag Trainer::getBag(){return bag;}

void Trainer::addPokemon(Pokemon newPokemon){
    if(pokemon.size()>5){
        throw std::invalid_argument( "Already have 6 Pokemon" );
    }
    pokemon.push_back(newPokemon);
    }

void Trainer::removePokemon(int pokemonNum){
    if(pokemon.size() == 0){
        throw std::invalid_argument( "Nothing to remove" );
    }
    if(pokemonNum<0 || pokemonNum>5){
        throw std::invalid_argument( "Invalid Pokemon index" );
    }
    pokemon.erase(pokemon.begin() + pokemonNum);
}


void Trainer::setBag(Bag newBag){bag = newBag;}

bool Trainer::equals(Trainer otherTrainer){
    if(!bag.equals(otherTrainer.getBag())
       || pokemon.size() != otherTrainer.getAllPokemon().size()){
        return false;
    }
    for (int i = 0; i < pokemon.size(); i++){
        if (!pokemon.at(i).equals(otherTrainer.getAllPokemon().at(i))){
            return false;
        }
    }
    return true;
}