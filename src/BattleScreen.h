
#pragma once

#include "Battle.h"
#include "BattleImage.h"
#include "Screen.h"
#include "Button.h"
#include "MainButtonGroup.h"
#include "BattleScreenState.h"
#include "AttackButtonGroup.h"
#include "PokemonButtonGroup.h"
#include "EventsLogDisplay.h"

class BattleScreen : public Screen {
    
private:
    
    Battle *battle;
    BattleImage *activePokemon1;
    BattleImage *activePokemon2;
    EventsLogDisplay eventsLog;
    BattleScreenState currentState;
    ButtonGroup *buttons;

    
public:
    BattleScreen(Battle *battle);
    
    void setBattle(Battle *newBattle);
    Battle getBattle();
    void switchState(BattleScreenState newState);
    void mousePressed(int x, int y);
    void draw();
    void clear();
    void populate();
};