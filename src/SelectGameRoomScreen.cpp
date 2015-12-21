
#include "SelectGameRoomScreen.h"
#include "AllPokemon.h"
#include "Battle.h"

SelectGameRoomScreen::SelectGameRoomScreen(ofApp *mainApp){
    setMainApp(mainApp);
    client = new sio::client();
    listener = new connection_listener(*client, mainApp);
    
    client->set_open_listener(std::bind(&connection_listener::on_connected, listener));
    client->set_close_listener(std::bind(&connection_listener::on_close, listener,std::placeholders::_1));
    client->set_fail_listener(std::bind(&connection_listener::on_fail, listener));
    client->connect("http://127.0.0.1:9093");
        mainApp->_lock.lock();
        if(!mainApp->connect_finish)
        {
            mainApp->_cond.wait(mainApp->_lock);
        }
        mainApp->_lock.unlock();
}

void SelectGameRoomScreen::setMainApp(ofApp *mainApp){
    this->mainApp = mainApp;
}

void SelectGameRoomScreen::addOptions(){
    options = new std::vector<GameRoomButton>();
    options->push_back(GameRoomButton(room1X, room1Y, buttonWidth, buttonHeight, client, mainApp));
    options->push_back(GameRoomButton(room2X, room2Y, buttonWidth, buttonHeight, client, mainApp));
    options->push_back(GameRoomButton(room3X, room3Y, buttonWidth, buttonHeight, client, mainApp));
    
}

void SelectGameRoomScreen::setContinueButton(){
    continueButton = new Button(continueButtonLocationX,continueButtonLocationY,buttonWidth,buttonHeight,"Continue");
    
}


void SelectGameRoomScreen::setBackButton(){
    
    backButton = new Button(backButtonLocationX,backButtonLocationY,buttonWidth,buttonHeight,"Back");
}


void SelectGameRoomScreen::draw(){
    backButton->draw();
    continueButton->draw();
    for(int i = 0; i < options->size() ;i++){
        options->at(i).draw();
    }
    if(warningMessage != NULL){
        warningMessage->draw();
    }
}

void SelectGameRoomScreen::clear(){
    delete continueButton;
    delete backButton;
    delete options;
    if (warningMessage != NULL){
        warningMessage = NULL;
    }
}



//bool SelectGameRoomScreen::optionIsSelected(int optionNum){
//    return options->at(optionNum).getButton()->getParameter().toString() == "1";
//}



void SelectGameRoomScreen::populate(){
    addOptions();
    setContinueButton();
    setBackButton();
}


bool SelectGameRoomScreen::selectionIsValid(){
    int count = 0;
//    for (int i = 0; i < options->size(); i++){
//        if(optionIsSelected(i)){
//            count++;
//        }
//    }
//    if (count == 6){
//        return true;
//    }
    return false;
}

void SelectGameRoomScreen::mousePressed(int x, int y){
    if(backButton->inside(x,y)){
        mainApp->switchToStartMenu();
    }
    if(continueButton->inside(x,y)){
        mainApp->switchToSelectPokemonMenu();
    }
    
}


