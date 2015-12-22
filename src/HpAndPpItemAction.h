
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
    int index;
    int itemIndex;
    bool isHpItem;
public:
    HpAndPpItemAction(Trainer *trainer, int itemIndex, int index, bool isHpItem);
    void setTrainer(Trainer *newTrainer);
    void setItem(int itemIndex);
    void setPokemon(int pokemonIndex);
    void setAttack(int attackIndex);
    std::vector<std::string> execute();
    std::string getJSON();
};