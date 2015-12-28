

#include "Button.h"

Button::Button(int x, int y, int w, int h, std::string text){
    button = new ofRectangle();
    setButtonX(x);
    setButtonY(y);
    setButtonHeight(h);
    setButtonWidth(w);
    setText(text);
}

void Button::setText(std::string newText){
    text = newText;
}

void Button::setButtonX(int x){
    buttonX = x;
}

void Button::setButtonWidth(int width){
    buttonWidth = width;
}

void Button::setButtonHeight(int height){
    buttonHeight = height;
}

std::string Button::getText(){
    return text;
}

void Button::setButtonY(int y){
    buttonY = y;
}

ofRectangle Button::getButton(){
    return *button;
}

int Button::getMinX(){
    return MIN(buttonX, buttonX + buttonWidth);
}

int Button::getMaxX(){
    return MAX(buttonX, buttonX + buttonWidth);
}

int Button::getMinY(){
    return MIN(buttonY, buttonY + buttonHeight);
}

int Button::getMaxY(){
    return MAX(buttonY, buttonY + buttonHeight);
}

bool Button::inside(int x, int y){
    return x > getMinX() && y > getMinY() &&
    x < getMaxX() && y < getMaxY();
}

void Button::draw(){
    ofSetColor(0,0,0);
    ofRect(buttonX, buttonY, buttonWidth, buttonHeight);
    ofSetColor(255,255,255);
    ofDrawBitmapString(text, buttonX+textOffset, buttonY+textOffset+10);
}


void Button::clear(){
    delete button;
}