
#pragma once

#include "Pokemon.h"

class Pikachu : public Pokemon {
public:
    Pikachu() : Pokemon("Pikachu", ELECTRIC, "images/pikachu.png", 80){
        addAttack(Attack("Thunderbolt", ELECTRIC, 30, 10));
        addAttack(Attack("Slam", NORMAL, 20, 15));
        addAttack(Attack("Spark", ELECTRIC, 35, 5));
        addAttack(Attack("Double Slap", NORMAL, 10, 10));
    }
    Pokemon *clone() const { return new Pikachu(*this); }
};


//-----------------------------------------------------------------------------


class Charmander : public Pokemon {
public:
    Charmander() : Pokemon("Charmander", FIRE, "images/charmander.png", 80){
        addAttack(Attack("Scratch", NORMAL, 20, 15));
        addAttack(Attack("Ember", FIRE, 40, 7));
        addAttack(Attack("Ancient Power", ROCK, 25, 5));
        addAttack(Attack("Crunch", DARK, 20, 10));
    }
    Pokemon *clone() const { return new Charmander(*this); }
};


//-----------------------------------------------------------------------------


class Squirtle : public Pokemon {
public:
    Squirtle() : Pokemon("Squirtle", WATER, "images/squirtle.png", 80){
        addAttack(Attack("Water Gun", WATER, 30, 10));
        addAttack(Attack("Tackle", NORMAL, 20, 15));
        addAttack(Attack("Bite", DARK, 25, 5));
        addAttack(Attack("Ice Beam", ICE, 25, 15));
    }
    Pokemon *clone() const { return new Squirtle(*this); }
};