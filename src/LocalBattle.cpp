
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

int LocalBattle::updatePlayer1TookAction(PlayerAction *action){
    updatePlayer1TookAction(true);
    updatePlayer2TookAction(generateRandomeAction());
    action1 = action;
    updatePlayer1TookAction(false);
    updatePlayer1TookAction(false);
    return executeActions();
    
}
int LocalBattle::updatePlayer2TookAction(PlayerAction *action){
    action2 = action;
    return 0;
}

PlayerAction *LocalBattle::generateRandomeAction(){
    int randomNum1 = rand() % 10;
    int randomNum2;
    PlayerAction *action;
    
        if (randomNum1 < 1){
            randomNum2 = rand() % 6;
            if(trainer2->getAllPokemon().at(randomNum2)->getCurrentHp() == 0){
                int i = 0;
                while (trainer2->getAllPokemon().at(i)->getCurrentHp() == 0){
                    i++;
                }
                action = new SwitchPokemonAction(trainer2, i);
            } else {
                action = new SwitchPokemonAction(trainer2, randomNum2);
            }
        } else {
            randomNum2 = rand() % 4;
            action = new AttackAction(trainer2->getActivePokemon(),trainer1,trainer2->getActivePokemon()->getAttacks().at(randomNum2));
        }
    return action;
}