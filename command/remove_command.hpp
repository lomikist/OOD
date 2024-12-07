#pragma once
#include "icommand.hpp"
#include <iostream>

class RemoveCommand : public Icommand
{
public:
    void execute() override
    {
        std::cout << "removed some element" << std::endl;
    };
};
