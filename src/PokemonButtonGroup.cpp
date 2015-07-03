
#include "PokemonButtonGroup.h"

PokemonButtonGroup::PokemonButtonGroup(Trainer *trainer){
    addButton(new Button(col1X, row1Y, expandedButtonWidth, buttonHeight, getHpDisplay(trainer->getPokemon(0))));
    addButton(new Button(col2X, row1Y, expandedButtonWidth, buttonHeight, getHpDisplay(trainer->getPokemon(1))));
    addButton(new Button(col1X, row2Y, expandedButtonWidth, buttonHeight, getHpDisplay(trainer->getPokemon(2))));
    addButton(new Button(col2X, row2Y, expandedButtonWidth, buttonHeight, getHpDisplay(trainer->getPokemon(3))));
    addButton(new Button(col1X, row3Y, expandedButtonWidth, buttonHeight, getHpDisplay(trainer->getPokemon(4))));
    addButton(new Button(col2X, row3Y, expandedButtonWidth, buttonHeight, getHpDisplay(trainer->getPokemon(5))));
}

std::string PokemonButtonGroup::getHpDisplay(Pokemon *pokemon){
    std::ostringstream currentHp;
    std::ostringstream maxHp;
    currentHp << pokemon->getCurrentHp();
    maxHp << pokemon->getMaxHp();
    return  pokemon->getName() + "  " + currentHp.str() + " / " + maxHp.str();
}