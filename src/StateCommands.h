#ifndef STATECOMMANDS_H
#define STATECOMMANDS_H

#include "Command.h"

class MenuState;

class SelectCommand : public Command
{
public:
    using Command::Execute;
    void Execute(MenuState &aState) override;
};

class MenuUpCommand : public Command
{
public:
    using Command::Execute;
    void Execute(MenuState &aState) override;
};

class MenuDownCommand : public Command
{
public:
    using Command::Execute;
    void Execute(MenuState &aState) override;
};

#endif
