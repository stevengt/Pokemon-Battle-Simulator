
#include "SelectPokemonMenu.h"

std::vector<SelectPokemonMenuOption> SelectPokemonMenu::options = std::vector<SelectPokemonMenuOption>();

SelectPokemonMenu::SelectPokemonMenu(ofApp &listener){
    SelectPokemonMenu::options.push_back(SelectPokemonMenuOption("images/pikachu.png","Pikachu", options.size()));
    SelectPokemonMenu::options.push_back(SelectPokemonMenuOption("images/startMenu.png","Pikachu", options.size()));
    SelectPokemonMenu::options.push_back(SelectPokemonMenuOption("images/pikachu.png","Pikachu", options.size()));
    SelectPokemonMenu::options.push_back(SelectPokemonMenuOption("images/startMenu.png","Pikachu", options.size()));
    SelectPokemonMenu::options.push_back(SelectPokemonMenuOption("images/pikachu.png","Pikachu", options.size()));
    SelectPokemonMenu::options.push_back(SelectPokemonMenuOption("images/startMenu.png","Pikachu", options.size()));
    SelectPokemonMenu::options.push_back(SelectPokemonMenuOption("images/pikachu.png","Pikachu", options.size()));
    SelectPokemonMenu::options.push_back(SelectPokemonMenuOption("images/startMenu.png","Pikachu", options.size()));
}

void SelectPokemonMenu::draw(){

    for(int i = 0; i < SelectPokemonMenu::options.size();i++){
        SelectPokemonMenu::options.at(i).draw();
    }
    
}
