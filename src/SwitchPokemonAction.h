
#pragma once

#include "PlayerAction.h"
#include "Trainer.h"
class SwitchPokemonAction : public PlayerAction {
private:
    Trainer *trainer;
    int newPokemonNum;
public:
    SwitchPokemonAction(Trainer *trainer, int newPokemonNum);
    void setTrainer(Trainer *newTrainer);
    void setNewPokemonNum(int newVal);
    std::string execute();
};