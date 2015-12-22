
#include "HpAndPpItem.h"

HpAndPpItem::HpAndPpItem(){}

HpAndPpItem::HpAndPpItem(std::string name, std::string description, int restoreAmount, ItemType type) : Item(name, description){
    setRestoreAmount(restoreAmount);
    setItemType(type);
}

int HpAndPpItem::getRestoreAmount(){return restoreAmount;}
void HpAndPpItem::setRestoreAmount(int newRestoreAmount){restoreAmount = newRestoreAmount;}

//TODO
void HpAndPpItem::use(){return;}

std::string HpAndPpItem::getJSON(){
    std::string json = "{ \"name\" : \"";
    json = json + name;
    json = json + "\", \"description\" : ";
    json = json + description;
    json = json + "\", \"restoreAmount\" : ";
    json = json + std::to_string(restoreAmount);
    json = json + ",\"item type\" : ";
    json = json + (type == HP ? "\"hp\"" : "\"pp\"");
    json = json + "}";
    return json;
}