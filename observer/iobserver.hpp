#pragma once

struct Iobserver 
{
    virtual ~Iobserver() = default;
    virtual void update() = 0; 
};
