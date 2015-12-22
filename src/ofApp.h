#pragma once

#include "ofMain.h"
#include "Screen.h"
#include "ListOfScreens.h"
#include "BattleScreen.h"
#include "Battle.h"
#include <vector>

#include <mutex>
#include "sio_client.h"

//using Poco::Thread;

class Screen;

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

