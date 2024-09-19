#ifndef STATECOMMANDS_H
#define STATECOMMANDS_H

#include "Command.h"

class State;

class SelectCommand : public Command
{
public:
    void Execute(State &aState) override;
};

class BackCommand : public Command
{
public:
    void Execute(State &aState) override;
};

class MenuUpCommand : public Command
{
public:
    void Execute(State &aState) override;
};

class MenuDownCommand : public Command
{
public:
    void Execute(State &aState) override;
};

class AutoCommand : public Command
{
public:
    void Execute(State &aState) override;
};

#endif
