
#include "GameRoomButton.h"
using namespace sio;

GameRoomButton::GameRoomButton(int x, int y, int w, int h, sio::client *client, ofApp *mainApp) : Button(x, y, w, h, ""){
    setClient(client);
    setMainApp(mainApp);

    
        client->socket()->on("room info", sio::socket::event_listener_aux([&](string const& name, object_message::ptr const& data, bool isAck,message::list &ack_resp){
            GlobalVariables::globalApp->_lock.lock();
            std::string roomInfo = data->get_map()["data"]->get_string();
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