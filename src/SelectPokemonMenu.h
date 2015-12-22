
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
#include "LocalBattle.h"
#include "OnlineBattle.h"
#include <iostream>
#include <vector>

using namespace sio;

class SelectPokemonMenu : public Screen {
    
private:
    ofApp *mainApp;
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

    SelectPokemonMenu(ofApp *mainApp);
    void setMainApp(ofApp *mainApp);
    void addOptions();
    void setContinueButton();
    void setBackButton();
    void setWarningMessage();
    bool optionIsSelected(int optionNum);
    Battle *makeBattle();
    Trainer *initializeTrainer(bool isTrainer1);
    void draw();
    void clear();
    void populate();
    void mousePressed(int x, int y);
    bool selectionIsValid();
};
