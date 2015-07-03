
#pragma once

#include "Trainer.h"

class Battle {
private:
    Trainer *trainer1;
    Trainer *trainer2;
    int turnNum;
    
public:
    Battle(Trainer *trainer1, Trainer *trainer2);
    void setTrainers(Trainer *newTrainer1, Trainer *newTrainer2);
    Trainer *getTrainer1();
    Trainer *getTrainer2();
    bool getIsTrainer1Turn();
};