#ifndef STATECOMMANDS_H
#define STATECOMMANDS_H

#include "Command.h"

class StateStack;

class NextStateCommand : public Command
{
public:
    void Execute(StateStack &aStateStack) override;
};

class PreviousStateCommand : public Command
{
public:
    void Execute(StateStack &aStateStack) override;
};

class MenuUpCommand : public Command
{
public:
    void Execute(StateStack &aStateStack) override;
};

class MenuDownCommand : public Command
{
public:
    void Execute(StateStack &aStateStack) override;
};

#endif
