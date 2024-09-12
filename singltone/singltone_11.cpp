#include <mutex>
#include <thread>
#include <iostream>

class Singltone {
private:
    Singltone()
    {
        std::cout << "constructor\n";
    };
public:
    ~Singltone()
    {
        std::cout << "dest\n";
    };
    static std::mutex my_mut;
    static Singltone* _instance;
public:
    static Singltone* get_instance()
    {    
        std::lock_guard<std::mutex> lock(my_mut);
        if(!_instance)
        {
            _instance = new Singltone();
        }
        return _instance;
    }
};

Singltone* Singltone::_instance = nullptr;
std::mutex Singltone::my_mut;
void foo()
{
    std::cout << "foo\n";
    Singltone* a = Singltone::get_instance();
}

void foo2()
{
    std::cout << "foo2\n";
    Singltone* b = Singltone::get_instance();
}


int main (int argc, char *argv[])
{
    std::thread tread1(foo);    
    std::thread tread12(foo2);
    tread1.join();
    tread12.join();
    return 0;
} 
