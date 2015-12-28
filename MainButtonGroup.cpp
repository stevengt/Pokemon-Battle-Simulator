

#include "MainButtonGroup.h"

MainButtonGroup::MainButtonGroup(){
    addButton(new Button(col1X, row1Y, buttonWidth, buttonHeight, "Attack"));
    addButton(new Button(col2X, row1Y, buttonWidth, buttonHeight, "Pokemon"));
    addButton(new Button(col1X, row2Y, buttonWidth, buttonHeight, "HP / PP"));
    addButton(new Button(col2X, row2Y, buttonWidth, buttonHeight, "Status"));
}
