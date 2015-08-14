
#include "StartMenu.h"



StartMenu::StartMenu(){
    populate();
}


ofImage StartMenu::getImage(){return image;}


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

    computerButton = new Button(computerButtonLocationX,computerButtonLocationY,buttonWidth,buttonHeight,"Computer");
    
}

void StartMenu::setOnlineButton(){

    onlineButton = new Button(onlineButtonLocationX,onlineButtonLocationY,buttonWidth,buttonHeight,"Online");
    
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




