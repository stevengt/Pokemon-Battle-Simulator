
#include "LocalBattle.h"
#include "AttackAction.h"

LocalBattle::LocalBattle(Trainer *trainer1, Trainer *trainer2) : Battle(trainer1, trainer2){}


void LocalBattle::updatePlayer1TookAction(bool newVal){
    player1TookAction = newVal;
    updatePlayer2TookAction(newVal);
    setUpdating(newVal);
}

void LocalBattle::updatePlayer2TookAction(bool newVal){player2TookAction = newVal;}

void LocalBattle::updatePlayer1TookAction(PlayerAction *action){
    updatePlayer1TookAction(true);
    updatePlayer2TookAction(new AttackAction(trainer2->getActivePokemon(),trainer1->getActivePokemon(),trainer2->getActivePokemon()->getAttacks().at(0)));
    action1 = action;
    executeActions();
    updatePlayer1TookAction(false);
    updatePlayer1TookAction(false);
    
}
void LocalBattle::updatePlayer2TookAction(PlayerAction *action){
    action2 = action;
}