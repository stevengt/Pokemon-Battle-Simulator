
#include "EventsLogDisplay.h"

EventsLogDisplay::EventsLogDisplay(){}

EventsLogDisplay::EventsLogDisplay(Battle *battle){
    setBattle(battle);
}

void EventsLogDisplay::setBattle(Battle *newBattle){
    battle = newBattle;
}

void EventsLogDisplay::draw(){
    ofSetColor(0,0,0);
    ofRect(locationX, locationY, width, height);
    ofSetColor(255,255,255);
    std::vector<std::string> eventsLog = battle->getEventsLog();
    for (int i = 0; i < eventsLog.size(); i++){
        ofDrawBitmapString(eventsLog.at(i), locationX+textOffset, locationY+textOffset*(i+1)+textMargin);
    }
    
}

void EventsLogDisplay::clear(){}