
#include "HpAndPpItemAction.h"

HpAndPpItemAction::HpAndPpItemAction(Trainer *trainer, HpAndPpItem *item, Pokemon *pokemon){
    setTrainer(trainer);
    setItem(item);
    setPokemon(pokemon);
}

HpAndPpItemAction::HpAndPpItemAction(Trainer *trainer, HpAndPpItem *item, Attack *attack){
    setTrainer(trainer);
    setItem(item);
    setAttack(attack);
}

void HpAndPpItemAction::setTrainer(Trainer *newTrainer){
    trainer = newTrainer;
}

void HpAndPpItemAction::setItem(HpAndPpItem *newItem){
    item = newItem;
}

void HpAndPpItemAction::setPokemon(Pokemon *newPokemon){
    pokemon = newPokemon;
}

void HpAndPpItemAction::setAttack(Attack *newAttack){
    attack = newAttack;
}

std::vector<std::string> HpAndPpItemAction::execute(){
    
    int restoreAmount = item->getRestoreAmount();
    if (item->getItemType() == HP){
        int currentHp = pokemon->getCurrentHp();
        int maxHp = pokemon->getMaxHp();
        int newHp = currentHp + restoreAmount;
        if (newHp > maxHp){
            pokemon->setCurrentHp(maxHp);
        } else {
            pokemon->setCurrentHp(newHp);
        }
    } else {
        int currentPp = attack->getCurrentPp();
        int maxPp = attack->getMaxPp();
        int newPp = currentPp + restoreAmount;
        if (newPp > maxPp){
            attack->setCurrentPp(maxPp);
        } else {
            attack->setCurrentPp(newPp);
        }
    }
    
    trainer->getBag()->removeItem(item);
    retVal.push_back("Player used " + item->getName());
    return retVal;
    
}