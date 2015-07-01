
#pragma once
#include "ofxButton.h"
#include "ofxLabel.h"
#include "ofMain.h"
#include "Screen.h"
#include "ofMain.h"
#include "ofApp.h"
#include "ofxGui.h"
#include "SelectPokemonMenuOption.h"
#include <iostream>
#include <vector>

class SelectPokemonMenu : public Screen {
    
private:
    
    
public:
    
    static std::vector<SelectPokemonMenuOption> options;
    
    SelectPokemonMenu(ofApp &listener);
 
    void draw();
};
