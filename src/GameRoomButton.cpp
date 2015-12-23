
#include "GameRoomButton.h"
using namespace sio;

int GameRoomButton::numButtons = 0;

GameRoomButton::GameRoomButton(int x, int y, int w, int h, sio::client *client, ofApp *mainApp) : Button(x, y, w, h, ""){
    setClient(client);
    setMainApp(mainApp);
    buttonId = numButtons;
    numButtons = (numButtons + 1) % 3;
    
        client->socket()->on("room info", sio::socket::event_listener_aux([&](string const& name, object_message::ptr const& data, bool isAck,message::list &ack_resp){
            GlobalVariables::globalApp->_lock.lock();
            std::string roomName = "room" + std::to_string(buttonId);
            std::string roomInfo = std::to_string(data->get_map()[roomName]->get_int());
            roomInfo = "Players : " + roomInfo;
            this->Button::setText(roomInfo);
            roomInfoRecieved = true;
            GlobalVariables::globalApp->_cond.notify_all();
            GlobalVariables::globalApp->_lock.unlock();
        }));
    
    client->socket()->emit("get room info");
    
        mainApp->_lock.lock();
        while(!roomInfoRecieved)
        {
            mainApp->_cond.wait(mainApp->_lock);
        }
        roomInfoRecieved = false;
        mainApp->_lock.unlock();
   
    
}


void GameRoomButton::setClient(sio::client *client){
    this->client = client;
}

void GameRoomButton::setMainApp(ofApp *mainApp){
    
    this->mainApp= mainApp;
}

int GameRoomButton::getId(){
    return buttonId;
}