#include "shape.hpp"
#include "irenderer.hpp"
#include <memory>

class RectShape : public Ishape 
{
public:
    RectShape(std::unique_ptr<Irenderer> ptr)
    {
        _impl = std::move(ptr);
    };
    void draw() override 
    {
        _impl->render();
    }
private:
    int x;
    int y;
    int h;
    int w;

    std::unique_ptr<Irenderer> _impl;
};
