#include "controller.hpp"

void Controller::setState(State* new_state) {
    m_state = new_state; 
}

void Controller::handle_input(int change_number)
{
    m_state->changeState(this, change_number);
}
