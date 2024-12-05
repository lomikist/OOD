#include "controller.hpp"
#include "menueState.hpp"
#include "pauseState.hpp"

int main() {
    Controller controller;

    State* initialState = new menuState();
    controller.setState(initialState);
    controller.handle_input(2);
    controller.handle_input(1);
    controller.handle_input(1);
    controller.handle_input(1);
    return 0;
}

