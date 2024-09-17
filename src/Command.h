#ifndef COMMAND_H
#define COMMAND_H

class State;

#include "bn_color.h"
#include "bn_bg_palettes.h"

class Command
{
public:
    virtual ~Command() = default;
    virtual void Execute(State &aState) = 0;
};

#endif
