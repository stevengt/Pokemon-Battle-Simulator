
#include "SelectPokemonMenu.h"
#include "AllPokemon.h"
//std::vector<SelectPokemonMenuOption> SelectPokemonMenu::options = std::vector<SelectPokemonMenuOption>();

SelectPokemonMenu::SelectPokemonMenu(){}

void SelectPokemonMenu::setListener(ofApp newListener){
    listener = &newListener;
}

void SelectPokemonMenu::addOptions(){
    options = new std::vector<SelectPokemonMenuOption>();
 
    options->push_back(SelectPokemonMenuOption(new Pikachu(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Charmander(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Squirtle(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Pikachu(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Charmander(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Squirtle(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Pikachu(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Charmander(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Squirtle(), options->size()));
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

Trainer *SelectPokemonMenu::initializeTrainer(bool isTrainer1){
    Trainer *trainer = new Trainer();
    if(isTrainer1){
        for(int i = 0; i < options->size() ; i++){
            if(optionIsSelected(i)){
                trainer->addPokemon(options->at(i).getPokemon());
            }
        }
    } else {
        for (int i = 0; i < 6; i++){
            trainer->addPokemon(options->at(i).getPokemon()->clone());
        }
    }
    return trainer;
}

bool SelectPokemonMenu::optionIsSelected(int optionNum){
    return options->at(optionNum).getButton()->getParameter().toString() == "1";
}


Battle *SelectPokemonMenu::makeBattle(){
    Trainer *trainer1 = initializeTrainer(true);
    Trainer *trainer2 = initializeTrainer(false);
    return new LocalBattle(trainer1, trainer2);
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
        if(optionIsSelected(i)){
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
        } else {
            GlobalVariables::globalApp->switchToBattleScreen(makeBattle());
        }
    }
    
}


