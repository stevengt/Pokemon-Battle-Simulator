
#pragma once

#include "Drawable.h"
#include "ofMain.h"

class Button : public Drawable {
private:
    ofGLProgrammableRenderer *renderer;
    ofRectangle *button;
    std::string text;
    int buttonX;
    int buttonY;
    int buttonWidth;
    int buttonHeight;
    static const int textOffset = 20;
    
    
public:
    Button(int x, int y, int w, int h, std::string text);
    ofRectangle getButton();
    void setText(std::string newText);
    void setButtonX(int x);
    void setButtonY(int y);
    void setButtonWidth(int width);
    void setButtonHeight(int height);
    bool inside(int x, int y);
    std::string getText();
    int getMinX();
    int getMaxX();
    int getMinY();
    int getMaxY();
    void draw();
    void clear();
};
