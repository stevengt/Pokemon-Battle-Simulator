

#include "GlobalVariables.h"
#include "ofApp.h"
#include "OnlineBattle.h"
#include <iostream>

using namespace sio;

namespace GlobalVariables{
  
    bool isUpdating = false;
    ofApp *globalApp;
    OnlineBattle *battle;
    void setBattleEventListeners(){
        battle->getClient()->socket()->on("action", sio::socket::event_listener_aux([&](string const& name, object_message::ptr const& data, bool isAck,message::list &ack_resp){
            GlobalVariables::globalApp->_lock.lock();
            std::string actionType = data->get_map()["action type"]->get_string();
            int index = data->get_map()["index"]->get_int();
            int itemIndex;
            bool isHpItem;
            battle->setTrainer1GoesFirst(data->get_map()["trainer1goesFirst"]->get_bool());
            
            if(actionType == "attack"){
                battle->setAction2(new AttackAction(battle->getTrainer2()->getActivePokemon(), battle->getTrainer1(), index));
            } else if(actionType == "HpAndPpItem"){
                itemIndex = data->get_map()["item index"]->get_int();
                printf("item index = %d\n", itemIndex);
                isHpItem = data->get_map()["isHpItem"]->get_string() == "true" ? true : false;
                battle->setAction2(new HpAndPpItemAction(battle->getTrainer2(), itemIndex, index, isHpItem));
            } else if(actionType == "StatusItem"){
                itemIndex = data->get_map()["item index"]->get_int();
                battle->setAction2(new StatusItemAction(battle->getTrainer2(), itemIndex, index));
            } else {
                battle->setAction2(new SwitchPokemonAction(battle->getTrainer2(), index));
            }
            
            battle->setActionInfoRecieved(true);
            GlobalVariables::globalApp->_cond.notify_all();
            GlobalVariables::globalApp->_lock.unlock();
        }));
        
        
        battle->getClient()->socket()->on("pokemon fainted", sio::socket::event_listener_aux([&](string const& name, object_message::ptr const& data, bool isAck,message::list &ack_resp){
            GlobalVariables::globalApp->_lock.lock();
            
            int index = data->get_map()["index"]->get_int();
            battle->setFaintedPokemonReplacementIndex(index);
            battle->setFaintedPokemonUpdated(true);

            GlobalVariables::globalApp->_cond.notify_all();
            GlobalVariables::globalApp->_lock.unlock();
        }));

        
        
    }

}