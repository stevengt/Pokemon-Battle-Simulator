
#include "AttackButtonGroup.h"


AttackButtonGroup::AttackButtonGroup(Pokemon *pokemon){
    for (int i = 0; i < pokemon->getAttacks().size(); i++){
        
        Attack *attack = pokemon->getAttacks().at(i);
        std::string attackName = attack->getName();
        
        std::ostringstream currentPp;
        std::ostringstream maxPp;
        currentPp << attack->getCurrentPp();
        maxPp << attack->getMaxPp();
        std::string currentPpDisplayString = currentPp.str();
        std::string maxPpDisplayString = maxPp.str();
        
        std::string displayString = attackName + "  " + currentPpDisplayString + " / " + maxPpDisplayString;
        
        if (i == 0){
            addButton(new Button(col1X - colOffset, row1Y, expandedWidth, buttonHeight, displayString));
        } else if (i == 1){
            addButton(new Button(col2X, row1Y, expandedWidth, buttonHeight, displayString));
        } else if (i == 2) {
            addButton(new Button(col1X-colOffset, row2Y, expandedWidth, buttonHeight, displayString));
        } else if (i == 3) {
            addButton(new Button(col2X, row2Y, expandedWidth, buttonHeight, displayString));
        }
    }
}
