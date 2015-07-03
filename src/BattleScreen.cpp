
#include "BattleScreen.h"
#include "ofMain.h"
#include "PokeType.h"


BattleScreen::BattleScreen(Battle *battle){
    setBattle(battle);
    activePokemon1 = new BattleImage(battle->getTrainer1().getActivePokemon(), true);
    activePokemon2 = new BattleImage(battle->getTrainer2().getActivePokemon(), false);
    
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
        if(buttons->getButtons().at(0)->inside(x,y)){
            switchToAttackButtons();
        }
    }

}

void BattleScreen::switchToAttackButtons(){
    currentState = ATTACK_BUTTONS;
    buttons->clear();
    ofClear(200, 200, 200);
    activePokemon1->getPokemon()->addAttack(Attack("Thunderbolt", ELECTRIC, 20, 10));
    buttons = new AttackButtonGroup(activePokemon1->getPokemon());
}

void BattleScreen::draw(){
    activePokemon1->draw();
    activePokemon2->draw();
    buttons->draw();
}
void BattleScreen::clear(){}
