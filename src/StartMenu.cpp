
#include "StartMenu.h"


StartMenu::StartMenu(){}
StartMenu::StartMenu(ofApp &listener){
    setImage("images/startMenu.png");
    setListener(listener);
    //gui->add(computerBattle.set("Computer battle", false));
    //parentWindow = theParentWindow;
    setComputerButton();
    setOnlineButton();
}

StartMenu::~StartMenu(){


    image.~ofImage_();
    computerButton.~ofxButton();
    onlineButton.~ofxButton();
    computerButtonLocation.~ofPoint();
    onlineButtonLocation.~ofPoint();
    onComputerButtonClick.~ofEvent();



}

ofImage StartMenu::getImage(){return image;}
ofxButton StartMenu::getComputerButton(){return computerButton;}
ofxButton StartMenu::getOnlineButton(){return onlineButton;}

ofApp StartMenu::getListener(){
    return *listener;
}

void StartMenu::setListener(ofApp newListener){
    listener = &newListener;
}

void StartMenu::setImage(std::string imageLocation){
    image = ofImage();
    image.loadImage(imageLocation);
}

void StartMenu::setComputerButton(){
    
    computerButton = ofxButton();
    computerButton.setup("Computer Battle", buttonWidth,buttonHeight);
    computerButton.setPosition(computerButtonLocation);
    computerButton.addListener(listener, &ofApp::computerBattlePressed);
    
}
void StartMenu::setOnlineButton(){
    onlineButton = ofxButton();
    onlineButton.setup("Online", buttonWidth,buttonHeight);
    onlineButton.setPosition(onlineButtonLocation);
    
}

void StartMenu::draw(){
    image.draw(50, 50, imageWidth, imageHeight);
    computerButton.draw();
    onlineButton.draw();
}

