#pragma once 
#include <memory>
#include "icommand.hpp"
class Client 
{
private:
    std::shared_ptr<Icommand> _command;
public:
    void set_command(std::shared_ptr<Icommand> new_com)
    {
        _command = new_com;
    };
    void exec_command()
    {
        _command->execute();
    };
};


