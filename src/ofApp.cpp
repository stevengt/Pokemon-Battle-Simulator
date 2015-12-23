#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundAuto(false);
    currentScreen = START_MENU;
    addScreens();
    isPaused = false;
    
}




//--------------------------------------------------------------
void ofApp::update(){

}


//--------------------------------------------------------------
void ofApp::draw(){

    if(!GlobalVariables::isUpdating){
        screens.at(currentScreen)->draw();
    }
}

void ofApp::addScreens(){
    screens.push_back(new StartMenu(this));
    screens.push_back(new SelectPokemonMenu(this));
    screens.push_back(new SelectGameRoomScreen(this));
}


void ofApp::switchToSelectPokemonMenu(){
    switchScreens(SELECT_POKEMON);

}


void ofApp::switchToStartMenu(){
    clearClient();
    switchScreens(START_MENU);
}

void ofApp::switchToSelectGameRoomScreen(){
    switchScreens(SELECT_GAME_ROOM);
    
}

void ofApp::switchToBattleScreen(Battle *battle){
    screens.push_back(new BattleScreen(battle, client));
    switchScreens(BATTLE_SCREEN);
}

void ofApp::switchScreens(ScreenState newScreen){
    GlobalVariables::isUpdating = true;
    this->screens.at(this->currentScreen)->clear();
    this->currentScreen = newScreen;
    this->screens.at(this->currentScreen)->populate();
    ofClear(200, 200, 200 );
    GlobalVariables::isUpdating = false;
}


void ofApp::setClient(sio::client *client){
    this->client = client;
}


void ofApp::clearClient(){
    this->client = NULL;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    this->screens.at(currentScreen)->mousePressed(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
