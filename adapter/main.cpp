
#include <iostream>
#include <list>

class Stack 
{
public:
    Stack() = default;
    Stack(const Stack& other) = default;
    virtual ~Stack(){};
    virtual void pop() = 0;
    virtual std::string& top() = 0;
    virtual void push(const std::string& val) = 0;
};

/*struct Stack_adapter : protected std::list<std::string> , public Stack*/
/*{*/
/*    Stack_adapter(){}; */
/*    ~Stack_adapter() = default;*/
/*    void pop() override*/
/*    {*/
/*        pop_back();*/
/*    };*/
/*    std::string&  top() override*/
/*    {*/
/*        return back(); */
/*    }*/
/*    void push(const std::string& val) override*/
/*    {*/
/*        push_back(val);*/
/*    }*/
/*};*/

struct Stack_adapter :  public Stack
{
    Stack_adapter(){}; 
    ~Stack_adapter() = default;

    void pop() override
    {
        _list.pop_back();
    };
    std::string&  top() override
    {
        return _list.back(); 
    }
    void push(const std::string& val) override
    {
        _list.push_back(val);
    }
private:
    std::list<std::string> _list; 
};
int main()
{
    Stack_adapter a;

    a.push("my");
    a.push("darkness");
    a.push("hello");
    std::cout << a.top();
    a.pop();
    std::cout << a.top();
    a.pop();
    std::cout << a.top();
    a.pop();
};
