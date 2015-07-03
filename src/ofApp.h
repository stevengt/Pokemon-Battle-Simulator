#pragma once

#include "ofMain.h"
#include "Screen.h"
#include "ListOfScreens.h"
#include "ListOfScreens.h"
#include "Battle.h"
#include "BattleScreen.h"
#include <vector>
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
};

