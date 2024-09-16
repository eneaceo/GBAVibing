#ifndef STATECOMMANDS_H
#define STATECOMMANDS_H

#include "Command.h"

class MenuState;

class SelectCommand : public Command
{
public:
    void Execute(MenuState &aState) override;
};

class MenuUpCommand : public Command
{
public:
    void Execute(MenuState &aState) override;
};

class MenuDownCommand : public Command
{
public:
    void Execute(MenuState &aState) override;
};

#endif
