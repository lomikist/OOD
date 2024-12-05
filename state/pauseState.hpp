#pragma once
#include "Istate.hpp"
#include "controller.hpp"
class menuState;

class pauseState : public State 
{
public:
    void changeState(Controller* controller, int changenumber) override;
};
