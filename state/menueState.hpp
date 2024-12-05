#pragma once
#include "Istate.hpp"
#include "controller.hpp"

class pauseState;

class menuState : public State 
{
public:
    void changeState(Controller* controller, int changeNumber) override;
};
