#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
    virtual ~Command() = default;
    virtual void Execute() = 0;
};

#include "bn_core.h"
#include "bn_bg_palettes.h"
#include "bn_color.h"

class NextStateCommand : public Command
{
public:
    void Execute() 
    {
        bn::bg_palettes::set_transparent_color(bn::color(31, 0, 0));
    };
};

class PreviousStateCommand : public Command
{
public:
    void Execute() 
    {
        bn::bg_palettes::set_transparent_color(bn::color(0, 31, 0));
    };
};

class MenuUpCommand : public Command
{
public:
    void Execute() 
    {
        bn::bg_palettes::set_transparent_color(bn::color(0, 0, 31));
    };
};

class MenuDownCommand : public Command
{
public:
    void Execute() 
    {
        bn::bg_palettes::set_transparent_color(bn::color(31, 31, 31));
    };
};

#endif