#include "ofApp.h"
#include <iostream>
#include "StartMenu.h"
#include "SelectPokemonMenu.h"

#include "GlobalVariables.h"
//using namespace MySecretGlobalVariables;
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

    if(!*GlobalVariables::isUpdating){
        screens.at(currentScreen)->draw();
    }
}

void ofApp::addScreens(){
    screens.push_back(new StartMenu());
    screens.push_back(new SelectPokemonMenu());
}


void ofApp::switchToSelectPokemonMenu(){
    *GlobalVariables::isUpdating = true;
    GlobalVariables::globalApp->screens.at(GlobalVariables::globalApp->currentScreen)->clear();
    GlobalVariables::globalApp->currentScreen = SELECT_POKEMON;
    GlobalVariables::globalApp->screens.at(GlobalVariables::globalApp->currentScreen)->populate();
    ofClear(200, 200, 200 );
    *GlobalVariables::isUpdating = false;

}


void ofApp::switchToStartMenu(){
    *GlobalVariables::isUpdating = true;
    GlobalVariables::globalApp->screens.at(GlobalVariables::globalApp->currentScreen)->clear();;
    GlobalVariables::globalApp->currentScreen = START_MENU;
    GlobalVariables::globalApp->screens.at(GlobalVariables::globalApp->currentScreen)->populate();
    ofClear(200, 200, 200 );
    *GlobalVariables::isUpdating = false;
    
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
    GlobalVariables::globalApp->screens.at(currentScreen)->mousePressed(x,y);
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
