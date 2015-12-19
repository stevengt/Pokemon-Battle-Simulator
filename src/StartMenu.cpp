
#include "StartMenu.h"



StartMenu::StartMenu(ofApp *mainApp){
    setMainApp(mainApp);
    populate();
}


ofImage StartMenu::getImage(){return image;}


Button StartMenu::getComputerButton(){return *computerButton;}
Button StartMenu::getOnlineButton(){return *onlineButton;}


ofApp* StartMenu::getMainApp(){
    return mainApp;
}

void StartMenu::setMainApp(ofApp *mainApp){
    this->mainApp = mainApp;
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
    setOnlineButton();
    setComputerButton();
}

void StartMenu::mousePressed(int x, int y){
    if(computerButton->inside(x,y)){
        mainApp->switchToSelectPokemonMenu();
    }
}




