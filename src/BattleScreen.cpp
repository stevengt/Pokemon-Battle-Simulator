#include "BattleScreen.h"
#include "Battle.h"
#include "ofApp.h"

BattleScreen::BattleScreen(Battle *battle, ofApp *mainApp) : Screen(mainApp) {
    setBattle(battle);
    battle->registerListener(this);
    activePokemon1 = new BattleImage(battle->getTrainer1(), true);
    activePokemon2 = new BattleImage(battle->getTrainer2(), false);
    eventsLog = EventsLogDisplay(battle->getEventsLog());
    currentState = MAIN_BUTTONS;
    
    buttons = new MainButtonGroup();
    
}

void BattleScreen::setBattle(Battle *newBattle){
    battle = newBattle;
}




void BattleScreen::populate(){}

void BattleScreen::mousePressed(int x, int y){
    if(!battle->isUpdating()){
        bool buttonPressed = false;
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
        
        } else if (currentState == REPLACE_POKEMON_BUTTONS){
            Trainer *trainer1 = battle->getTrainer1();
            Pokemon *activePokemon = battle->getTrainer1()->getActivePokemon();
            for (int i = 0; i < 6; i++){
                if (buttons->getButtons().at(i)->inside(x,y) && trainer1->getAllPokemon().at(i)->getCurrentHp() != 0){
                    trainer1->setActivePokemon(i);
                    if(mainApp->client != NULL){ mainApp->client->socket()->emit("pokemon fainted", sio::string_message::create(SwitchPokemonAction(trainer1, i).getJSON())); }
                    buttonPressed = true;
                    
                }
            }
            if (buttonPressed){
                switchState(MAIN_BUTTONS);
                return;
            }
        }
        
        else {
            if (currentState == POKEMON_BUTTONS){
            
                Trainer *trainer1 = battle->getTrainer1();
                Pokemon *activePokemon = battle->getTrainer1()->getActivePokemon();
                for (int i = 0; i < 6; i++){
                    if (buttons->getButtons().at(i)->inside(x,y) && trainer1->getAllPokemon().at(i) != activePokemon
                        && trainer1->getAllPokemon().at(i)->getCurrentHp() != 0){
                    
                        if(battle->updatePlayer1TookAction(new SwitchPokemonAction(trainer1, i))  == SWITCH_TO_MAIN_BUTTONS ){
                            buttonPressed = true;
                        }
                        
                    
                    }
                }
                if (buttonPressed){
                    switchState(MAIN_BUTTONS);
                    return;
                }
                
            } else if (currentState == ATTACK_BUTTONS){
                
                Pokemon *attackingPokemon = battle->getTrainer1()->getActivePokemon();
                Trainer *defendingTrainer = battle->getTrainer2();
                for (int i = 0; i < 4 ; i++){
                    if (buttons->getButtons().at(i)->inside(x,y) && attackingPokemon->getAttacks().at(i)->getCurrentPp() != 0){
                        if(battle->updatePlayer1TookAction(new AttackAction(attackingPokemon, defendingTrainer, i)) == SWITCH_TO_MAIN_BUTTONS ){
                            buttonPressed = true;

                        }
                    }
                }
                if (buttonPressed){
                    switchState(MAIN_BUTTONS);
                    return;
                }
                
            } else if (currentState == HP_AND_PP_BUTTONS){
                for (int i = 0; i < buttons->getButtons().size() ; i++){
                    if (buttons->getButtons().at(i)->inside(x,y)){
                        Trainer *trainer = battle->getTrainer1();
                        HpAndPpItem *item = trainer->getBag()->getHpAndPpItems().at(i);
                        if( battle->updatePlayer1TookAction(new HpAndPpItemAction(battle->getTrainer1(), i, trainer->getActivePokemonIndex(), item->getItemType() == HP ? true : false )) == SWITCH_TO_MAIN_BUTTONS ){
                            buttonPressed = true;
                        }
                       
                    }
                }
                if (buttonPressed){
                    switchState(MAIN_BUTTONS);
                    return;
                }
                
            } else if (currentState == STATUS_BUTTONS){
                for (int i = 0; i < buttons->getButtons().size() ; i++){
                    if (buttons->getButtons().at(i)->inside(x,y)){
                        Trainer *trainer = battle->getTrainer1();
                        StatusItem *item = trainer->getBag()->getStatusItems().at(i);
                        if(battle->updatePlayer1TookAction(new StatusItemAction(battle->getTrainer1(), i, trainer->getActivePokemonIndex())) == SWITCH_TO_MAIN_BUTTONS ){
                            buttonPressed = true;
                        }
                       
                    }
                }
                if (buttonPressed){
                    switchState(MAIN_BUTTONS);
                    return;
                }
            }
        }

    }
    if (battle->trainer1Won()){
        switchState(WIN);
    }
    if (battle->trainer2Won()){
        switchState(LOSE);
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
        case REPLACE_POKEMON_BUTTONS:
            buttons = new PokemonButtonGroup(battle->getTrainer1());
            break;
        case WIN:
            buttons = new EndGameButtonGroup(true);
            break;
        case LOSE:
            buttons = new EndGameButtonGroup(false);
            break;
            
    }
}

void BattleScreen::switchPokemon(){
    switchState(REPLACE_POKEMON_BUTTONS);
}


void BattleScreen::draw(){
    activePokemon1->draw();
    activePokemon2->draw();
    eventsLog.draw();
    buttons->draw();
}

void BattleScreen::clear(){}

Battle *BattleScreen::getBattle(){
    return battle;
}

