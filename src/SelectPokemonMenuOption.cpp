

#include "SelectPokemonMenuOption.h"

int SelectPokemonMenuOption::frameWidth = 1024 - SelectPokemonMenuOption::frameMargin; //1024 = dimensions of window, ofWidth() does not work for some reason.
int SelectPokemonMenuOption::frameHeight = 1024 - frameMargin;
int SelectPokemonMenuOption::cellWidth = imageWidth + imagePaddingRight;
int SelectPokemonMenuOption::cellHeight = imageHeight + imagePaddingBottom;

int SelectPokemonMenuOption::gridWidth = frameWidth / (cellWidth);
int SelectPokemonMenuOption::gridHeight = frameHeight / (cellHeight);
int SelectPokemonMenuOption::cellsPerRow = frameWidth / cellWidth;
int SelectPokemonMenuOption::cellsPerCol = frameHeight / cellHeight;
int SelectPokemonMenuOption::buttonOffset = imageHeight + 10;


SelectPokemonMenuOption::SelectPokemonMenuOption(){}

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
    button = new ofxToggle();
    button->setup(pokemonName,false);
    button->setShape(location.x, location.y+buttonOffset, buttonWidth, buttonHeight);
}

void SelectPokemonMenuOption::draw(){
    image.draw(location.x, location.y, imageWidth, imageHeight);
    button->draw();
}

void SelectPokemonMenuOption::clear(){
    image.~ofImage_();
    button->~ofxToggle();
    location.~ofPoint();
}
