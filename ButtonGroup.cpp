
#include "ButtonGroup.h"

ButtonGroup::ButtonGroup(){}

void ButtonGroup::addButton(Button *button){
    buttons.push_back(button);
}

std::vector<Button*> ButtonGroup::getButtons(){
    return buttons;
}

void ButtonGroup::draw(){
    for (int i = 0; i < buttons.size(); i++){
        buttons.at(i)->draw();
    }
}

void ButtonGroup::clear(){
    for (int i = 0; i < buttons.size(); i++){
        buttons.at(i)->clear();
    }
}