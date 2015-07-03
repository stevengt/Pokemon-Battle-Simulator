
#pragma once

#include "ofMain.h"

#include "Drawable.h"
#include "Pokemon.h"

class BattleImage : public Drawable {
private:
    static const int imageLocation1X = 100;
    static const int imageLocation1Y = 400;
    static const int imageLocation2X = 600;
    static const int imageLocation2Y = 100;
    static const int imageWidth = 200;
    static const int imageHeight = 200;
    static const int healthbarHeight = 10;
    static const int healthbarOffset = 20;
    int healthbarWidth;
    Pokemon *pokemon;
    ofImage image;
    bool isTrainer1;
public:
    BattleImage(Pokemon *pokemon, bool isTrainer1);
    Pokemon *getPokemon();
    void setPokemon(Pokemon *newPokemon);
    void setImage(std::string imageLocation);
    void setIsPlayer1(bool newVal);
    void draw();
    void clear();
};