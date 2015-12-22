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
    Button *backButton;
    Button *warningMessage = NULL;
    sio::client *client = nullptr;
    connection_listener *listener;
    static const int backButtonLocationX = 50;
    static const int backButtonLocationY = 700;
    static const int roomX = 50;
    static const int room1Y = 100;
    static const int buttonWidth = 200;
    static const int buttonHeight = 50;
    static const int textOffset = 10;
public:
    
    std::vector<GameRoomButton> *options;
    
    SelectGameRoomScreen(ofApp *mainApp);
    void setMainApp(ofApp *mainApp);
    void addOptions();
    void setBackButton();
    void draw();
    void clear();
    void populate();
    void mousePressed(int x, int y);
    
};