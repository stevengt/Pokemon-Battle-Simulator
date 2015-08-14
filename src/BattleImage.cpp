
#include "BattleImage.h"

BattleImage::BattleImage(Trainer *trainer, bool isTrainer1){
    image = ofImage();
    setTrainer(trainer);
    setImage();
    setIsPlayer1(isTrainer1);
}

void BattleImage::setTrainer(Trainer *newTrainer){
    trainer = newTrainer;
}

void BattleImage::setImage(){
    image.loadImage(trainer->getActivePokemon()->getImageLocation());
}

void BattleImage::setIsPlayer1(bool newVal){
    isTrainer1 = newVal;
}

Trainer *BattleImage::getTrainer(){
    return trainer;
}

void BattleImage::draw(){
    setImage();
    healthbarWidth = ( ( (float)(trainer->getActivePokemon()->getCurrentHp()) / (trainer->getActivePokemon()->getMaxHp()) ) * imageWidth );
    if (isTrainer1){
        image.draw(imageLocation1X, imageLocation1Y, imageWidth, imageHeight);
        ofRect(imageLocation1X, imageLocation1Y + imageHeight + healthbarOffset, healthbarWidth, healthbarHeight);
    } else{
        image.draw(imageLocation2X, imageLocation2Y, imageWidth, imageHeight);
        ofRect(imageLocation2X, imageLocation2Y + imageHeight + healthbarOffset, healthbarWidth, healthbarHeight);
    }
    
}

void BattleImage::clear(){}