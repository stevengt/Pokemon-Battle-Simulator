
#pragma once
#include "ofxButton.h"
#include "ofxLabel.h"
#include "ofMain.h"
#include "Screen.h"
#include "ofMain.h"
#include "ofApp.h"
#include "ofxGui.h"

#include <iostream>

class SelectPokemonMenu : public Screen {
    
private:
    ofImage image;
    ofEvent<bool> computerScreen;
    ofApp *listener;
    ofxButton computerButton;
    ofxButton onlineButton;
    //ofParameter<bool> computerBattle;
    int imageWidth = 400;
    int imageHeight = 400;
    int buttonWidth = 200;
    int buttonHeight = 70;
    ofPoint computerButtonLocation = ofPoint(600,200);
    ofPoint onlineButtonLocation = ofPoint(600,400);
    ofEvent<bool> onComputerButtonClick;
    
public:
    
    SelectPokemonMenu(ofApp &listener);
    
    void test();
    
    ofImage getImage();
    ofxButton getComputerButton();
    ofxButton getOnlineButton();
    ofApp getListener();
    
    void setListener(ofApp newListener);
    void setImage(std::string imageLocation);
    void setComputerButton();
    void setOnlineButton();
    void draw();
};