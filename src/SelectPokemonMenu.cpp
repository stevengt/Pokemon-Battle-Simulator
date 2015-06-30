
#include "SelectPokemonMenu.h"

SelectPokemonMenu::SelectPokemonMenu(ofApp &listener){
    setImage("images/pikachu.png");
    setListener(listener);
    //gui->add(computerBattle.set("Computer battle", false));
    //parentWindow = theParentWindow;
    setComputerButton();
    setOnlineButton();
}

void SelectPokemonMenu::test(){
    std::cout << "success";
}

ofImage SelectPokemonMenu::getImage(){return image;}
ofxButton SelectPokemonMenu::getComputerButton(){return computerButton;}
ofxButton SelectPokemonMenu::getOnlineButton(){return onlineButton;}

ofApp SelectPokemonMenu::getListener(){
    return *listener;
}

void SelectPokemonMenu::setListener(ofApp newListener){
    listener = &newListener;
}

void SelectPokemonMenu::setImage(std::string imageLocation){
    image = ofImage();
    image.loadImage(imageLocation);
}

void SelectPokemonMenu::setComputerButton(){
    
    computerButton = ofxButton();
    computerButton.setup("test", buttonWidth,buttonHeight);
    computerButton.setPosition(computerButtonLocation);
    computerButton.addListener(listener, &ofApp::computerBattlePressed);
    
}
void SelectPokemonMenu::setOnlineButton(){
    onlineButton = ofxButton();
    onlineButton.setup("test", buttonWidth,buttonHeight);
    onlineButton.setPosition(onlineButtonLocation);
    
}

void SelectPokemonMenu::draw(){
    image.draw(50, 50, imageWidth, imageHeight);
    computerButton.draw();
    onlineButton.draw();
}