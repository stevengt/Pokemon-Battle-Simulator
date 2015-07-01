
#include "SelectPokemonMenu.h"

//std::vector<SelectPokemonMenuOption> SelectPokemonMenu::options = std::vector<SelectPokemonMenuOption>();

SelectPokemonMenu::SelectPokemonMenu(){
    options = std::vector<SelectPokemonMenuOption>();
    options.push_back(SelectPokemonMenuOption("images/pikachu.png","Pikachu", options.size()));
    options.push_back(SelectPokemonMenuOption("images/startMenu.png","Pikachu", options.size()));
    options.push_back(SelectPokemonMenuOption("images/pikachu.png","Pikachu", options.size()));
    options.push_back(SelectPokemonMenuOption("images/startMenu.png","Pikachu", options.size()));
    options.push_back(SelectPokemonMenuOption("images/pikachu.png","Pikachu", options.size()));
    options.push_back(SelectPokemonMenuOption("images/startMenu.png","Pikachu", options.size()));
    options.push_back(SelectPokemonMenuOption("images/pikachu.png","Pikachu", options.size()));
    options.push_back(SelectPokemonMenuOption("images/startMenu.png","Pikachu", options.size()));
    
    
    //theOption = SelectPokemonMenuOption("images/startMenu.png","Pikachu", 9);
    
//    button = ofxButton();
//    button.setup("test");
//    button.setPosition(600,600);
    
}

void SelectPokemonMenu::setListener(ofApp newListener){
    listener = &newListener;
}


void SelectPokemonMenu::draw(){

    for(int i = 0; i < options.size() ;i++){
        SelectPokemonMenu::options.at(i).draw();
    }
    //theOption.draw();
    //button.draw();
    
}

void SelectPokemonMenu::clear(){}


