
#pragma once
#include <iostream>

class OnlineBattle;
class ofApp;

namespace GlobalVariables{
    extern bool isUpdating;
    extern ofApp *globalApp;
    extern OnlineBattle *battle;
    void setBattleEventListeners();

    
    
}
