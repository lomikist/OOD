#include "concret_observer.hpp"
#include "concret_subject.hpp"

int main()
{
    Concret_sub sub;

    std::shared_ptr<Iobserver> ob1 = std::make_shared<Concret_observer>();
    std::shared_ptr<Iobserver> ob2 = std::make_shared<Concret_observer>();
    std::shared_ptr<Iobserver> ob3 = std::make_shared<Concret_observer>();
    std::shared_ptr<Iobserver> ob4 = std::make_shared<Concret_observer>();

    sub.add_observer(ob1);
    sub.add_observer(ob2);
    sub.add_observer(ob3);
    sub.add_observer(ob4);

    sub.start();
};
