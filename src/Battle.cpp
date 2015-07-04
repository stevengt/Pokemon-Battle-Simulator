

#include "Battle.h"
#include "HpAndPpItem.h"
#include "StatusItem.h"

Battle::Battle(Trainer *trainer1, Trainer *trainer2){
    setTrainers(trainer1, trainer2);
    trainer1->setActivePokemon(0);
    trainer2->setActivePokemon(1);
    updating = false;
}

Trainer *Battle::getTrainer1(){return trainer1;}
Trainer *Battle::getTrainer2(){return trainer2;}
bool Battle::bothPlayersTookActions(){return player1TookAction && player2TookAction;}

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

void Battle::setUpdating(bool newVal){updating = newVal;}

bool Battle::isUpdating(){
    return updating;
}

void Battle::executeActions(){
    action1->execute();
    action2->execute();
}
