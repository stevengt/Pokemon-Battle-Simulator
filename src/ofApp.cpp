#include "ofApp.h"
#include <iostream>
#include "StartMenu.h"
#include "SelectPokemonMenu.h"
#include "BattleScreen.h"
#include "SelectGameRoomScreen.h"
#include "GlobalVariables.h"

#include <stdio.h>
#include <string.h>
#define EM(__O__) std::cout<<__O__<<std::endl




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
    switchScreens(START_MENU);
    
}

void ofApp::switchToSelectGameRoomScreen(){
    switchScreens(SELECT_GAME_ROOM);
    
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
