
#include "BattleScreen.h"




BattleScreen::BattleScreen(Battle *battle){
    setBattle(battle);
    activePokemon1 = new BattleImage(battle->getTrainer1().getActivePokemon(), true);
    activePokemon2 = new BattleImage(battle->getTrainer2().getActivePokemon(), false);
}


void BattleScreen::setBattle(Battle *newBattle){
    battle = newBattle;
}

Battle BattleScreen::getBattle(){
    return *battle;
}

void BattleScreen::populate(){}
void BattleScreen::mousePressed(int x, int y){}
void BattleScreen::draw(){
    activePokemon1->draw();
    activePokemon2->draw();
}
void BattleScreen::clear(){}
