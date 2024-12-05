#include "pauseState.hpp"
#include "menueState.hpp"
#include <iostream>

void pauseState::changeState(Controller* controller, int changeNumber)
{
    State* new_state;

    if (changeNumber == 1)
    {
        new_state = new menuState();
        std::cout << "changes to menustate\n";
    }
    else
    {
        new_state = new pauseState();
        std::cout << "changes to pausestate\n";
    }
    controller->setState(new_state);
}

