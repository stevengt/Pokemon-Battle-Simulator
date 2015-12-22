
#pragma once

#include "Button.h"
#include "sio_client.h"
#include "ofApp.h"
#include "GlobalVariables.h"
#include <cstring>
#include <string>

class GameRoomButton : public Button {
private:
    ofApp *mainApp;
    bool roomInfoRecieved = false;
public:
    sio::client *client;
    GameRoomButton(int x, int y, int w, int h, sio::client *client, ofApp *mainApp);
    void setClient(sio::client *client);
    void setMainApp(ofApp *mainApp);
};