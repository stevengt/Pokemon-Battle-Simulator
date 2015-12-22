
#include "SelectGameRoomScreen.h"
#include "AllPokemon.h"
#include "Battle.h"

SelectGameRoomScreen::SelectGameRoomScreen(ofApp *mainApp){
    setMainApp(mainApp);
}

void SelectGameRoomScreen::setMainApp(ofApp *mainApp){
    this->mainApp = mainApp;
}

void SelectGameRoomScreen::addOptions(){
    
    if(client != nullptr){
        client->close();
        client->clear_con_listeners();
    }
    delete client;
    
    client = new sio::client();
    listener = new connection_listener(*client, mainApp);
    
    client->set_open_listener(std::bind(&connection_listener::on_connected, listener));
    client->set_close_listener(std::bind(&connection_listener::on_close, listener,std::placeholders::_1));
    client->set_fail_listener(std::bind(&connection_listener::on_fail, listener));
    client->connect("http://127.0.0.1:9093");
    mainApp->_lock.lock();
    while(!mainApp->connect_finish)
    {
        mainApp->_cond.wait(mainApp->_lock);
    }
    mainApp->_lock.unlock();

    options = new std::vector<GameRoomButton>();
    options->push_back(GameRoomButton(roomX, room1Y, buttonWidth, buttonHeight, client, mainApp));
    options->push_back(GameRoomButton(roomX, room1Y + 200, buttonWidth, buttonHeight, client, mainApp));
    options->push_back(GameRoomButton(roomX, room1Y + 400, buttonWidth, buttonHeight, client, mainApp));

}

void SelectGameRoomScreen::setBackButton(){
    
    backButton = new Button(backButtonLocationX,backButtonLocationY,buttonWidth,buttonHeight,"Back");
}


void SelectGameRoomScreen::draw(){
    backButton->draw();
    for(int i = 0; i < options->size() ;i++){
        options->at(i).draw();
    }
    if(warningMessage != NULL){
        warningMessage->draw();
    }
}

void SelectGameRoomScreen::clear(){
    delete backButton;
    delete options;
    if (warningMessage != NULL){
        warningMessage = NULL;
    }
}


void SelectGameRoomScreen::populate(){
    addOptions();
    setBackButton();
}


void SelectGameRoomScreen::mousePressed(int x, int y){
    for(int i = 0; i < options->size(); i++){
        if(options->at(i).inside(x, y)){
            mainApp->setClient(options->at(i).client);
            mainApp->switchToSelectPokemonMenu();
            return;
        }
    }
    if(backButton->inside(x,y)){
        mainApp->switchToStartMenu();
    }
    
}


