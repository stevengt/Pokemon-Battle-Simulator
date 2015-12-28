
#include "EventsLogDisplay.h"

EventsLogDisplay::EventsLogDisplay(){}

EventsLogDisplay::EventsLogDisplay(std::vector<std::string> *log){
    setLog(log);
}

void EventsLogDisplay::setLog(std::vector<std::string> *log){
    this->log = log;
}

void EventsLogDisplay::draw(){
    ofSetColor(0,0,0);
    ofRect(locationX, locationY, width, height);
    ofSetColor(255,255,255);
    for (int i = 0; i < log->size(); i++){
        ofDrawBitmapString(log->at(i), locationX+textOffset, locationY+textOffset*(i+1)+textMargin);
    }
    
}

void EventsLogDisplay::clear(){}