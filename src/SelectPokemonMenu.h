
#pragma once
#include "ofxButton.h"
#include "ofxLabel.h"
#include "ofMain.h"
#include "Screen.h"
#include "ofMain.h"
#include "ofApp.h"
#include "ofxGui.h"
#include "SelectPokemonMenuOption.h"
#include "GlobalVariables.h"

#include <iostream>
#include <vector>

class SelectPokemonMenu : public Screen {
    
private:
    ofApp *listener;
    //ofxButton button;
    SelectPokemonMenuOption theOption;
public:
    
    std::vector<SelectPokemonMenuOption> options;

    SelectPokemonMenu();
    
    void setListener(ofApp newListener);
 
    void draw();
    
    void clear();
};
