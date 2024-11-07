
#include <iostream>
struct IView 
{
    virtual void draw() = 0;
};

class ITextView : public IView
{
public:
    void draw() override
    {
        std::cout << "drawing text view" << std::endl;
    }
};

struct ADecorator : public IView
{
    ADecorator(IView* obj) : _obj(obj){};
    void draw() override = 0;
protected:
    IView* _obj;
};

struct ScrollDecorator : public ADecorator
{
    ScrollDecorator(IView* obj) : ADecorator(obj){};
    void draw() override
    {
        _obj->draw();
        std::cout << "draw with scrollin ...." << std::endl;
    }
};

struct FilterDecorator : public ADecorator
{
    FilterDecorator(IView* obj) : ADecorator(obj){} 
    void draw() override
    {
        _obj->draw();
        std::cout << "filetr setted ...." << std::endl;
    }
};

int main() 
{
    ITextView* text_view = new ITextView();
    
    ScrollDecorator* text_with_scroll = new ScrollDecorator(new FilterDecorator(text_view));

    text_with_scroll->draw();

}

