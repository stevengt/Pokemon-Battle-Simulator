

#include "StatusItem.h"


StatusItem::StatusItem(std::string name, std::string description, Status status) : Item(name, description){
    setStatus(status);
}


Status StatusItem::getStatus(){return status;}
void StatusItem::setStatus(Status newStatus){status = newStatus;}


//TODO
void StatusItem::use(){return;}