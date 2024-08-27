#ifndef COMMAND_H
#define COMMAND_H

class Actor;

class Command
{
public:
    virtual ~Command() = default;
    virtual void Execute(Actor &aActor) = 0;
};

#endif
