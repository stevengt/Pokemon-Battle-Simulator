
#include "OnlineBattle.h"
#include "ofApp.h"

OnlineBattle::OnlineBattle(Trainer *trainer1, Trainer *trainer2, sio::client *client) : Battle(trainer1, trainer2) {
    setClient(client);
    actionInfoRecieved = false;
    GlobalVariables::battle = this;
    GlobalVariables::setBattleEventListeners();
    
}

void OnlineBattle::setClient(sio::client *client){
    this->client = client;
}

int OnlineBattle::updatePlayer1TookAction(PlayerAction *action){
    action1 = action;
    
    client->socket()->emit("action taken", sio::string_message::create(action->getJSON()));
    
    GlobalVariables::globalApp->_lock.lock();
    while(!actionInfoRecieved)
    {
        GlobalVariables::globalApp->_cond.wait(GlobalVariables::globalApp->_lock);
    }
    actionInfoRecieved = false;
    GlobalVariables::globalApp->_lock.unlock();
    

    return executeActions(trainer1GoesFirst);
    
}

void OnlineBattle::updatePlayer1TookAction(bool nelVal){}

void OnlineBattle::updatePlayer2TookAction(bool newVal){}

int OnlineBattle::updatePlayer2TookAction(PlayerAction *action){}


sio::client *OnlineBattle::getClient(){
    return client;
}

bool OnlineBattle::getActionInfoRecieved(){
    return actionInfoRecieved;
}
void OnlineBattle::setActionInfoRecieved(bool newVal){
    actionInfoRecieved = newVal;
}

bool OnlineBattle::setTrainer1GoesFirst(bool newVal){
    trainer1GoesFirst = newVal;
}