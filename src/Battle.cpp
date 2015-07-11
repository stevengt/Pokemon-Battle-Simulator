

#include "Battle.h"
#include "HpAndPpItem.h"
#include "StatusItem.h"
#include "BattleScreen.h"
#include <unistd.h>


Battle::Battle(Trainer *trainer1, Trainer *trainer2){
    pokemon2Fainted = false;
    setTrainers(trainer1, trainer2);
    trainer1->setActivePokemon(0);
    trainer2->setActivePokemon(1);
    updating = false;
}

void Battle::registerListener(BattleScreen *newListener){
    listener = newListener;
}

Trainer *Battle::getTrainer1(){return trainer1;}
Trainer *Battle::getTrainer2(){return trainer2;}
bool Battle::bothPlayersTookActions(){return player1TookAction && player2TookAction;}

void Battle::setTrainers(Trainer *newTrainer1, Trainer *newTrainer2){
    trainer1 = newTrainer1;
    trainer2 = newTrainer2;
    
    trainer1->getBag()->addItem(new HpAndPpItem("Potion", "Restore 20 HP", 20, HP));
    trainer1->getBag()->addItem(new HpAndPpItem("Potion", "Restore 20 HP", 20, HP));
    trainer1->getBag()->addItem(new HpAndPpItem("Super Potion", "Restore 40 HP", 40, HP));
    trainer1->getBag()->addItem(new HpAndPpItem("Super Potion", "Restore 40 HP", 40, HP));
    trainer1->getBag()->addItem(new HpAndPpItem("Ether", "Restore 10 PP", 10, PP));
    trainer1->getBag()->addItem(new HpAndPpItem("Potion", "Restore 20 HP", 20, HP));
    trainer1->getBag()->addItem(new HpAndPpItem("Potion", "Restore 20 HP", 20, HP));
    trainer1->getBag()->addItem(new StatusItem("Awaken", "Wakes up sleeping Pokemon", ASLEEP));
    trainer1->getBag()->addItem(new StatusItem("PRLYZ HEAL", "Heals paralysis", PARALYZED));
    trainer1->getBag()->addItem(new StatusItem("Awaken", "Wakes up sleeping Pokemon", ASLEEP));
}

void Battle::setUpdating(bool newVal){updating = newVal;}

bool Battle::isUpdating(){
    return updating;
}

BattleReturnState Battle::executeActions(){
    
    
    int i = rand() % 2;
    BattleReturnState state;
    
    switch (i){
        case 0:
            state = executeAction(action1);
            
            if (state == EXECUTE_NEXT_ACTION){
                state = executeAction(action2);
                if(state != EXECUTE_NEXT_ACTION){
                    return state;
                }
            } else {
                return state;
            }
            
            
            return SWITCH_TO_MAIN_BUTTONS;
            break;
            
        case 1:
            state = executeAction(action2);
            
            if (state == EXECUTE_NEXT_ACTION){
                state = executeAction(action1);
                if(state != EXECUTE_NEXT_ACTION){
                    return state;
                }
            } else {
                return state;
            }
            
            
            return SWITCH_TO_MAIN_BUTTONS;
            break;
            
    }
}

BattleReturnState Battle::executeAction(PlayerAction *action){
    addToLogs(action->execute());
    
    if (trainerPokemonFainted(trainer1)){
        if(trainer2Won()){
            return PLAYER_LOST;
        }
        listener->switchPokemon();
        return SWITCH_POKEMON;
    } else if (trainerPokemonFainted(trainer2)){
        for ( int i = 0; i < 7; i++ ){
            
            if(i==6){
                return PLAYER_WON;
            }
            
            if (trainer2->getAllPokemon().at(i)->getCurrentHp() != 0) {
                trainer2->setActivePokemon(i);
                return SWITCH_TO_MAIN_BUTTONS;
            }
        }
    }
    
    return EXECUTE_NEXT_ACTION;

}



bool Battle::trainerPokemonFainted(Trainer *trainer){
    return trainer->getActivePokemon()->getCurrentHp() == 0;

}

bool Battle::trainer1Won(){
    for (int i = 0; i < 6; i++){
       if (trainer2->getAllPokemon().at(i)->getCurrentHp() != 0){
            return false;
        }
    }
    return true;
}


bool Battle::trainer2Won(){
    for (int i = 0; i < 6; i++){
        if (trainer1->getAllPokemon().at(i)->getCurrentHp() != 0){
            return false;
        }
    }
    return true;
}




void Battle::addToLogs(std::vector<std::string> events){
    
    for(int i = 0; i < events.size(); i++){
        std::string event = events.at(i);
        eventsLog.push_back(event);
        if (eventsLog.size() > 15){
            eventsLog.erase(eventsLog.begin());
        }
    }
    
}

std::vector<std::string> Battle::getEventsLog(){
    return eventsLog;
}
