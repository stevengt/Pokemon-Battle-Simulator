
#include "HpAndPpItemAction.h"

HpAndPpItemAction::HpAndPpItemAction(Trainer *trainer, int itemIndex, int index, bool isHpItem){
    setTrainer(trainer);
    setItem(itemIndex);
    this->isHpItem = isHpItem;
    if(isHpItem){
        setPokemon(index);
    } else {
        setAttack(index);
    }
}

void HpAndPpItemAction::setTrainer(Trainer *newTrainer){
    trainer = newTrainer;
}

void HpAndPpItemAction::setItem(int itemIndex){
    this->itemIndex = itemIndex;
    item = trainer->getBag()->getHpAndPpItems().at(itemIndex);
}

void HpAndPpItemAction::setPokemon(int pokemonIndex){
    this->index = pokemonIndex;
    pokemon = trainer->getPokemon(pokemonIndex);
}

void HpAndPpItemAction::setAttack(int attackIndex){
    this->index = attackIndex;
    attack = pokemon->getAttacks().at(attackIndex);
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


std::string HpAndPpItemAction::getJSON(){
    std::string json = "{ \"action type\" : \"HpAndPpItem\",";
    json = json + " \"isHpItem\" : ";
    json = json + (isHpItem ? "\"true\", " : "\"false\", ");
    json = json + "\"index\" : ";
    json = json + std::to_string(index);
    json = json + ", \"item index\" : ";
    json = json + std::to_string(itemIndex);
    json = json + "}";
    return json;
}