
#include "SelectPokemonMenu.h"
#include "AllPokemon.h"
#include "Battle.h"

SelectPokemonMenu::SelectPokemonMenu(ofApp *mainApp){
    setMainApp(mainApp);
}

void SelectPokemonMenu::setMainApp(ofApp *mainApp){
    this->mainApp = mainApp;
}

void SelectPokemonMenu::addOptions(){
    options = new std::vector<SelectPokemonMenuOption>();
 
    options->push_back(SelectPokemonMenuOption(new Pikachu(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Charmander(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Squirtle(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Bulbasaur(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Skarmory(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Ghastly(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Lotad(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Magnemite(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Jynx(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Sneasel(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Aerodactyl(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Axew(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Absol(), options->size()));
    options->push_back(SelectPokemonMenuOption(new Clefairy(), options->size()));

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
        trainer->addPokemon(new Pikachu());
        trainer->addPokemon(new Charmander());
        trainer->addPokemon(new Squirtle());
        trainer->addPokemon(new Bulbasaur());
        trainer->addPokemon(new Skarmory());
        trainer->addPokemon(new Ghastly());
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
        mainApp->switchToStartMenu();
    }
    if(continueButton->inside(x,y)){
        if (!selectionIsValid()){
            setWarningMessage();
        } else {
            mainApp->switchToBattleScreen(makeBattle());
        }
    }
    
}


