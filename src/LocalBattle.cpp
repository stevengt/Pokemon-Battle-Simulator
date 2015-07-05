
#include "LocalBattle.h"
#include "AttackAction.h"
#include "SwitchPokemonAction.h"

LocalBattle::LocalBattle(Trainer *trainer1, Trainer *trainer2) : Battle(trainer1, trainer2){}


void LocalBattle::updatePlayer1TookAction(bool newVal){
    player1TookAction = newVal;
    updatePlayer2TookAction(newVal);
    setUpdating(newVal);
}

void LocalBattle::updatePlayer2TookAction(bool newVal){player2TookAction = newVal;}

void LocalBattle::updatePlayer1TookAction(PlayerAction *action){
    updatePlayer1TookAction(true);
    updatePlayer2TookAction(generateRandomeAction());
    action1 = action;
    executeActions();
    updatePlayer1TookAction(false);
    updatePlayer1TookAction(false);
    
}
void LocalBattle::updatePlayer2TookAction(PlayerAction *action){
    action2 = action;
}

PlayerAction *LocalBattle::generateRandomeAction(){
    int randomNum1 = rand() % 2;
    int randomNum2;
    PlayerAction *action;
    switch (randomNum1){
        case 0:
            randomNum2 = rand() % 6;
            action = new SwitchPokemonAction(trainer2, randomNum2);
            break;
        case 1:
            randomNum2 = rand() % 4;
            action = new AttackAction(trainer2->getActivePokemon(),trainer1,trainer2->getActivePokemon()->getAttacks().at(randomNum2));
            break;
    }
    return action;
}