
#pragma once

#include "PlayerAction.h"
#include "HpAndPpItem.h"
#include "Pokemon.h"
#include "Trainer.h"

class HpAndPpItemAction : public PlayerAction {
private:
    Trainer *trainer;
    HpAndPpItem *item;
    Pokemon *pokemon;
    Attack *attack;
public:
    HpAndPpItemAction(Trainer *trainer, HpAndPpItem *item, Pokemon *pokemon);
    HpAndPpItemAction(Trainer *trainer, HpAndPpItem *item, Attack *attack);
    void setTrainer(Trainer *newTrainer);
    void setItem(HpAndPpItem *item);
    void setPokemon(Pokemon *pokemon);
    void setAttack(Attack *newAttack);
    std::string execute();
};