
#pragma once

class Screen{
public:
    virtual void draw()=0;
    virtual ~Screen() = 0;
    virtual void clear()=0;
};