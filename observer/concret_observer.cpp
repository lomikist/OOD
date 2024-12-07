#include "concret_observer.hpp"
#include <iostream>

Concret_observer::Concret_observer() : id(s_id)
{
    s_id++;
};

void Concret_observer::update()
{
    std::cout << "observer " << id << " was updated." << std::endl;
};

