
#pragma once

#include "Pokemon.h"
#include "Bag.h"
#include <vector>

class Trainer{

private:
    std::vector<Pokemon*> pokemon;
    int activePokemon;
    Bag *bag = NULL;
    
public:
    Trainer();
    Pokemon *getActivePokemon();
    int getActivePokemonIndex();
    void setActivePokemon(int pokemonNum);
    std::vector<Pokemon*>getAllPokemon();
    Pokemon *getPokemon(int pokemonNum);
    Bag *getBag();
    void addPokemon(Pokemon *newPokemon);
    void removePokemon(int pokemonNum);
    void setBag(Bag *newBag);
    bool equals(Trainer otherTrainer);
    std::string getJSON();
};

