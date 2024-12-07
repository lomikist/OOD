#pragma once 
#include "icommand.hpp"
#include <iostream>

class AddCommand : public Icommand
{
public:
    void execute() override
    {
        std::cout << "added some element" << std::endl;
    };
};
