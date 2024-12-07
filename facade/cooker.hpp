#pragma once

#include <iostream>
#include <string>

struct Cooker 
{
    void cook(std::string meal)
    { 
        std::cout << "cooking a " << meal << std::endl;
    };
};
