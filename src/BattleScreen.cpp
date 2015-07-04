
#include "BattleScreen.h"
#include "ofMain.h"
#include "PokeType.h"
#include "ItemButtonGroup.h"
#include "SwitchPokemonAction.h"
#include "AttackAction.h"

BattleScreen::BattleScreen(Battle *battle){
    setBattle(battle);
    activePokemon1 = new BattleImage(battle->getTrainer1(), true);
    activePokemon2 = new BattleImage(battle->getTrainer2(), false);
    
    currentState = MAIN_BUTTONS;
    
    buttons = new MainButtonGroup();
    
}


void BattleScreen::setBattle(Battle *newBattle){
    battle = newBattle;
}

Battle BattleScreen::getBattle(){
    return *battle;
}



void BattleScreen::populate(){}
void BattleScreen::mousePressed(int x, int y){
    if(!battle->isUpdating()){
        if(currentState == MAIN_BUTTONS){
            if (buttons->getButtons().at(0)->inside(x,y)){
                switchState(ATTACK_BUTTONS);
                return;
            } else if (buttons->getButtons().at(1)->inside(x,y)){
                switchState(POKEMON_BUTTONS);
                return;
            } else if (buttons->getButtons().at(2)->inside(x,y)){
                switchState(HP_AND_PP_BUTTONS);
                return;
            } else if (buttons->getButtons().at(3)->inside(x,y)){
                switchState(STATUS_BUTTONS);
                return;
            }
        
        } else if (currentState == POKEMON_BUTTONS){
            bool buttonPressed = false;
            if (buttons->getButtons().at(0)->inside(x,y)){
                battle->updatePlayer1TookAction(new SwitchPokemonAction(battle->getTrainer1(), 0));
                buttonPressed = true;
            } else if (buttons->getButtons().at(1)->inside(x,y)){
                 battle->updatePlayer1TookAction(new SwitchPokemonAction(battle->getTrainer1(), 1));
                buttonPressed = true;
            } else if (buttons->getButtons().at(2)->inside(x,y)){
                 battle->updatePlayer1TookAction(new SwitchPokemonAction(battle->getTrainer1(), 2));
                buttonPressed = true;
            } else if (buttons->getButtons().at(3)->inside(x,y)){
                battle->updatePlayer1TookAction(new SwitchPokemonAction(battle->getTrainer1(), 3));
                buttonPressed = true;
            } else if (buttons->getButtons().at(4)->inside(x,y)){
                battle->updatePlayer1TookAction(new SwitchPokemonAction(battle->getTrainer1(), 4));
                buttonPressed = true;
            } else if (buttons->getButtons().at(5)->inside(x,y)){
                battle->updatePlayer1TookAction(new SwitchPokemonAction(battle->getTrainer1(), 5));
                buttonPressed = true;
            }
            
            if (buttonPressed){
                switchState(MAIN_BUTTONS);
            }
        } else if (currentState == ATTACK_BUTTONS){
            bool buttonPressed = false;
            Pokemon *attackingPokemon = battle->getTrainer1()->getActivePokemon();
            Pokemon *defendingPokemon = battle->getTrainer2()->getActivePokemon();
            if (buttons->getButtons().at(0)->inside(x,y)){
                battle->updatePlayer1TookAction(new AttackAction(attackingPokemon,defendingPokemon,attackingPokemon->getAttacks().at(0)));
                buttonPressed = true;
            } else if (buttons->getButtons().at(1)->inside(x,y)){
                battle->updatePlayer1TookAction(new AttackAction(attackingPokemon,defendingPokemon,attackingPokemon->getAttacks().at(1)));
                buttonPressed = true;
            } else if (buttons->getButtons().at(2)->inside(x,y)){
                battle->updatePlayer1TookAction(new AttackAction(attackingPokemon,defendingPokemon,attackingPokemon->getAttacks().at(2)));
                buttonPressed = true;
            } else if (buttons->getButtons().at(3)->inside(x,y)){
                battle->updatePlayer1TookAction(new AttackAction(attackingPokemon,defendingPokemon,attackingPokemon->getAttacks().at(3)));
                buttonPressed = true;
            }
            if (buttonPressed){
                switchState(MAIN_BUTTONS);
            }
        }
    }
}

void BattleScreen::switchState(BattleScreenState newState){
    currentState = newState;
    buttons->clear();
    ofClear(200, 200, 200);
    switch (newState){
        case MAIN_BUTTONS:
            buttons = new MainButtonGroup();
            break;
        case ATTACK_BUTTONS:
            buttons = new AttackButtonGroup(activePokemon1->getTrainer()->getActivePokemon());
            break;
        case POKEMON_BUTTONS:
            buttons = new PokemonButtonGroup(battle->getTrainer1());
            break;
        case HP_AND_PP_BUTTONS:
            buttons = new ItemButtonGroup(battle->getTrainer1()->getBag(), true);
            break;
        case STATUS_BUTTONS:
            buttons = new ItemButtonGroup(battle->getTrainer1()->getBag(), false);
            break;
            
    }
}


void BattleScreen::draw(){
    activePokemon1->draw();
    activePokemon2->draw();
    buttons->draw();
}
void BattleScreen::clear(){}
