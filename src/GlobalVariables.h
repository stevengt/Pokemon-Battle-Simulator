
#pragma once
#include <iostream>
//#include "ofApp.h"

class ofApp;
class OnlineBattle;

namespace GlobalVariables{
    extern bool isUpdating;
    extern ofApp *globalApp;
    extern OnlineBattle *battle;
    void setBattleEventListeners();

    
    
}
