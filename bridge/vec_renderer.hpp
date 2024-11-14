#include "irenderer.hpp"
#include <iostream>

class VectorRenderer : public Irenderer
{
public:
    VectorRenderer(const VectorRenderer& ) = delete;
    VectorRenderer() = default;
    void render() override
    {
        std::cout << "print shape in vector manner\n"; 
    };
};
