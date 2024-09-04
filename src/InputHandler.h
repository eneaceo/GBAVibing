#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <memory>
#include "Command.h"

class StateStack;

class InputHandler
{
public:
    enum BUTTONS
    {
        A,
        B,
        UP,
        DOWN
    };

    InputHandler() {};
    ~InputHandler() = default;

    void BindButton(uint8_t aButton, std::unique_ptr<Command> aNewCommand);
    void HandleInput(StateStack &aStateStack);

private:
    std::unique_ptr<Command> ButtonA;
    std::unique_ptr<Command> ButtonB;
    std::unique_ptr<Command> ButtonUp;
    std::unique_ptr<Command> ButtonDown;
};

#endif