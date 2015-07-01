

#include "SelectPokemonMenuOption.h"

int SelectPokemonMenuOption::frameWidth = 1024 - SelectPokemonMenuOption::frameMargin; //1024 = dimensions of window
int SelectPokemonMenuOption::frameHeight = 1024 - frameMargin;
int SelectPokemonMenuOption::cellWidth = imageWidth + imagePadding;
int SelectPokemonMenuOption::cellHeight = imageHeight + imagePadding;

int SelectPokemonMenuOption::gridWidth = frameWidth / (cellWidth);
int SelectPokemonMenuOption::gridHeight = frameHeight / (cellHeight);
int SelectPokemonMenuOption::cellsPerRow = frameWidth / cellWidth;
int SelectPokemonMenuOption::cellsPerCol = frameHeight / cellHeight;



SelectPokemonMenuOption::SelectPokemonMenuOption(std::string imageLocation, std::string pokemonName, int numOfOptions){
    setLocation(numOfOptions);
    setImage(imageLocation);
    setButton(pokemonName);
    
}

void SelectPokemonMenuOption::setImage(std::string imageLocation){
        image = ofImage();
        image.loadImage(imageLocation);
}

void SelectPokemonMenuOption::setLocation(int numOfOptions){

   
    ofPoint gridPosition = ofPoint(numOfOptions % cellsPerRow, numOfOptions / gridWidth);
    location = ofPoint(frameMargin + (gridPosition.x)*(cellWidth), frameMargin+(gridPosition.y)*(cellHeight));

}

void SelectPokemonMenuOption::setButton(std::string pokemonName){
    button = ofxButton();
    button.setup(pokemonName, buttonWidth,buttonHeight);
    button.setPosition(location->x,location->y+buttonOffset);
    
    //computerButton.addListener(listener, &ofApp::computerBattlePressed);
}

void SelectPokemonMenuOption::draw(){
    image.draw(location->x, location->y, imageWidth, imageHeight);
    //button.draw();
}