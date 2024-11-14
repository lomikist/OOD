#include "irenderer.hpp"
#include "shape.hpp"
#include "text_renderer.hpp"
#include "vec_renderer.hpp"
#include "circle_shape.hpp"
#include "rect_shape.hpp"
#include <memory>

int main (int argc, char *argv[])
{
    CircleShape a(std::make_unique<TextRenderer>());    
    RectShape b(std::make_unique<VectorRenderer>());    

    a.draw();
    b.draw();
    return 0;
}
