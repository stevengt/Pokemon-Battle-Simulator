
#pragma once

#include "ofMain.h"
#include "ofxButton.h"

class SelectPokemonMenuOption{
private:
    ofImage image;
    ofxButton button;
    static const int imageWidth = 200;
    static const int imageHeight = 200;
    static const int buttonWidth = 100;
    static const int buttonHeight = 50;
    static const int buttonOffset = 250;
    static const int frameMargin = 50;
    static const int imagePadding = 50;
    static int frameWidth;
    static int frameHeight;
    static int cellWidth;
    static int cellHeight;
    static int gridWidth;
    static int gridHeight;
    static int cellsPerRow;
    static int cellsPerCol;
    
    
    
    ofParameter<ofPoint> location;
    
public:
    SelectPokemonMenuOption(std::string imageLocation, std::string pokemonName, int numOfOptions);
    void setImage(std::string imageLocation);
    void setLocation(int numOfOptions);
    void setButton(std::string pokemonName);
    void draw();
    
};
