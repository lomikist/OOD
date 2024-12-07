#pragma once
struct Icommand 
{
    virtual void execute() = 0;
    virtual ~Icommand() = default;
};
