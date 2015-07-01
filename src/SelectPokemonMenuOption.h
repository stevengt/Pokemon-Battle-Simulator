
#pragma once

#include "ofMain.h"
#include "ofxButton.h"
#include "ofApp.h"
#include "GlobalVariables.h"

class SelectPokemonMenuOption{
private:
    ofImage image;
    ofxButton* button;
    static const int imageWidth = 150;
    static const int imageHeight = 150;
    static const int buttonWidth = 150;
    static const int buttonHeight = 50;
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
    
    
    
    ofParameter<ofPoint> location;
    
public:
    SelectPokemonMenuOption();
    SelectPokemonMenuOption(std::string imageLocation, std::string pokemonName, int numOfOptions);
    void setImage(std::string imageLocation);
    void setLocation(int numOfOptions);
    void setButton(std::string pokemonName);
    void draw();
    
};
