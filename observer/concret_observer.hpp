#pragma once

#include "iobserver.hpp"

class Concret_observer : public Iobserver
{
public:
    Concret_observer();
    virtual ~Concret_observer() = default;
    void update() override; 
private:
    inline static int s_id = 0;
    int id;
};
