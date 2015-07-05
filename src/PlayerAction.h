
#pragma once
#include <iostream>

class PlayerAction{
public:
    virtual std::string execute()=0;
};