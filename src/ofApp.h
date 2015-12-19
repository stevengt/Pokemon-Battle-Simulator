#pragma once

#include "ofMain.h"
#include "Screen.h"
#include "ListOfScreens.h"
#include "BattleScreen.h"
#include "Battle.h"
#include <vector>

#include "ofxLibwebsockets.h"

#include "SIOClient.h"


using Poco::Thread;

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
        std::vector<Screen*> screens;
        ofEvent<bool> computerBattle;
        bool isPaused;
        void addScreens();
        ScreenState currentScreen;


        ofxLibwebsockets::Client client;
    
        ofBuffer buff;
        ofMutex  mutex;
    
        // websocket methods
        void onConnect( ofxLibwebsockets::Event& args );
        void onOpen( ofxLibwebsockets::Event& args );
        void onClose( ofxLibwebsockets::Event& args );
        void onIdle( ofxLibwebsockets::Event& args );
        void onMessage( ofxLibwebsockets::Event& args );
        void onBroadcast( ofxLibwebsockets::Event& args );
    
};

