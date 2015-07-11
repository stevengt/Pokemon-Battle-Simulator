
#pragma once

#include "Battle.h"
#include "PlayerAction.h"
class LocalBattle : public Battle {
    
public:
    LocalBattle(Trainer *trainer1, Trainer *trainer2);
    void updatePlayer1TookAction(bool newVal);
    void updatePlayer2TookAction(bool newVal);
    int updatePlayer1TookAction(PlayerAction *action);
    int updatePlayer2TookAction(PlayerAction *action);
    PlayerAction *generateRandomeAction();
};