
#include "BattleImage.h"

BattleImage::BattleImage(Pokemon *pokemon, bool isTrainer1){
    setImage(pokemon->getImageLocation());
    setPokemon(pokemon);
    setIsPlayer1(isTrainer1);
}

void BattleImage::setPokemon(Pokemon *newPokemon){
    pokemon = newPokemon;
    setImage(pokemon->getImageLocation());
}

void BattleImage::setImage(std::string imageLocation){
    image = ofImage();
    image.loadImage(imageLocation);
}

void BattleImage::setIsPlayer1(bool newVal){
    isTrainer1 = newVal;
}

Pokemon *BattleImage::getPokemon(){
    return pokemon;
}

void BattleImage::draw(){
    healthbarWidth = ( ( (pokemon->getCurrentHp()) / (pokemon->getMaxHp()) ) * imageWidth );
    if (isTrainer1){
        image.draw(imageLocation1X, imageLocation1Y, imageWidth, imageHeight);
        ofRect(imageLocation1X, imageLocation1Y + imageHeight + healthbarOffset, healthbarWidth, healthbarHeight);
    } else{
        image.draw(imageLocation2X, imageLocation2Y, imageWidth, imageHeight);
        ofRect(imageLocation2X, imageLocation2Y + imageHeight + healthbarOffset, healthbarWidth, healthbarHeight);
    }
    
}

void BattleImage::clear(){}