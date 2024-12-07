#pragma once

#include <iostream>
#include <string>

struct Washer 
{
    void wash(std::string meal)
    { 
        std::cout << "washing a " << meal << std::endl;
    };
};
