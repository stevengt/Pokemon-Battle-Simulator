
#pragma once
#include "Battle.h"
#include "sio_client.h"
#include "AttackAction.h"
#include "HpAndPpItemAction.h"
#include "StatusItemAction.h"
#include "SwitchPokemonAction.h"


using namespace GlobalVariables;

class OnlineBattle : public Battle {
private:
    sio::client *client;
    bool actionInfoRecieved;
    bool trainer1GoesFirst;
public:
    OnlineBattle(Trainer *trainer1, Trainer *trainer2, sio::client *client);
    void setClient(sio::client *client);
    void updatePlayer1TookAction(bool newVal);
    int updatePlayer1TookAction(PlayerAction *action);
    void updatePlayer2TookAction(bool newVal);
    int updatePlayer2TookAction(PlayerAction *action);
    sio::client *getClient();
    bool getActionInfoRecieved();
    void setActionInfoRecieved(bool newVal);
    void setTrainer1GoesFirst(bool newVal);
    

};