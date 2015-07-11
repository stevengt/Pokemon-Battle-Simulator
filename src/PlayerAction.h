
#pragma once
#include <iostream>
#include <vector>
class PlayerAction{
    
protected :
    std::vector<std::string> retVal;
    
public:
    virtual std::vector<std::string> execute()=0;
};