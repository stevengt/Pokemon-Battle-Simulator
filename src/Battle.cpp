

#include "Battle.h"
#include "HpAndPpItem.h"
#include "StatusItem.h"

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
    
    trainer1->getBag()->addItem(new HpAndPpItem("Potion", "Restore 20 HP", 20, HP));
    trainer1->getBag()->addItem(new HpAndPpItem("Potion", "Restore 20 HP", 20, HP));
    trainer1->getBag()->addItem(new HpAndPpItem("Super Potion", "Restore 40 HP", 40, HP));
    trainer1->getBag()->addItem(new HpAndPpItem("Super Potion", "Restore 40 HP", 40, HP));
    trainer1->getBag()->addItem(new HpAndPpItem("Ether", "Restore 10 PP", 10, PP));
    trainer1->getBag()->addItem(new HpAndPpItem("Potion", "Restore 20 HP", 20, HP));
    trainer1->getBag()->addItem(new HpAndPpItem("Potion", "Restore 20 HP", 20, HP));
    trainer1->getBag()->addItem(new StatusItem("Awaken", "Wakes up sleeping Pokemon", ASLEEP));
    trainer1->getBag()->addItem(new StatusItem("PRLYZ HEAL", "Heals paralysis", PARALYZED));
    trainer1->getBag()->addItem(new StatusItem("Awaken", "Wakes up sleeping Pokemon", ASLEEP));
}

