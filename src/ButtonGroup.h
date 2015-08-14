
#pragma once

#include "Drawable.h"
#include "Button.h"
#include <vector>

class ButtonGroup : public Drawable {
protected:
    static const int buttonWidth = 150;
    static const int buttonHeight = 50;
    std::vector<Button*> buttons;

public:
    ButtonGroup();
    void addButton(Button *button);
    std::vector<Button*> getButtons();
    void draw();
    void clear();
};