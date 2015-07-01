#include "ofApp.h"
#include <iostream>
#include "StartMenu.h"
#include "SelectPokemonMenu.h"

#include "GlobalVariables.h"
//using namespace MySecretGlobalVariables;
//--------------------------------------------------------------
void ofApp::setup(){
    //void* mem = malloc(sizeof(StartMenu));
    currentState = START_MENU;
    //ofSetBackgroundAuto(false);
    //setUpdating(false);
//    bool tmp;
//    bool *atmp;
//    atmp = &tmp;
//    *atmp = true;
////    std::cout << *atmp;
//    MySecretGlobalVariables::isUpdating = ofPtr<bool>(atmp);
    //std::cout << MySecretGlobalVariables::isUpdating;
    ofSetBackgroundAuto(false);
    screens.push_back(new StartMenu());
    screens.push_back(new SelectPokemonMenu());
    currentScreen = START_MENU;
    isPaused = false;
    //currentScreen = ofPtr<Screen>(new StartMenu(*this));     //this line
    
    
    
    //std::shared_ptr<Screen> currentScreen(new StartMenu(*this));
    
    
    //PokemonGlobal::app = this;
    //currentScreen = (Screen*) malloc(1024);
    //currentScreen = new StartMenu(*this);
    //currentScreen = StartMenu(*this);
}

//--------------------------------------------------------------
void ofApp::update(){
//    if (currentState==SELECT_POKEMON){
//        std::cout << "test";
//        currentScreen.reset(new SelectPokemonMenu(*this));
//    }
}


//--------------------------------------------------------------
void ofApp::draw(){
    //std::cout << &currentScreen;
    //std::cout << "stopped";
    if(!*GlobalVariables::isUpdating){
        //std::cout << std::endl << this->currentScreen;
    //std::cout << *MySecretGlobalVariables::isUpdating;
        //screens.at(currentScreen)->test();
        screens.at(currentScreen)->draw();
    }
}

//void ofApp::setUpdating(bool newVal){
//    updating = newVal;
//}
//
//bool ofApp::getUpdating(){
//    return *isUpdating;
//}

void ofApp::computerBattlePressed(){
    currentState = SELECT_POKEMON;
    //std::cout << sizeof(*currentScreen);
    
    //delete currentScreen;
    //std::cout << MySecretGlobalVariables::isUpdating;
    *GlobalVariables::isUpdating = true;
    
    GlobalVariables::globalApp->screens.at(GlobalVariables::globalApp->currentScreen)->clear();;
    
    //GlobalVariables::globalApp->screens.at(GlobalVariables::globalApp->currentScreen)->clearButtons();
    //this->currentScreen.~ofPtr();
    //currentScreen.~ofPtr();
    //Screen *newScreen = new SelectPokemonMenu(*this);
    
    GlobalVariables::globalApp->currentScreen = SELECT_POKEMON;
    ofClear(200, 200, 200 );
    
    //currentScreen = ofPtr<Screen>(new SelectPokemonMenu(*this));  //only this line
    
    
    *GlobalVariables::isUpdating = false;
    //MySecretGlobalVariables::globalApp->screens.at(MySecretGlobalVariables::globalApp->currentScreen)->draw();
    //currentScreen.~ofPtr();
    //Screen *newScreen = new SelectPokemonMenu(*this);
    //currentScreen = newScreen;
    //*MySecretGlobalVariables::isUpdating = false;
    //std::cout << sizeof(*currentScreen);
    //delete currentScreen;
//    update();
    //delete[] currentScreen;
    //Screen *newScreen = new SelectPokemonMenu(*this);
    //ofClear(0,0,0);
    //currentScreen = new SelectPokemonMenu(*this);
    //currentScreen = newScreen;
   // updating = false;
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
