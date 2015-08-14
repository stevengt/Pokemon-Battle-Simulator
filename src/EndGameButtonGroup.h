
#pragma once

#include "ButtonGroup.h"

class EndGameButtonGroup : public ButtonGroup {
private:
    static const int x = 400;
    static const int y = 400;
    
public:
    EndGameButtonGroup(bool won);
};
