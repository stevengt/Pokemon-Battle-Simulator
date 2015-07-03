

#include "MainButtonGroup.h"

MainButtonGroup::MainButtonGroup(){
    addButton(new Button(buttonLocation1X, buttonLocation1Y, buttonWidth, buttonHeight, "Attack"));
    addButton(new Button(buttonLocation2X, buttonLocation2Y, buttonWidth, buttonHeight, "Pokemon"));
    addButton(new Button(buttonLocation3X, buttonLocation3Y, buttonWidth, buttonHeight, "HP / PP"));
    addButton(new Button(buttonLocation4X, buttonLocation4Y, buttonWidth, buttonHeight, "Status"));
}
