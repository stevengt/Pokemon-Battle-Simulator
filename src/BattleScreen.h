
#pragma once

#include "Battle.h"
#include "BattleImage.h"
#include "Screen.h"

class BattleScreen : public Screen {
    
private:
    Battle *battle;
    BattleImage *activePokemon1;
    BattleImage *activePokemon2;
    
public:
    BattleScreen(Battle *battle);
    
    void setBattle(Battle *newBattle);
    Battle getBattle();
    void mousePressed(int x, int y);
    void draw();
    void clear();
    void populate();
};