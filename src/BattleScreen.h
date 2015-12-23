
#pragma once

#include "BattleImage.h"
#include "Screen.h"
#include "Button.h"
#include "MainButtonGroup.h"
#include "BattleScreenState.h"
#include "AttackButtonGroup.h"
#include "PokemonButtonGroup.h"
#include "EventsLogDisplay.h"
#include "ofMain.h"
#include "PokeType.h"
#include "ItemButtonGroup.h"
#include "SwitchPokemonAction.h"
#include "AttackAction.h"
#include "HpAndPpItemAction.h"
#include "StatusItemAction.h"
#include "EndGameButtonGroup.h"
#include "BattleReturnState.h"
#include "sio_client.h"

class Battle;

class BattleScreen : public Screen {
    
private:
    
    Battle *battle;
    BattleImage *activePokemon1;
    BattleImage *activePokemon2;
    EventsLogDisplay eventsLog;
    BattleScreenState currentState;
    ButtonGroup *buttons;
    sio::client *client;

    
public:
    BattleScreen(Battle *battle, sio::client *client);
    Battle *getBattle();
    void setBattle(Battle *newBattle);
    void switchState(BattleScreenState newState);
    void mousePressed(int x, int y);
    void draw();
    void clear();
    void populate();
    void switchPokemon();
    void setClient(sio::client *client);
};