
#pragma once

class BattleScreen;
class EventsLogDisplay;

#include "Trainer.h"
#include "PlayerAction.h"
#include <vector>
#include "BattleReturnState.h"
#include "GlobalVariables.h"
#include "HpAndPpItem.h"
#include "StatusItem.h"
#include "BattleScreen.h"
#include <unistd.h>

class Battle {
protected:
    Trainer *trainer1;
    Trainer *trainer2;
    bool pokemon1Fainted;
    bool pokemon2Fainted;
    bool player1TookAction;
    bool player2TookAction;
    bool updating;
    PlayerAction *action1;
    PlayerAction *action2;
    std::vector<std::string> *eventsLog;
    BattleScreen *listener;
    bool faintedPokemonUpdated;
    int faintedPokemonReplacementIndex;
    
public:
    bool trainer1Won();
    bool trainer2Won();
    Battle(Trainer *trainer1, Trainer *trainer2);
    void setTrainers(Trainer *newTrainer1, Trainer *newTrainer2);
    void registerListener(BattleScreen *newListener);
    Trainer *getTrainer1();
    Trainer *getTrainer2();
    void setAction1(PlayerAction *action);
    void setAction2(PlayerAction *action);
    bool bothPlayersTookActions();
    virtual void updatePlayer1TookAction(bool newVal)=0;
    virtual void updatePlayer2TookAction(bool newVal)=0;
    virtual int updatePlayer1TookAction(PlayerAction *action)=0;
    virtual int updatePlayer2TookAction(PlayerAction *action)=0;
    void setUpdating(bool newVal);
    bool isUpdating();
    void addToLogs(std::vector<std::string> events);
    std::vector<std::string> *getEventsLog();
    BattleReturnState executeActions();
    BattleReturnState executeActions(bool trainer1goesFirst);
    BattleReturnState executeAction(PlayerAction *action);
    bool trainerPokemonFainted(Trainer *trainer);
    void setFaintedPokemonUpdated(bool newVal);
    void setFaintedPokemonReplacementIndex(int newVal);
};