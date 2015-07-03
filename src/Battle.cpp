

#include "Battle.h"

Battle::Battle(Trainer *trainer1, Trainer *trainer2){
    setTrainers(trainer1, trainer2);
    turnNum = 0;
    trainer1->setActivePokemon(0);
    trainer2->setActivePokemon(1);
}

Trainer *Battle::getTrainer1(){return trainer1;}
Trainer *Battle::getTrainer2(){return trainer2;}
bool Battle::getIsTrainer1Turn(){return turnNum % 2 ;}

void Battle::setTrainers(Trainer *newTrainer1, Trainer *newTrainer2){
    trainer1 = newTrainer1;
    trainer2 = newTrainer2;
}

