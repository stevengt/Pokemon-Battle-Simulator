
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



//-----------------------------------------------------------------------------


class Bulbasaur : public Pokemon {
public:
    Bulbasaur() : Pokemon("Bulbasaur", GRASS, "images/bulbasaur.png", 80){
        addAttack(new Attack("Tackle", NORMAL, 20, 15));
        addAttack(new Attack("Vine Whip", GRASS, 25, 10));
        addAttack(new Attack("Posion Powder", POISON, 30, 5));
        addAttack(new Attack("Razor Leaf", GRASS, 35, 7));
    }
};



//-----------------------------------------------------------------------------


class Skarmory : public Pokemon {
public:
    Skarmory() : Pokemon("Skarmory", STEEL, FLYING, "images/skarmory.png", 100){
        addAttack(new Attack("Peck", FLYING, 25, 10));
        addAttack(new Attack("Air Cutter", FLYING, 40, 5));
        addAttack(new Attack("Steel Wing", STEEL, 40, 7));
        addAttack(new Attack("Fury Attack", NORMAL, 15, 15));
    }
};


//-----------------------------------------------------------------------------


class Ghastly : public Pokemon {
public:
    Ghastly() : Pokemon("Ghastly", GHOST, POISON, "images/ghastly.jpg", 100){
        addAttack(new Attack("Lick", GHOST, 15, 10));
        addAttack(new Attack("Sucker Punch", DARK, 40, 7));
        addAttack(new Attack("Shadow Ball", GHOST, 40, 5));
        addAttack(new Attack("Hidden Power", NORMAL, 15, 10));
    }
};

//-----------------------------------------------------------------------------


class Lotad : public Pokemon {
public:
    Lotad() : Pokemon("Lotad", WATER, GRASS, "images/lotad.png", 70){
        addAttack(new Attack("Bubble", WATER, 15, 10));
        addAttack(new Attack("Solar Beam", GRASS, 40, 5));
        addAttack(new Attack("Energy Ball", GRASS, 40, 7));
        addAttack(new Attack("Scald", WATER, 35, 5));
    }
};

//-----------------------------------------------------------------------------


class Magnemite : public Pokemon {
public:
    Magnemite() : Pokemon("Magnemite", STEEL, ELECTRIC, "images/magnemite.png", 70){
        addAttack(new Attack("Thunder", ELECTRIC, 35, 6));
        addAttack(new Attack("Hidden Power", NORMAL, 25, 10));
        addAttack(new Attack("Flash Cannon", STEEL, 40, 4));
        addAttack(new Attack("Tackle", NORMAL, 15, 15));
    }
};

//-----------------------------------------------------------------------------


class Jynx : public Pokemon {
public:
    Jynx() : Pokemon("Jynx", ICE, PSYCHIC, "images/jynx.png", 70){
        addAttack(new Attack("Draining Kiss", FAIRY, 35, 6));
        addAttack(new Attack("Pound", NORMAL, 25, 10));
        addAttack(new Attack("Lick", DARK, 15, 10));
        addAttack(new Attack("Ice Punch", ICE, 25, 15));
    }
};


//-----------------------------------------------------------------------------


class Sneasel : public Pokemon {
public:
    Sneasel() : Pokemon("Sneasel", ICE, DARK, "images/sneasel.png", 90){
        addAttack(new Attack("Scratch", DARK, 15, 15));
        addAttack(new Attack("Icy Wind", ICE, 25, 10));
        addAttack(new Attack("Metal Claw", STEEL, 15, 10));
        addAttack(new Attack("Feint Attack", DARK, 35, 7));
    }
};

//-----------------------------------------------------------------------------


class Aerodactyl : public Pokemon {
public:
    Aerodactyl() : Pokemon("Aerodactyl", ROCK, FLYING, "images/aerodactyl.png", 70){
        addAttack(new Attack("Iron Head", STEEL, 40, 6));
        addAttack(new Attack("Rock Slide", ROCK, 30, 10));
        addAttack(new Attack("Bite", DARK, 15, 10));
        addAttack(new Attack("Wing Attack", FLYING, 25, 15));
    }
};

//-----------------------------------------------------------------------------


class Axew : public Pokemon {
public:
    Axew() : Pokemon("Axew", DRAGON, "images/axew.png", 70){
        addAttack(new Attack("Scratch", NORMAL, 20, 10));
        addAttack(new Attack("Dual Chop", DRAGON, 30, 10));
        addAttack(new Attack("Assurance", DARK, 25, 15));
        addAttack(new Attack("Slash", NORMAL, 15, 15));
    }
};

//-----------------------------------------------------------------------------


class Absol : public Pokemon {
public:
    Absol() : Pokemon("Absol", DARK, "images/absol.png", 100){
        addAttack(new Attack("Futrue Sight", PSYCHIC, 35, 6));
        addAttack(new Attack("Bite", DARK, 20, 10));
        addAttack(new Attack("Night Slash", DARK, 25, 10));
        addAttack(new Attack("Razor Wind", NORMAL, 25, 15));
    }
};

//-----------------------------------------------------------------------------


class Clefairy : public Pokemon {
public:
    Clefairy() : Pokemon("Clefairy", FAIRY, "images/clefairy.png", 80){
        addAttack(new Attack("Moonblast", FAIRY, 35, 6));
        addAttack(new Attack("Pound", NORMAL, 25, 10));
        addAttack(new Attack("Stored Power", PSYCHIC, 10, 15));
        addAttack(new Attack("Meteor Mash", STEEL, 25, 15));
    }
};


class PokemonFactory {
    public:
    
    PokemonFactory(){}
    
    Pokemon* create(std::string name){
        if (name == "Pikachu"){ return new Pikachu(); }
        else if (name == "Charmander"){ return new Charmander(); }
        else if (name == "Squirtle"){ return new Squirtle(); }
        else if (name == "Bulbasaur"){ return new Bulbasaur(); }
        else if (name == "Skarmory"){return new Skarmory(); }
        else if (name == "Ghastly"){return new Ghastly(); }
        else if (name == "Lotad"){return new Lotad(); }
        else if (name == "Magnemite"){return new Magnemite(); }
        else if (name == "Jynx"){return new Jynx(); }
        else if (name == "Sneasel"){return new Sneasel(); }
        else if (name == "Aerodactyl"){return new Aerodactyl(); }
        else if (name == "Axew"){return new Axew(); }
        else if (name == "Absol"){return new Absol(); }
        else if (name == "Clefairy"){return new Clefairy(); }
        else { return nullptr; }

    }
    
};

