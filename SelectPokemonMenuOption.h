
#pragma once

#include "ofMain.h"
#include "ofxToggle.h"
#include "ofApp.h"

#include "Pokemon.h"

#include "GlobalVariables.h"

class SelectPokemonMenuOption : public Drawable{
private:
    ofImage image;
    ofxToggle *button;
    static const int imageWidth = 100;
    static const int imageHeight = 100;
    static const int buttonWidth = 100;
    static const int buttonHeight = 20;
    static const int frameMargin = 50;
    static const int imagePaddingRight = 25;
    static const int imagePaddingBottom = 100;
    static int buttonOffset;
    static int frameWidth;
    static int frameHeight;
    static int cellWidth;
    static int cellHeight;
    static int gridWidth;
    static int gridHeight;
    static int cellsPerRow;
    static int cellsPerCol;
    ofPoint location;
    Pokemon *pokemon;
    
public:
    SelectPokemonMenuOption();
    SelectPokemonMenuOption(Pokemon *pokemon, int numOfOptions);
    void setImage(std::string imageLocation);
    void setLocation(int numOfOptions);
    ofxToggle *getButton();
    void setPokemon(Pokemon *newPokemon);
    Pokemon *getPokemon();
    void setButton(std::string pokemonName);
    void draw();
    void clear();
    
    
};
