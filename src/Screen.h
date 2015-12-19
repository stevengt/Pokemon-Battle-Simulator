
#pragma once
#include "Drawable.h"

class ofApp;

class Screen : public Drawable {
public:
    virtual void populate()=0;
    virtual void mousePressed(int x, int y)=0;
};