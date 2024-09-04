#ifndef COMMAND_H
#define COMMAND_H

class StateStack;

class Command
{
public:
    virtual ~Command() = default;
    virtual void Execute(StateStack &aStateStack) = 0;
};

#endif
