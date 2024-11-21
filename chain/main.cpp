#include <iostream>
#include <memory>

class Pawn
{
public:
    bool move_forward()
    {
        return true; 
    };

    bool check_ablity()
    {
        return true;
    }

    bool check_math()
    {
        return true;
    }
};

struct Ihandler 
{
    virtual void next_handler(Pawn) = 0;
    virtual ~Ihandler(){};
    virtual void set_handler(std::shared_ptr<Ihandler> succes_handler) = 0;
};

class AvalibleHandler : public Ihandler 
{
    std::shared_ptr<Ihandler> _succes;
public:
    void next_handler(Pawn pawn) override
    {
        if (pawn.check_ablity())
        {
            std::cout << "move is avalibel" << std::endl;
            if (_succes)
                _succes->next_handler(pawn);
        }
    };
    void set_handler(std::shared_ptr<Ihandler> succes_handler) override
    {
        _succes = succes_handler;
    };
};

class MathHandler : public Ihandler 
{
    std::shared_ptr<Ihandler> _succes;
public:
    void next_handler(Pawn pawn) override
    {
        if (pawn.check_math())
        {
            std::cout << "math is avalibel" << std::endl;
            if (_succes)
                _succes->next_handler(pawn);
        }
    };
    void set_handler(std::shared_ptr<Ihandler> succes_handler) override
    {
        _succes = succes_handler;
    };
};


int main()
{
    Pawn pawn;
    std::shared_ptr<Ihandler> math_handler = std::make_shared<MathHandler>();
    std::shared_ptr<Ihandler> avalible_handler = std::make_shared<AvalibleHandler>();

    avalible_handler->set_handler(math_handler);
    avalible_handler->next_handler(pawn);
};



