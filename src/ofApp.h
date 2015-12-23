#pragma once
#define _ofApp
//#include "ofMain.h"
//#include "Screen.h"
//#include "ListOfScreens.h"
#include <vector>
#include <mutex>
//#include "OnlineBattle.h"
#include <iostream>
//#include "StartMenu.h"
//#include "SelectPokemonMenu.h"
//#include "BattleScreen.h"
//#include "SelectGameRoomScreen.h"
//#include "GlobalVariables.h"

#include <stdio.h>
#include <string.h>
//using Poco::Thread;

//class BattleScreen;
//class Battle;
//class OnlineBattle;

#include "ofMain.h"
//#include "Screen.h"
#include "ListOfScreens.h"
#include "BattleScreen.h"
#include "GlobalVariables.h"
#include "sio_client.h"

class Screen;
class Battle;
class StartMenu;
class SelectPokemonMenu;
class SelectGameRoomScreen;

using namespace sio;

class ofApp : public ofBaseApp {

private:
    
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void switchScreens(ScreenState newScreen);
        void switchToSelectPokemonMenu();
        void switchToStartMenu();
        void switchToBattleScreen(Battle *battle);
        void switchToSelectGameRoomScreen();
        std::vector<Screen*> screens;
        ofEvent<bool> computerBattle;
        bool isPaused;
        void addScreens();
        void setClient(sio::client *client);
        void clearClient();
        ScreenState currentScreen;

    
    std::mutex _lock;
    std::condition_variable_any _cond;
    bool connect_finish = false;
    sio::client *client = NULL;
};

