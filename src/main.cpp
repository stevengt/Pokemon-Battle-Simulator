#include "ofMain.h"
#include "ofApp.h"
#include "GlobalVariables.h"
//#include "PokemonGlobal.cpp"

//========================================================================


int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
    
  //  app = new ofApp();
    bool tmp;
    GlobalVariables::isUpdating= &tmp;
    GlobalVariables::isUpdating = false;
    
    
    ofRunApp(new ofApp());

}
