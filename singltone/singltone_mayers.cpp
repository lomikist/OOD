#include <thread>
#include <iostream>
class Singltone {
private:
    Singltone()
    {
        std::cout << "contstrutor\n";
    };
public:
    ~Singltone()
    {
        std::cout << "dest\n";
    };
public:
   static Singltone& get_instance()
   {
       static Singltone my_inst;
       return my_inst;
   }
};

void foo()
{
    Singltone a = Singltone::get_instance();
}
void foo2()
{
   Singltone b = Singltone::get_instance();
}

int main (int argc, char *argv[])
{
    std::thread tread1(foo);    
    std::thread tread12(foo2);
    tread1.detach();
    tread12.detach();
    return 0;
}
