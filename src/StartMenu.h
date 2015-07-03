
#pragma once
//#include "ofxButton.h"
//#include "ofxLabel.h"
#include "ofMain.h"
#include "Screen.h"
#include "ofMain.h"
#include "ofApp.h"
#include "ofxGui.h"
#include "GlobalVariables.h"
#include "Button.h"
#include <iostream>

class StartMenu : public Screen {
    
private:
    ofImage image;
    ofApp *listener;
//    ofxButton *computerButton;
//    ofxButton *onlineButton;
    Button *computerButton;
    Button *onlineButton;
    int imageWidth = 400;
    int imageHeight = 400;
    int buttonWidth = 200;
    int buttonHeight = 70;
    ofPoint computerButtonLocation = ofPoint(600,200);
    ofPoint onlineButtonLocation = ofPoint(600,400);
    //ofEvent<bool> onComputerButtonClick;
    
public:
    StartMenu();
    ~StartMenu();
    ofImage getImage();
//    ofxButton getComputerButton();
//    ofxButton getOnlineButton();
    Button getComputerButton();
    Button getOnlineButton();
    ofApp getListener();
    
    void setListener(ofApp newListener);
    void setImage(std::string imageLocation);
    void setComputerButton();
    void setOnlineButton();
    void draw();
    void clear();
    void populate();
    void mousePressed(int x, int y);
};