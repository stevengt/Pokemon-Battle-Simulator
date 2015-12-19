
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
    ofApp *mainApp;
    Button *computerButton;
    Button *onlineButton;
    static const int imageWidth = 400;
    static const int imageHeight = 400;
    static const int buttonWidth = 200;
    static const int buttonHeight = 70;
    static const int computerButtonLocationX = 600;
    static const int computerButtonLocationY = 200;
    static const int onlineButtonLocationX = 600;
    static const int onlineButtonLocationY = 400;
    
public:
    StartMenu(ofApp *mainApp);
    ofImage getImage();
    Button getComputerButton();
    Button getOnlineButton();
    ofApp *getMainApp();
    
    void setMainApp(ofApp *mainApp);
    void setImage(std::string imageLocation);
    void setComputerButton();
    void setOnlineButton();
    void draw();
    void clear();
    void populate();
    void mousePressed(int x, int y);
};