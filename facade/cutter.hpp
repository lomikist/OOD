#pragma once

#include <iostream>
#include <string>

struct Cutter 
{
    void cut(std::string meal)
    { 
        std::cout << "cutting a " << meal << std::endl;
    };
};
