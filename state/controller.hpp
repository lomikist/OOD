#pragma once
#include "Istate.hpp"

class Controller 
{
public:
    Controller() = default;
    void setState(State* new_state); 
    void handle_input(int change_number);
private:
    State* m_state = nullptr;
};
