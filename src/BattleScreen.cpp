
#include "BattleScreen.h"
#include "ofMain.h"
#include "PokeType.h"
#include "ItemButtonGroup.h"

BattleScreen::BattleScreen(Battle *battle){
    setBattle(battle);
    activePokemon1 = new BattleImage(battle->getTrainer1()->getActivePokemon(), true);
    activePokemon2 = new BattleImage(battle->getTrainer2()->getActivePokemon(), false);
    
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
    
    if(currentState == MAIN_BUTTONS){
        if (buttons->getButtons().at(0)->inside(x,y)){
            switchToAttackButtons();
            return;
        } else if (buttons->getButtons().at(1)->inside(x,y)){
            switchToPokemonButtons();
            return;
        } else if (buttons->getButtons().at(2)->inside(x,y)){
            switchToHpAndPpItemButtons();
            return;
        } else if (buttons->getButtons().at(3)->inside(x,y)){
            switchToStatusItemButtons();
            return;
        }
        
    } else if (currentState == POKEMON_BUTTONS){
        if (buttons->getButtons().at(0)->inside(x,y)){
            activePokemon1->setPokemon(battle->getTrainer1()->getPokemon(0));
            switchToMainButtons();
        } else if (buttons->getButtons().at(1)->inside(x,y)){
            activePokemon1->setPokemon(battle->getTrainer1()->getPokemon(1));
            switchToMainButtons();
        } else if (buttons->getButtons().at(2)->inside(x,y)){
            activePokemon1->setPokemon(battle->getTrainer1()->getPokemon(2));
            switchToMainButtons();
        } else if (buttons->getButtons().at(3)->inside(x,y)){
            activePokemon1->setPokemon(battle->getTrainer1()->getPokemon(3));
            switchToMainButtons();
        } else if (buttons->getButtons().at(4)->inside(x,y)){
            activePokemon1->setPokemon(battle->getTrainer1()->getPokemon(4));
            switchToMainButtons();
        } else if (buttons->getButtons().at(5)->inside(x,y)){
            activePokemon1->setPokemon(battle->getTrainer1()->getPokemon(5));
            switchToMainButtons();
        } else if (buttons->getButtons().at(6)->inside(x,y)){
            activePokemon1->setPokemon(battle->getTrainer1()->getPokemon(6));
            switchToMainButtons();
        }
    }

}

void BattleScreen::switchToMainButtons(){
    currentState = MAIN_BUTTONS;
    buttons->clear();
    ofClear(200, 200, 200);
    buttons = new MainButtonGroup();
}

void BattleScreen::switchToAttackButtons(){
    currentState = ATTACK_BUTTONS;
    buttons->clear();
    ofClear(200, 200, 200);
    buttons = new AttackButtonGroup(activePokemon1->getPokemon());
}

void BattleScreen::switchToPokemonButtons(){
    currentState = POKEMON_BUTTONS;
    buttons->clear();
    ofClear(200, 200, 200);
    buttons = new PokemonButtonGroup(battle->getTrainer1());
}

void BattleScreen::switchToHpAndPpItemButtons(){
    currentState = HP_AND_PP_BUTTONS;
    buttons->clear();
    ofClear(200, 200, 200);
    buttons = new ItemButtonGroup(battle->getTrainer1()->getBag(), true);
}

void BattleScreen::switchToStatusItemButtons(){
    currentState = STATUS_BUTTONS;
    buttons->clear();
    ofClear(200, 200, 200);
    buttons = new ItemButtonGroup(battle->getTrainer1()->getBag(), false);
}

void BattleScreen::draw(){
    activePokemon1->draw();
    activePokemon2->draw();
    buttons->draw();
}
void BattleScreen::clear(){}
