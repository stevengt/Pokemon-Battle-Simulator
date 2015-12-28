
#pragma once

#include "ButtonGroup.h"
#include "Trainer.h"

#include <sstream>

class PokemonButtonGroup : public ButtonGroup {
private:
    static const int row1Y = 400;
    static const int row2Y = 500;
    static const int row3Y = 600;
    static const int col1X = 400;
    static const int col2X = 700;
    static const int expandedButtonWidth = 250;
    
    std::string getHpDisplay(Pokemon *pokemon);
    
public:
    PokemonButtonGroup(Trainer *trainer);
};
