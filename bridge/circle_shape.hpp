#include "shape.hpp"
#include "irenderer.hpp"
#include <memory>

class CircleShape : public Ishape 
{
public:
    CircleShape(std::unique_ptr<Irenderer> ptr)
    {
        _impl = std::move(ptr);
    };

    void draw() override 
    {
        _impl->render();
    }
private:
    int x = 0;
    int y = 0;
    int h = 0;
    int w = 0;

    std::unique_ptr<Irenderer> _impl;
};
