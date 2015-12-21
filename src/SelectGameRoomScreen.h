#pragma once

#include "ofMain.h"
#include "Screen.h"
#include "ofMain.h"
#include "ofApp.h"
#include "ofxGui.h"
#include "SelectPokemonMenuOption.h"
#include "GlobalVariables.h"
#include "Button.h"
#include "LocalBattle.h"
#include <iostream>
#include <vector>

#include "GameRoomButton.h"
#include "ConnectionListener.h"

class SelectGameRoomScreen : public Screen {
    
private:
    ofApp *mainApp;
    Button *continueButton;
    Button *backButton;
    Button *warningMessage = NULL;
    sio::client *client;
    connection_listener *listener;
    static const int backButtonLocationX = 50;
    static const int backButtonLocationY = 700;
    static const int room1X = 50;
    static const int room1Y = 100;
    static const int room2X = 50;
    static const int room2Y = 300;
    static const int room3X = 50;
    static const int room3Y = 500;
    static const int continueButtonLocationX = 800;
    static const int continueButtonLocationY = 700;
    static const int buttonWidth = 200;
    static const int buttonHeight = 50;
    static const int textOffset = 10;
public:
    
    std::vector<GameRoomButton> *options;
    
    SelectGameRoomScreen(ofApp *mainApp);
    void setMainApp(ofApp *mainApp);
    void addOptions();
    void setContinueButton();
    void setBackButton();
    //bool optionIsSelected(int optionNum);
    void draw();
    void clear();
    void populate();
    void mousePressed(int x, int y);
    bool selectionIsValid();
    
};