
#pragma once

#include "Trainer.h"
#include "PlayerAction.h"

#include <vector>

class Battle {
protected:
    Trainer *trainer1;
    Trainer *trainer2;
    bool player1TookAction;
    bool player2TookAction;
    bool updating;
    PlayerAction *action1;
    PlayerAction *action2;
    std::vector<std::string> eventsLog;
public:
    Battle(Trainer *trainer1, Trainer *trainer2);
    void setTrainers(Trainer *newTrainer1, Trainer *newTrainer2);
    Trainer *getTrainer1();
    Trainer *getTrainer2();
    bool bothPlayersTookActions();
    virtual void updatePlayer1TookAction(bool newVal)=0;
    virtual void updatePlayer2TookAction(bool newVal)=0;
    virtual void updatePlayer1TookAction(PlayerAction *action)=0;
    virtual void updatePlayer2TookAction(PlayerAction *action)=0;
    void setUpdating(bool newVal);
    bool isUpdating();
    void addToLogs(std::string event);
    std::vector<std::string> getEventsLog();
    void executeActions();
};