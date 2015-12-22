
#include "SwitchPokemonAction.h"


SwitchPokemonAction::SwitchPokemonAction(Trainer *trainer, int newPokemonNum){
    setTrainer(trainer);
    setNewPokemonNum(newPokemonNum);
}

void SwitchPokemonAction::setTrainer(Trainer *newTrainer){
    trainer = newTrainer;
}
void SwitchPokemonAction::setNewPokemonNum(int newVal){
    newPokemonNum = newVal;
}

std::vector<std::string> SwitchPokemonAction::execute(){
    std::string oldPokemonName = trainer->getActivePokemon()->getName();
    trainer->setActivePokemon(newPokemonNum);
    std::string newPokemonName = trainer->getActivePokemon()->getName();
    retVal.push_back("Player switched out " + oldPokemonName + " for " + newPokemonName);
    return retVal;
}

std::string SwitchPokemonAction::getJSON(){
    std::string json = "{ \"action type\" :\"switch pokemon\",";
    json = json + "\"index\" : ";
    json = json + std::to_string(newPokemonNum);
    json = json + "}";
    return json;
}