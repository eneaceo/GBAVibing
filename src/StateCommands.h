#ifndef STATECOMMANDS_H
#define STATECOMMANDS_H

#include "Command.h"

class Actor;

class NextStateCommand : public Command
{
public:
    void Execute(Actor &aActor) override;
};

class PreviousStateCommand : public Command
{
public:
    void Execute(Actor &aActor) override;
};

class MenuUpCommand : public Command
{
public:
    void Execute(Actor &aActor) override;
};

class MenuDownCommand : public Command
{
public:
    void Execute(Actor &aActor) override;
};

#endif
