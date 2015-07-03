
#include "AttackButtonGroup.h"


AttackButtonGroup::AttackButtonGroup(Pokemon *pokemon){
    for (int i = 0; i < pokemon->getAttacks().size(); i++){
        if(i==0){
            addButton(new Button(col1X, row1Y, buttonWidth, buttonHeight, pokemon->getAttacks().at(i).getName()));
        } else if(i==1){
            addButton(new Button(col2X, row1Y, buttonWidth, buttonHeight, pokemon->getAttacks().at(i).getName()));
        } else if(i==2){
            addButton(new Button(col1X, row2Y, buttonWidth, buttonHeight, pokemon->getAttacks().at(i).getName()));
        } else if(i==3){
            addButton(new Button(col2X, row2Y, buttonWidth, buttonHeight, pokemon->getAttacks().at(i).getName()));
        }
    }
    
}
