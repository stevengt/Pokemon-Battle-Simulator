
#pragma once

#include "GroupOf4Buttons.h"
#include "Pokemon.h"
class AttackButtonGroup : public GroupOf4Buttons {
private:
    static const int expandedWidth = 200;
    static const int colOffset = 100;
    
public:
    AttackButtonGroup(Pokemon *pokemon);
};