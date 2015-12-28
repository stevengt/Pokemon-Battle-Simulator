

#include "StatusItem.h"


StatusItem::StatusItem(std::string name, std::string description, Status status) : Item(name, description){
    setStatus(status);
    setItemType(STATUS);
}


Status StatusItem::getStatus(){return status;}
void StatusItem::setStatus(Status newStatus){status = newStatus;}


//TODO
void StatusItem::use(){return;}

std::string StatusItem::getJSON(){
    std::string json = "{ \"name\" : \"";
    json = json + name;
    json = json + "\", \"description\" : ";
    json = json + description;
    json = json + "\", \"status\" : ";
    std::string tmp;
    switch(status){
        case BURNED :
            tmp = "\"burned\"";
            break;
        case FROZEN :
            tmp = "\"frozen\"";
            break;
        case PARALYZED:
            tmp = "\"paralyzed\"";
            break;
        case POISENED:
            tmp = "\"poisened\"";
            break;
        case ASLEEP:
            tmp = "\"asleep\"";
            break;
        case CONFUSED:
            tmp = "\"confused\"";
            break;
    }
    json = json + tmp;
    json = json + "}";
    return json;
}