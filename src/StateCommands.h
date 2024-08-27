#ifndef STATECOMMAND_H
#define STATECOMMAND_H

#include "Command.h"
#include "StateStack.h"

class NextStateCommand : public Command
{
public:
    void Execute(Actor &aActor) override
    {
        StateStack &aStateStack = static_cast<StateStack&>(aActor);
        aStateStack.AdvanceState();
    };
};

class PreviousStateCommand : public Command
{
public:
    void Execute(Actor &aActor) override
    {
        StateStack &aStateStack = static_cast<StateStack&>(aActor);
        aStateStack.PreviousState();
    };
};

#include "bn_bg_palettes.h"
#include "bn_color.h"


class MenuUpCommand : public Command
{
public:
    void Execute(Actor &aActor) override
    {
        bn::bg_palettes::set_transparent_color(bn::color(0, 0, 0));
    };
};

class MenuDownCommand : public Command
{
public:
    void Execute(Actor &aActor) override
    {
        bn::bg_palettes::set_transparent_color(bn::color(31, 31, 31));
    };
};

#endif