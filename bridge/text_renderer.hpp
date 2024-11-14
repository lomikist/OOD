#include <iostream>
#include "irenderer.hpp"

class TextRenderer : public Irenderer
{
public:
    TextRenderer(const TextRenderer& ) = delete;
    TextRenderer() = default;
    void render() override
    {
        std::cout << "print shape in text manner\n"; 
    };
};
