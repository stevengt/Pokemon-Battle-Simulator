#pragma once

#include "ofMain.h"
#include "Screen.h"
#include "ListOfScreens.h"
//#include "MySecretGlobalVariables.h"
//#include "MySecretGlobalVariables.h"
#include "ListOfScreens.h"
#include <vector>
class ofApp : public ofBaseApp {

private:
    
    //ofPtr<bool> isUpdating;
    
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
        //bool getUpdating();
        void computerBattlePressed();
        //std::auto_ptr<Screen> currentScreen;
        //Screen *currentScreen;
        //ofPtr<Screen> currentScreen;
        //std::shared_ptr<Screen> currentScreen;
        std::vector<Screen*> screens;
        ofEvent<bool> computerBattle;
        ScreenState currentState;
        //void* mem = malloc(1000);
        //sofPtr<bool> isUpdating;
    
        ScreenState currentScreen;
};

