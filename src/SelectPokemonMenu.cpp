
#include "SelectPokemonMenu.h"

//std::vector<SelectPokemonMenuOption> SelectPokemonMenu::options = std::vector<SelectPokemonMenuOption>();

SelectPokemonMenu::SelectPokemonMenu(){}

void SelectPokemonMenu::setListener(ofApp newListener){
    listener = &newListener;
}

void SelectPokemonMenu::addOptions(){
    options = new std::vector<SelectPokemonMenuOption>();
    options->push_back(SelectPokemonMenuOption("images/pikachu.png","Pikachu", options->size()));
    options->push_back(SelectPokemonMenuOption("images/startMenu.png","Pikachu", options->size()));
    options->push_back(SelectPokemonMenuOption("images/pikachu.png","Pikachu", options->size()));
    options->push_back(SelectPokemonMenuOption("images/startMenu.png","Pikachu", options->size()));
    options->push_back(SelectPokemonMenuOption("images/pikachu.png","Pikachu", options->size()));
    options->push_back(SelectPokemonMenuOption("images/startMenu.png","Pikachu", options->size()));
    options->push_back(SelectPokemonMenuOption("images/pikachu.png","Pikachu", options->size()));
    options->push_back(SelectPokemonMenuOption("images/startMenu.png","Pikachu", options->size()));
}

void SelectPokemonMenu::setContinueButton(){
        continueButton = new Button(continueButtonLocationX,continueButtonLocationY,buttonWidth,buttonHeight,"Continue");
    
}


void SelectPokemonMenu::setBackButton(){
//    backButton =  new ofxButton();
//    backButton->setup("Back");
//    backButton->setPosition(backButtonLocationX,backButtonLocationY);
//    backButton->addListener(listener, &ofApp::switchToStartMenu);
    backButton = new Button(backButtonLocationX,backButtonLocationY,buttonWidth,buttonHeight,"Back");
}


void SelectPokemonMenu::draw(){
    backButton->draw();
    continueButton->draw();
        for(int i = 0; i < options->size() ;i++){
            options->at(i).draw();
        }
}

void SelectPokemonMenu::clear(){
    delete continueButton;
    delete backButton;
    delete options;
}


void SelectPokemonMenu::populate(){
    addOptions();
    setListener(*GlobalVariables::globalApp);
    setContinueButton();
    setBackButton();
}

void SelectPokemonMenu::mousePressed(int x, int y){
    if(backButton->inside(x,y)){
        GlobalVariables::globalApp->switchToStartMenu();
    }
}


