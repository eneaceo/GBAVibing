#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
    virtual ~Command() {};
    virtual void Execute() = 0;
};

class NextStateCommand : public Command
{
public:
    void Execute() {};
};

class PreviousStateCommand : public Command
{
public:
    void Execute() {};
};

class MenuUpCommand : public Command
{
public:
    void Execute() {};
};

class MenuDownCommand : public Command
{
public:
    void Execute() {};
};

#endif