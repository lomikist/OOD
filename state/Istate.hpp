#pragma once

struct State 
{
    virtual ~State() = default;
    virtual void changeState(class Controller* controller, int changenumber) = 0;
};
