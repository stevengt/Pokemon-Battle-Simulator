
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

std::string SwitchPokemonAction::execute(){
    std::string oldPokemonName = trainer->getActivePokemon()->getName();
    trainer->setActivePokemon(newPokemonNum);
    std::string newPokemonName = trainer->getActivePokemon()->getName();
    return "Player switched out " + oldPokemonName + " for " + newPokemonName;
}