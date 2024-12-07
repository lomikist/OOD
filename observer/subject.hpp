#pragma once
#include "iobserver.hpp"
#include <memory>
#include <vector>

class Asubject
{
public:
    virtual ~Asubject() = default;
    void add_observer(std::shared_ptr<Iobserver> new_observer); 
    void remove_observer(int index);
    virtual void notify_observers();
private:
    std::vector<std::shared_ptr<Iobserver>> m_observers;
};
