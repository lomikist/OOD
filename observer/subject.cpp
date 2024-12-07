#include "subject.hpp"

void Asubject::add_observer(std::shared_ptr<Iobserver> new_observer)
{
    if (new_observer != nullptr)
        m_observers.push_back(new_observer);
}
void Asubject::remove_observer(int index)
{
    m_observers.erase(m_observers.begin() + index);
}
void Asubject::notify_observers()
{
    for (auto observer : m_observers) {
        observer->update(); 
    }
}
