#include "ofApp.h"
#include <iostream>
#include "StartMenu.h"
#include "SelectPokemonMenu.h"
#include "BattleScreen.h"
#include "GlobalVariables.h"



//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundAuto(false);
    currentScreen = START_MENU;
    addScreens();
    isPaused = false;
    
    
//    // setup client @ port 9093
//    client.connect("localhost", 5000);
//    client.addListener(this);
//    client.send("Hello world!");
//
    
    
    SIOClient *sio = SIOClient::connect("http://localhost:9093");
    sio->send("Hello Socket.IO");
    
    
}



//--------------------------------------------------------------
void ofApp::onConnect( ofxLibwebsockets::Event& args ){
    ofLogVerbose()<<"on connected";
}

//--------------------------------------------------------------
void ofApp::onOpen( ofxLibwebsockets::Event& args ){
    ofLogVerbose()<<"on open";
}

//--------------------------------------------------------------
void ofApp::onClose( ofxLibwebsockets::Event& args ){
    ofLogVerbose()<<"on close";
}

//--------------------------------------------------------------
void ofApp::onIdle( ofxLibwebsockets::Event& args ){
    ofLogVerbose()<<"on idle";
}

//--------------------------------------------------------------
void ofApp::onMessage( ofxLibwebsockets::Event& args ){
    // need to load this next frame!    buff.clear();
    mutex.lock();
    buff.set(args.data.getData(), args.data.size());
    mutex.unlock();
}

//--------------------------------------------------------------
void ofApp::onBroadcast( ofxLibwebsockets::Event& args ){
    cout<<"got broadcast "<<args.message<<endl;
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
