
#pragma once
#include "Drawable.h"

class ofApp;

class Screen : public Drawable {
protected:
    ofApp *mainApp;
public:
    Screen(ofApp *mainApp){ this->mainApp = mainApp; }
    virtual void populate()=0;
    virtual void mousePressed(int x, int y)=0;
};