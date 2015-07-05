
#pragma once

#include "ofMain.h"
#include "Drawable.h"
#include "Battle.h"
class EventsLogDisplay : public Drawable {
private:
    static const int locationX = 50;
    static const int locationY = 50;
    static const int width = 450;
    static const int height = 250;
    static const int textMargin = 5;
    static const int textOffset = 15;
    Battle *battle;
public:
    EventsLogDisplay();
    EventsLogDisplay(Battle *battle);
    void setBattle(Battle *newBattle);
    void draw();
    void clear();
};