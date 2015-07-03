
#include "StartMenu.h"



StartMenu::StartMenu(){
    populate();
}

StartMenu::~StartMenu(){


    //image.~ofImage_();
    //computerButton->~ofxButton();
    //onlineButton->~ofxButton();
    computerButtonLocation.~ofPoint();
    onlineButtonLocation.~ofPoint();
    //onComputerButtonClick.~ofEvent();



}

ofImage StartMenu::getImage(){return image;}
//ofxButton StartMenu::getComputerButton(){return *computerButton;}
//ofxButton StartMenu::getOnlineButton(){return *onlineButton;}

Button StartMenu::getComputerButton(){return *computerButton;}
Button StartMenu::getOnlineButton(){return *onlineButton;}


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
    
//    computerButton = new ofxButton();
//    computerButton->setup("Computer Battle", buttonWidth,buttonHeight);
//    computerButton->setPosition(computerButtonLocation);
//    computerButton->addListener(listener, &ofApp::switchToSelectPokemonMenu);
    computerButton = new Button(computerButtonLocation.x,computerButtonLocation.y,buttonWidth,buttonHeight,"Computer");
    
}
void StartMenu::setOnlineButton(){
//    onlineButton = new ofxButton();
//    onlineButton->setup("Online", buttonWidth,buttonHeight);
//    onlineButton->setPosition(onlineButtonLocation);
    onlineButton = new Button(onlineButtonLocation.x,onlineButtonLocation.y,buttonWidth,buttonHeight,"Online");
    
}

void StartMenu::draw(){
    image.draw(50, 50, imageWidth, imageHeight);
    computerButton->draw();
    onlineButton->draw();
}

void StartMenu::clear(){
//    delete computerButton;
//    delete onlineButton;
    computerButton->clear();
    onlineButton->clear();
    //onComputerButtonClick.~ofEvent();
}

void StartMenu::populate(){
    setImage("images/startMenu.png");
    setListener(*GlobalVariables::globalApp);
    setOnlineButton();
    setComputerButton();
}

void StartMenu::mousePressed(int x, int y){
    if(computerButton->inside(x,y)){
        GlobalVariables::globalApp->switchToSelectPokemonMenu();
    }
}




