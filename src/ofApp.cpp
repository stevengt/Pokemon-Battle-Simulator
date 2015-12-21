#include "ofApp.h"
#include <iostream>
#include "StartMenu.h"
#include "SelectPokemonMenu.h"
#include "BattleScreen.h"
#include "GlobalVariables.h"


typedef std::function<void(void)> con_listener;


void OnMessage(sio::event &l)
{
    std::cout << l.get_message();
}




//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundAuto(false);
    currentScreen = START_MENU;
    addScreens();
    isPaused = false;
    
    
    sio::client h;
    //h.socket()->on("message", &OnMessage);
    
    h.connect("http://127.0.0.1:9093");
    h.socket()->emit("message", sio::string_message::create("stevengt"));
    
    //h.socket()->emit("message");
    
    
    
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
}


void ofApp::switchToSelectPokemonMenu(){
    switchScreens(SELECT_POKEMON);

}


void ofApp::switchToStartMenu(){
    switchScreens(START_MENU);
    
}

void ofApp::switchToBattleScreen(Battle *battle){
    screens.push_back(new BattleScreen(battle));
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
