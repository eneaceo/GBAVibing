#ifndef COMMAND_H
#define COMMAND_H

class State;
class MenuState;

class Command
{
public:
    virtual ~Command() = default;
    virtual void Execute(State &aState) {};
    virtual void Execute(MenuState &aState) {};
};

#endif
