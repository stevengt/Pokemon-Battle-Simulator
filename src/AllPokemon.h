
#pragma once

#include "Pokemon.h"

class Pikachu : public Pokemon {
public:
    Pikachu() : Pokemon("Pikachu", ELECTRIC, "images/pikachu.png", 80){
        addAttack(new Attack("Thunderbolt", ELECTRIC, 30, 10));
        addAttack(new Attack("Slam", NORMAL, 20, 15));
        addAttack(new Attack("Spark", ELECTRIC, 35, 5));
        addAttack(new Attack("Double Slap", NORMAL, 10, 10));
    }
};


//-----------------------------------------------------------------------------


class Charmander : public Pokemon {
public:
    Charmander() : Pokemon("Charmander", FIRE, "images/charmander.png", 80){
        addAttack(new Attack("Scratch", NORMAL, 20, 15));
        addAttack(new Attack("Ember", FIRE, 40, 7));
        addAttack(new Attack("Ancient Power", ROCK, 25, 5));
        addAttack(new Attack("Crunch", DARK, 20, 10));
    }
};


//-----------------------------------------------------------------------------


class Squirtle : public Pokemon {
public:
    Squirtle() : Pokemon("Squirtle", WATER, "images/squirtle.png", 80){
        addAttack(new Attack("Water Gun", WATER, 30, 10));
        addAttack(new Attack("Tackle", NORMAL, 20, 15));
        addAttack(new Attack("Bite", DARK, 25, 5));
        addAttack(new Attack("Ice Beam", ICE, 25, 15));
    }
};