

#include "EndGameButtonGroup.h"


EndGameButtonGroup::EndGameButtonGroup(bool won){
    if (won){
        addButton(new Button(x, y, buttonWidth, buttonHeight, "You won!"));
    } else {
        addButton(new Button(x, y, buttonWidth, buttonHeight, "You lost"));
    }
}