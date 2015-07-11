
#pragma once

#include "PlayerAction.h"
#include "StatusItem.h"
#include "Pokemon.h"
#include "Trainer.h"

class StatusItemAction : public PlayerAction {
private:
    Trainer *trainer;
    StatusItem *item;
    Pokemon *pokemon;
public:
    StatusItemAction(Trainer *trainer, StatusItem *item, Pokemon *pokemon);
    void setTrainer(Trainer *newTrainer);
    void setItem(StatusItem *item);
    void setPokemon(Pokemon *pokemon);
    std::string execute();
};