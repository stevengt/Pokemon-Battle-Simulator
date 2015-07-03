
#pragma once
//#include "ofxButton.h"
//#include "ofxLabel.h"
#include "ofMain.h"
#include "Screen.h"
#include "ofMain.h"
#include "ofApp.h"
#include "ofxGui.h"
#include "SelectPokemonMenuOption.h"
#include "GlobalVariables.h"
#include "Button.h"
#include <iostream>
#include <vector>

class SelectPokemonMenu : public Screen {
    
private:
    ofApp *listener;
    Button *continueButton;
    Button *backButton;
    Button *warningMessage = NULL;
    static const int backButtonLocationX = 50;
    static const int backButtonLocationY = 700;
    static const int warningButtonLocationX = 350;
    static const int warningButtonLocationY = 700;
    static const int continueButtonLocationX = 800;
    static const int continueButtonLocationY = 700;
    static const int warningButtonWidth = 300;
    static const int buttonWidth = 200;
    static const int buttonHeight = 50;
    static const int textOffset = 10;
public:
    
    std::vector<SelectPokemonMenuOption> *options;

    SelectPokemonMenu();
    void setListener(ofApp newListener);
    void addOptions();
    void setContinueButton();
    void setBackButton();
    void setWarningMessage();
    void draw();
    void clear();
    void populate();
    void mousePressed(int x, int y);
    bool selectionIsValid();
};
