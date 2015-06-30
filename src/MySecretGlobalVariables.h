
#pragma once
#include <iostream>
#include "ofApp.h"

namespace MySecretGlobalVariables{
    extern bool *isUpdating;
    extern ofApp* globalApp;
//    
//    struct Init{
//        Init(){
//            
//            *isUpdating = false;
//            bool tmp;
//            isUpdating= &tmp;
//            *isUpdating = true;
//            std::cout << *isUpdating;
//            
//        }
//    } init_;
}
