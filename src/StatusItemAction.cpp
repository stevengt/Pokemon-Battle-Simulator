

#include "StatusItemAction.h"

StatusItemAction::StatusItemAction(Trainer *trainer, StatusItem *item, Pokemon *pokemon){
    setTrainer(trainer);
    setItem(item);
    setPokemon(pokemon);
}

void StatusItemAction::setTrainer(Trainer *newTrainer){
    trainer = newTrainer;
}

void StatusItemAction::setItem(StatusItem *newItem){
    item = newItem;
}

void StatusItemAction::setPokemon(Pokemon *newPokemon){
    pokemon = newPokemon;
}

std::string StatusItemAction::execute(){
    
    Status status = item->getStatus();
    trainer->getBag()->removeItem(item);
    
    if (pokemon->getStatus() == status){
        pokemon->setStatus(NONE);
    } else {
        return "Player wasted a " + item->getName();
    }
    
    return "Player used " + item->getName();
    
}