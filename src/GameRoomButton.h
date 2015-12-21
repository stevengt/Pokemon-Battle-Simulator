
#pragma once

#include "Button.h"
#include "sio_client.h"
#include "ofApp.h"

#include <cstring>
#include <string>

class GameRoomButton : public Button {
private:
    sio::client *client;
    ofApp *mainApp;
    bool roomInfoRecieved = false;
public:
    GameRoomButton(int x, int y, int w, int h, sio::client *client, ofApp *mainApp);
    void setClient(sio::client *client);
    void setMainApp(ofApp *mainApp);
};