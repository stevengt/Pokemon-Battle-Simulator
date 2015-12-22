
#include "OnlineBattle.h"

OnlineBattle::OnlineBattle(Trainer *trainer1, Trainer *trainer2, sio::client *client) : Battle(trainer1, trainer2) {
    setClient(client);
}

void OnlineBattle::setClient(sio::client *client){
    this->client = client;
}

int OnlineBattle::updatePlayer1TookAction(PlayerAction *action){
    action1 = action;
    std::string actionJSON = action1->getJSON();
    bool actionInfoRecieved = false;
    client->socket()->on("action taken", sio::socket::event_listener_aux([&](string const& name, object_message::ptr const& data, bool isAck,message::list &ack_resp){
        GlobalVariables::globalApp->_lock.lock();
        std::string actionType = data->get_map()["action type"]->get_string();
        int index = data->get_map()["index"]->get_int();
        int itemIndex = data->get_map()["item index"]->get_int();
        bool isHpItem = data->get_map()["isHpItem"]->get_string() == "true" ? true : false;
        
        if(actionType == "attack"){
            action2 = new AttackAction(trainer2->getActivePokemon(), trainer1, index);
        } else if(actionType == "HpAndPpItem"){
            action2 = new HpAndPpItemAction(trainer2, itemIndex, index, isHpItem);
        } else if(actionType == "StatusItem"){
            action2 = new StatusItemAction(trainer2, itemIndex, index);
        } else {
            action2 = new SwitchPokemonAction(trainer2, index);
        }

        actionInfoRecieved = true;
        GlobalVariables::globalApp->_cond.notify_all();
        GlobalVariables::globalApp->_lock.unlock();
    }));
    
    client->socket()->emit("action taken", sio::string_message::create(action->getJSON()));
    
    GlobalVariables::globalApp->_lock.lock();
    while(!actionInfoRecieved)
    {
        GlobalVariables::globalApp->_cond.wait(GlobalVariables::globalApp->_lock);
    }
    GlobalVariables::globalApp->_lock.unlock();
    

    return executeActions();
    
}

void OnlineBattle::updatePlayer1TookAction(bool nelVal){}

void OnlineBattle::updatePlayer2TookAction(bool newVal){}

int OnlineBattle::updatePlayer2TookAction(PlayerAction *action){}
