
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

void SwitchPokemonAction::execute(){
    trainer->setActivePokemon(newPokemonNum);
}