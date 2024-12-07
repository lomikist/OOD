#pragma once
#include "cooker.hpp"
#include "cutter.hpp"
#include "washer.hpp"

class Facade
{
    Cooker m_cooker;
    Washer m_washer;
    Cutter m_cutter;
public:
    void order_meal(std::string meal)
    {
        m_washer.wash(meal);
        m_cutter.cut(meal);
        m_cooker.cook(meal);
    };
};
