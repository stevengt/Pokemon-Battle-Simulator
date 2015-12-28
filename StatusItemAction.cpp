

#include "StatusItemAction.h"

StatusItemAction::StatusItemAction(Trainer *trainer, int itemIndex, int pokemonIndex){
    setTrainer(trainer);
    setItem(itemIndex);
    setPokemon(pokemonIndex);
}

void StatusItemAction::setTrainer(Trainer *newTrainer){
    trainer = newTrainer;
}

void StatusItemAction::setItem(int itemIndex){
    this->itemIndex = itemIndex;
    item = trainer->getBag()->getStatusItems().at(itemIndex);
}

void StatusItemAction::setPokemon(int pokemonIndex){
    this->pokemonIndex = pokemonIndex;
    pokemon = trainer->getAllPokemon().at(pokemonIndex);
}

std::vector<std::string> StatusItemAction::execute(){
    
    Status status = item->getStatus();
    trainer->getBag()->removeItem(item);
    
    if (pokemon->getStatus() == status){
        pokemon->setStatus(NONE);
    } else {
        retVal.push_back("Player wasted a " + item->getName());
        return retVal;
    }
    
    retVal.push_back("Player used " + item->getName());
    
    return retVal;
    
}


std::string StatusItemAction::getJSON(){
    std::string json = "{ \"action type\" : \"StatusItem\",";
    json = json + "\"index\" : ";
    json = json + std::to_string(pokemonIndex);
    json = json + ", \"item index\" : ";
    json = json + std::to_string(itemIndex);
    json = json + "}";
    return json;
}
