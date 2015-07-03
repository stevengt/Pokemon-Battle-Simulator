
#include "AttackButtonGroup.h"


AttackButtonGroup::AttackButtonGroup(Pokemon *pokemon){
    for (int i = 0; i < pokemon->getAttacks().size(); i++){
        if(i==0){
            addButton(new Button(buttonLocation1X, buttonLocation1Y, buttonWidth, buttonHeight, pokemon->getAttacks().at(i).getName()));
        } else if(i==1){
            addButton(new Button(buttonLocation2X, buttonLocation2Y, buttonWidth, buttonHeight, pokemon->getAttacks().at(i).getName()));
        } else if(i==2){
            addButton(new Button(buttonLocation3X, buttonLocation3Y, buttonWidth, buttonHeight, pokemon->getAttacks().at(i).getName()));
        } else if(i==3){
            addButton(new Button(buttonLocation4X, buttonLocation4Y, buttonWidth, buttonHeight, pokemon->getAttacks().at(i).getName()));
        }
    }
    
}
