#include "concret_subject.hpp"

void Concret_sub::start()
{
    int a;
    while (true)
    {
        std::cin >> a;
        if (a % 2 == 0) {
            notify_observers();
        }
    }
};
