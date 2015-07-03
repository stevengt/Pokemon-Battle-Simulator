
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

    backButton = new Button(backButtonLocationX,backButtonLocationY,buttonWidth,buttonHeight,"Back");
}


void SelectPokemonMenu::draw(){
    backButton->draw();
    continueButton->draw();
        for(int i = 0; i < options->size() ;i++){
            options->at(i).draw();
        }
    if(warningMessage != NULL){
        warningMessage->draw();
    }
}

void SelectPokemonMenu::clear(){
    delete continueButton;
    delete backButton;
    delete options;
    if (warningMessage != NULL){
        warningMessage = NULL;
    }
}


void SelectPokemonMenu::populate(){
    addOptions();
    setListener(*GlobalVariables::globalApp);
    setContinueButton();
    setBackButton();
}

void SelectPokemonMenu::setWarningMessage(){
    warningMessage = new Button(warningButtonLocationX, warningButtonLocationY, warningButtonWidth, buttonHeight, "You must select 6 Pokemon");
}

bool SelectPokemonMenu::selectionIsValid(){
    int count = 0;
    for (int i = 0; i < options->size(); i++){
        if(options->at(i).getButton()->getParameter().toString() == "1"){
            count++;
        }
    }
    if (count == 6){
        return true;
    }
    return false;
}

void SelectPokemonMenu::mousePressed(int x, int y){
    if(backButton->inside(x,y)){
        GlobalVariables::globalApp->switchToStartMenu();
    }
    if(continueButton->inside(x,y)){
        if (!selectionIsValid()){
            setWarningMessage();
        }
    }
    
}


