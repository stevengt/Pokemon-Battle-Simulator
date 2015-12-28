
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
    int itemIndex;
    int pokemonIndex;
public:
    StatusItemAction(Trainer *trainer, int itemIndex, int pokemonIndex);
    void setTrainer(Trainer *newTrainer);
    void setItem(int itemIndex);
    void setPokemon(int pokemonIndex);
    std::vector<std::string> execute();
    std::string getJSON();
};