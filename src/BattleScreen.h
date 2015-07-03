
#pragma once

#include "Battle.h"
#include "BattleImage.h"
#include "Screen.h"
#include "Button.h"
#include "MainButtonGroup.h"
#include "BattleScreenState.h"
#include "AttackButtonGroup.h"

class BattleScreen : public Screen {
    
private:
    
    Battle *battle;
    BattleImage *activePokemon1;
    BattleImage *activePokemon2;
    
    BattleScreenState currentState;
    ButtonGroup *buttons;

    
public:
    BattleScreen(Battle *battle);
    
    void setBattle(Battle *newBattle);
    Battle getBattle();
    void switchToAttackButtons();
    void mousePressed(int x, int y);
    void draw();
    void clear();
    void populate();
};