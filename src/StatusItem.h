
#pragma once

#include "Item.h"
#include "Status.h"

class HpAndPpItem;

class StatusItem : public Item {
private:
    Status status;
public:
    StatusItem(std::string name, std::string description, Status status);
    Status getStatus();
    void setStatus(Status newStatus);
    void use();
};