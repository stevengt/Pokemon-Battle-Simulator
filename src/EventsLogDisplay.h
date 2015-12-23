
#pragma once

#include "ofMain.h"
#include "Drawable.h"

class EventsLogDisplay : public Drawable {
private:
    static const int locationX = 50;
    static const int locationY = 50;
    static const int width = 450;
    static const int height = 250;
    static const int textMargin = 5;
    static const int textOffset = 15;
    std::vector<std::string> *log;
public:
    EventsLogDisplay();
    EventsLogDisplay(std::vector<std::string> *log);
    void setLog(std::vector<std::string> *log);
    void draw();
    void clear();
};